//L.E.A.Samadhi Dewmini
//April 21th 20222
//Discription:Firm Alarm

/*define MQ2pin (0)
www.arduinopoint.com 
Fire Alarm System 
*/

int incomingByte = 0;
//float sensorValue;  //variable to store sensor value
int redLed1 = 3;
int redLed2 = 8;
int buzzer1 = 5; //PWM (~) pin
int buzzer2 = 6; //PWM (~) pin
int data = 0; //This will store the data from the sensor.
int lightPin = A1;
const int gas = 0;
int MQ2pin = A0;

void setup() { //The Setup function runs once.
Serial.begin(9600); // sets the serial port to 9600
pinMode(redLed1, OUTPUT); 
pinMode(redLed2, OUTPUT);  
pinMode(buzzer1, OUTPUT);
pinMode(buzzer2, OUTPUT);

}

void loop() {
data = analogRead(lightPin); //Read the value from the light sensor and store it in the lightData variable.
data = map(data,6,679,0,100); //map the data value to a percentage
Serial.print("Light value =");
Serial.println(data); //Print the data to the serial port.
delay(1000); //Wait 1 second (1000mS) before running again.


  if (data>=80){ // HIGH MEANS NO FLAME
    tone(buzzer2, 5000); //the buzzer sound frequency at 5000 Hz
     digitalWrite(redLed1, HIGH);
     digitalWrite(redLed2,LOW);
    noTone(buzzer1);
    }
  
   float sensorValue,MQ2pin;
   sensorValue = analogRead(MQ2pin); // read analog input pin 0

  if(sensorValue >= 470){
    Serial.print(sensorValue);
    Serial.println(" |SMOKE DETECTED");
    digitalWrite(redLed2, HIGH);
    tone(buzzer1, 5000); //the buzzer sound frequency at 5000 Hz
    digitalWrite(redLed1, LOW);
    noTone(buzzer2);
    
  
  }
  else{
  	digitalWrite(redLed2,LOW);
    noTone(buzzer2);
    Serial.println("Sensor Value: ");
    Serial.println(sensorValue);
  } 
  delay(1000);
}
	float getsensorValue(int pin){
  	return (analogRead(pin));
  
}





