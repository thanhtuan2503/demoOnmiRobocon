/*
 Example sketch for the PS4 Bluetooth library - developed by Kristian Lauszus
 For more information visit my blog: http://blog.tkjelectronics.dk/ or
 send me an e-mail:  kristianl@tkjelectronics.com
 */
#include <SoftwareSerial.h>
SoftwareSerial mySerial(12, 13); //Define PIN12 & PIN13 as software UART
#include <PS4BT.h>
#include <usbhub.h>

// Satisfy the IDE, which needs to see the include statment in the ino too.
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif
#include <SPI.h>
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 4000;           // interval at which to blink (milliseconds)

USB Usb;
//USBHub Hub1(&Usb); // Some dongles have a hub inside
BTD Btd(&Usb); // You have to create the Bluetooth Dongle instance like so

/* You can create the instance of the PS4BT class in two ways */
// This will start an inquiry and then pair with the PS4 controller - you only have to do this once
// You will need to hold down the PS and Share button at the same time, the PS4 controller will then start to blink rapidly indicating that it is in pairing mode
PS4BT PS4(&Btd, PAIR);

// After that you can simply create the instance like so and then press the PS button on the device
//PS4BT PS4(&Btd);

bool printAngle, printTouch;
uint8_t oldL2Value, oldR2Value;
int tuan;
int R2Stt = 0; 
int L2Stt = 0;
int UpStt = 0;
int DownStt = 0;
int LeftStt = 0;
int RightStt = 0;
int TriStt = 0;
int CirStt = 0;
int CrStt = 0;
int SqrStt = 0;
void setup() {
  mySerial.println("{N1  V0 A20000}");
  delay(2);
  mySerial.println("{N2  V0 A20000}");
  delay(2);
  mySerial.println("{N3  V0 A20000}");
  delay(2);
  mySerial.println("{N4  V0 A20000}");
  delay(2);
  Serial.begin(115200);
  mySerial.begin(19200);   // set the data rate for the SoftwareSerial port
  pinMode(10, OUTPUT);          // sets the digital pin 13 as output
#if !defined(__MIPSEL__)
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
#endif
  if (Usb.Init() == -1) {
    Serial.print(F("\r\nOSC did not start"));
    while (1); // Halt
  }
  Serial.print(F("\r\nPS4 Bluetooth Library Started"));
   mySerial.println("{N1 V0 A2000 }");  //send to driver Add =2 (N2), Vị trí P=500 rad, Vận tốc V=40 rad/s và gia tốc A =2000 rad/s^2.  
}

//Handling Button Up******************************

void ButtonUp(){
        if (PS4.getButtonPress(UP)) {
        while ( UpStt != 1){
          Serial.println(F("\r\nUP"));
          mySerial.println("{N1  V-50 A2000}");
          delay(2);
          mySerial.println("{N2  V50 A2000}");
          delay(2);
          mySerial.println("{N3  V-50 A2000}");
          delay(2);
          mySerial.println("{N4  V50 A2000}");   
          UpStt = 1;
        }
      }
      else {
        while( UpStt != 0){
          mySerial.println("{N1  V0 A20000}");
          delay(2);
          mySerial.println("{N2  V0 A20000}");
          delay(2);
          mySerial.println("{N3  V0 A20000}");
          delay(2);
          mySerial.println("{N4  V0 A20000}");
          UpStt = 0;
        }
      }
}

//Handling Button Down******************************

void ButtonDown(){
        if (PS4.getButtonPress(DOWN)) {
        while ( DownStt != 1){
          Serial.print(F("\r\nDown"));
          mySerial.println("{N1  V50 A2000}");
          delay(2);
          mySerial.println("{N2  V-50 A2000}");
          delay(2);
          mySerial.println("{N3  V50 A2000}");
          delay(2);
          mySerial.println("{N4  V-50 A2000}"); 
          DownStt = 1;
        } 
      }
       else{
        while ( DownStt != 0){
          mySerial.println("{N1  V0 A2000}");
          delay(2);
          mySerial.println("{N2  V0 A2000}");
          delay(2);
          mySerial.println("{N3  V0 A2000}");
          delay(2);
          mySerial.println("{N4  V0 A2000}");
          DownStt = 0;
        }
      }
}

//Handling Button Right******************************

void ButtonRight(){
        if (PS4.getButtonPress(RIGHT)) {
        while ( RightStt != 1){
          Serial.print(F("\r\nRight"));
          mySerial.println("{N1  V-50 A2000}");
          delay(2);
          mySerial.println("{N2  V-50 A2000}");
          delay(2);
          mySerial.println("{N3  V50 A2000}");
          delay(2);
          mySerial.println("{N4  V50 A2000}");     
          RightStt = 1;
        }   
      }

      else {
        while( RightStt != 0){
          mySerial.println("{N1  V0 A20000}");
          delay(2);
          mySerial.println("{N2  V0 A20000}");
          delay(2);
          mySerial.println("{N3  V0 A20000}");
          delay(2);
          mySerial.println("{N4  V0 A20000}");
          RightStt = 0;
        }
      }
}

//Handling Button Left******************************

void ButtonLeft(){
        if (PS4.getButtonPress(LEFT)) {
        while ( LeftStt != 1){
          Serial.print(F("\r\nLeft"));
          mySerial.println("{N1  V50 A2000}");
          delay(2);
          mySerial.println("{N2  V50 A2000}");
          delay(2);
          mySerial.println("{N3  V-50 A2000}");
          delay(2);
          mySerial.println("{N4  V-50 A2000}"); 
          LeftStt = 1;
        }
      }
      else {
        while( LeftStt != 0){
          mySerial.println("{N1  V0 A20000}");
          delay(2);
          mySerial.println("{N2  V0 A20000}");
          delay(2);
          mySerial.println("{N3  V0 A20000}");
          delay(2);
          mySerial.println("{N4  V0 A20000}");
          LeftStt = 0;
        }
      }
}

//Handling Button Triangle******************************

void TriangleButton(){
        if (PS4.getButtonPress(TRIANGLE)) {
        while ( TriStt != 1){
          Serial.println(F("\r\nTRIANGLE"));       
          mySerial.println("{N1  V0 A20000}");
          delay(2);
          mySerial.println("{N2  V0 A20000}");
          delay(2);
          mySerial.println("{N3  V200 A20000}");
          delay(2);
          mySerial.println("{N4  V0 A20000}");
          TriStt = 1;
        }
      }
      else {
        while( TriStt != 0){
          mySerial.println("{N1  V0 A20000}");
          delay(2);
          mySerial.println("{N2  V0 A20000}");
          delay(2);
          mySerial.println("{N3  V0 A20000}");
          delay(2);
          mySerial.println("{N4  V0 A20000}");
          TriStt = 0;
        }
      }
}

//Handling Button Circle******************************

void CircleButton(){
        if (PS4.getButtonPress(CIRCLE)) {
        while( CirStt != 1){
          Serial.print(F("\r\nCircle"));
          mySerial.println("{N1  V0 A2000}");
          delay(2);
          mySerial.println("{N2  V200 A2000}");
          delay(2);
          mySerial.println("{N3  V0 A2000}");
          delay(2);
          mySerial.println("{N4  V0 A2000}");
          CirStt = 1;
        }
      }
      else{
        while ( CirStt != 0){
          mySerial.println("{N1  V0 A2000}");
          delay(2);
          mySerial.println("{N2  V0 A2000}");
          delay(2);
          mySerial.println("{N3  V0 A2000}");
          delay(2);
          mySerial.println("{N4  V0 A2000}");
          CirStt = 0;
        }
      }   
}

//Handling Button Cross******************************

void CrossButton(){
        if (PS4.getButtonPress(CROSS)) {
        while ( CrStt != 1){
          Serial.print(F("\r\nCross"));
          mySerial.println("{N1  V200 A2000}");
          delay(2);
          mySerial.println("{N2  V0 A2000}");
          delay(2);
          mySerial.println("{N3  V0 A2000}");
          delay(2);
          mySerial.println("{N4  V0 A2000}");
          CrStt = 1;
        }
      }
      else {
        while ( CrStt != 0){
          mySerial.println("{N1  V0 A2000}");
          delay(2);
          mySerial.println("{N2  V0 A2000}");
          delay(2);
          mySerial.println("{N3  V0 A2000}");
          delay(2);
          mySerial.println("{N4  V0 A2000}");
          CrStt = 0;
        }
      }  
}

//Handling Button Square******************************

void SquareButton(){
  
      if (PS4.getButtonPress(SQUARE)) {
        while ( SqrStt != 1){
          Serial.print(F("\r\nSquare"));
          mySerial.println("{N1  V0 A2000}");
          delay(2);
          mySerial.println("{N2  V0 A2000}");
          delay(2);
          mySerial.println("{N3  V0 A2000}");
          delay(2);
          mySerial.println("{N4  V200 A2000}");
          SqrStt = 1;   
        }
      }
      else{
        while ( SqrStt != 0){
          mySerial.println("{N1  V0 A2000}");
          delay(2);
          mySerial.println("{N2  V0 A2000}");
          delay(2);
          mySerial.println("{N3  V0 A2000}");
          delay(2);
          mySerial.println("{N4  V0 A2000}"); 
          SqrStt = 0;
        }   
      }
}
//Handling Button L2******************************

void L2Button(){
       if (PS4.getButtonPress(L2)) {
        while ( L2Stt != 1){      
          mySerial.println("{N1  V50 A2000}");
          delay(2);
          mySerial.println("{N2  V50 A2000}");
          delay(2);
          mySerial.println("{N3  V50 A2000}");
          delay(2);
          mySerial.println("{N4  V50 A2000}");   
          L2Stt = 1;
        }
      }
      else {
        while( L2Stt != 0){
          mySerial.println("{N1  V0 A20000}");
          delay(2);
          mySerial.println("{N2  V0 A20000}");
          delay(2);
          mySerial.println("{N3  V0 A20000}");
          delay(2);
          mySerial.println("{N4  V0 A20000}");
          L2Stt = 0;
        }
      }
}

//Handling Button R2******************************

void R2Button(){
        if (PS4.getButtonPress(R2)) {
        while ( R2Stt != 1){      
          mySerial.println("{N1  V-50 A2000}");
          delay(2);
          mySerial.println("{N2  V-50 A2000}");
          delay(2);
          mySerial.println("{N3  V-50 A2000}");
          delay(2);
          mySerial.println("{N4  V-50 A2000}");   
          R2Stt = 1;
        }
      }
      else {
        while( R2Stt != 0){
          mySerial.println("{N1  V0 A20000}");
          delay(2);
          mySerial.println("{N2  V0 A20000}");
          delay(2);
          mySerial.println("{N3  V0 A20000}");
          delay(2);
          mySerial.println("{N4  V0 A20000}");
          R2Stt = 0;
        }
      }
}
void loop() {
  
  Usb.Task();
  unsigned long currentMillis = millis();
  if (mySerial.available()) {
    Serial.write(mySerial.read());
   // Serial.write("hello");
  }
  if (PS4.connected()) {
    if (PS4.getAnalogHat(LeftHatX) > 137 || PS4.getAnalogHat(LeftHatX) < 117 || PS4.getAnalogHat(LeftHatY) > 137 || PS4.getAnalogHat(LeftHatY) < 117 || PS4.getAnalogHat(RightHatX) > 137 || PS4.getAnalogHat(RightHatX) < 117 || PS4.getAnalogHat(RightHatY) > 137 || PS4.getAnalogHat(RightHatY) < 117) {
      Serial.print(F("\r\nLeftHatX: "));
      Serial.print(PS4.getAnalogHat(LeftHatX));
      Serial.print(F("\tLeftHatY: "));
      Serial.print(PS4.getAnalogHat(LeftHatY));
      Serial.print(F("\tRightHatX: "));
      Serial.print(PS4.getAnalogHat(RightHatX));
      Serial.print(F("\tRightHatY: "));
      Serial.print(PS4.getAnalogHat(RightHatY));
    }

    if (PS4.getAnalogButton(L2) || PS4.getAnalogButton(R2)) { // These are the only analog buttons on the PS4 controller
      Serial.print(F("\r\nL2: "));
      Serial.print(PS4.getAnalogButton(L2));
      Serial.print(F("\tR2: "));
      Serial.print(PS4.getAnalogButton(R2));
    }
    //Handling Analog Button*****************************************************
    L2Button();
    R2Button();
    //***************************************************************************

    if (PS4.getButtonClick(PS)) {
      Serial.print(F("\r\nPS"));
      PS4.disconnect();
    }
    else {

    // Directional Button******************************
    
    ButtonUp();
    ButtonDown();
    ButtonRight();
    ButtonLeft();

    //Cubes Button******************************
    TriangleButton();
    CircleButton();
    CrossButton();
    SquareButton();
//***********************************************************************


      if (PS4.getButtonClick(L1)){
        Serial.print(F("\r\nL1"));
        mySerial.println("{N1  V0 A2000}");
        delay(2);
        mySerial.println("{N2  V0 A2000}");
        delay(2);
        mySerial.println("{N3  V0 A2000}");
        delay(2);
        mySerial.println("{N4  V0 A2000}");
      }
      if (PS4.getButtonClick(L3))
        Serial.print(F("\r\nL3"));
      if (PS4.getButtonClick(R1)){
        Serial.print(F("\r\nR1"));
        mySerial.println("{N1  V0 A2000}");
        delay(2);
        mySerial.println("{N2  V0 A2000}");
        delay(2);
        mySerial.println("{N3  V0 A2000}");
        delay(2);
        mySerial.println("{N4  V0 A2000}");
      }
      if (PS4.getButtonClick(R3))
        Serial.print(F("\r\nR3"));

      if (PS4.getButtonClick(SHARE))
        Serial.print(F("\r\nShare"));
      if (PS4.getButtonClick(OPTIONS)) {
        Serial.print(F("\r\nOptions"));
        printAngle = !printAngle;
      }
      if (PS4.getButtonClick(TOUCHPAD)) {
        Serial.print(F("\r\nTouchpad"));
        printTouch = !printTouch;
      }

      if (printAngle) { // Print angle calculated using the accelerometer only
        Serial.print(F("\r\nPitch: "));
        Serial.print(PS4.getAngle(Pitch));
        Serial.print(F("\tRoll: "));
        Serial.print(PS4.getAngle(Roll));
      }

      if (printTouch) { // Print the x, y coordinates of the touchpad
        if (PS4.isTouching(0) || PS4.isTouching(1)) // Print newline and carriage return if any of the fingers are touching the touchpad
          Serial.print(F("\r\n"));
        for (uint8_t i = 0; i < 2; i++) { // The touchpad track two fingers
          if (PS4.isTouching(i)) { // Print the position of the finger if it is touching the touchpad
            Serial.print(F("X")); Serial.print(i + 1); Serial.print(F(": "));
            Serial.print(PS4.getX(i));
            Serial.print(F("\tY")); Serial.print(i + 1); Serial.print(F(": "));
            Serial.print(PS4.getY(i));
            Serial.print(F("\t"));
          }
        }
      }
    }
   }
//    Serial.println("no bug");
}
