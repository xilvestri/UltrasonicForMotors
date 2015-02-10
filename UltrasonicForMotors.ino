
/* Ultrasonic Ranging with HC-SR04 and LCD
by Glenn Mossy, gmossy@gmail.com, Starter Kit, 2014
*/

 
const int triggerPin1 = 6;      //Trig pin
const int echoPin1    = 7;         //Echo pin
const int triggerPin2 = 3;      //Trig pin
const int echoPin2    = 4; 
const int LEDleft = 11;      //indication lights
const int LEDright    = 12; 

void setup() {

Serial.begin(9600);
}
 
void loop()
{
   
  // establish variables for duration of the ping,
  // and the distance result in inches and centimeters:
  long duration1, inches1, cm1, duration2, inches2, cm2;
 
  // The PING))) is triggered by a HIGH pulse of 2 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(triggerPin1, OUTPUT);
  digitalWrite(triggerPin1, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin1, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin1, LOW);
  pinMode(echoPin1, INPUT);
  duration1 = pulseIn(echoPin1, HIGH);
  
  pinMode(triggerPin2, OUTPUT);
  digitalWrite(triggerPin2, LOW);
  delayMicroseconds(2);
  digitalWrite(triggerPin2, HIGH);
  delayMicroseconds(10);
  digitalWrite(triggerPin2, LOW);
  pinMode(echoPin2, INPUT);
  duration2 = pulseIn(echoPin2, HIGH);
 
  // The same pin is used to read the signal from the PING))): a HIGH
  // pulse whose duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.

 
  // convert the time into a distance
  inches1 = microsecondsToInches(duration1);
  cm1 = microsecondsToCentimeters(duration1);
  
  inches2 = microsecondsToInches(duration2);
  cm2 = microsecondsToCentimeters(duration2);

  //Serial.print("Left Distance measured in inches= ");
  //Serial.println(inches1);
  //Serial.print("Right Distance measured in inches= ");
  //Serial.println(inches2);
  
  if(duration1 >duration2){
    digitalWrite(LEDleft, HIGH);
    digitalWrite(LEDright, LOW);
    Serial.println("E");
  }
    
  if(duration2 > duration1){
    digitalWrite(LEDright, HIGH);
    digitalWrite(LEDleft, LOW);
    Serial.println("1");
  }

 
  delay(400);
}
 
long microsecondsToInches(long microseconds)
{
  // There are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}
