#include<bits/stdc++.h>
using namespace std;

int main(){
	string s1,s2;
	string seat1,seat2;
	cin>>s1>>seat1>>s2>>seat2;
	if(s1==s2){
		
	}
	else {
		cout<<"0000";
		return 0;
	}
	if((seat1[0]+seat1[1])==(seat2[0]+seat2[1])){
		
	}
	else {
		cout<<1000;
		return 0;
	}
	char s3=seat1[2];
	char s4=seat2[2];
	if((s3=='A' || s3=='B' ||s3=='C') && (s4=='A' || s4=='B' ||s4=='C')){
		
	}
	else if((s3=='D'||s3=='F')&&(s4=='D'||s4=='F')){
		cout<<1111;
		return 0;
	}
	else {
		cout<<1100;
		return 0;
	}
	if(s3+1==s4 || s4+1==s3){
		cout<<1111;
	}
	else {
		cout<<1110;
	}
	return 0;
} 
