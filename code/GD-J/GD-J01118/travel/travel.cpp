#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    if(c1==c2){
    	cout<<1;
	}else{
		cout<<"0000";
		return 0; 
	}
	int num1=0,num2=0;
	num1=(s1[0]-'0')*10+(s1[1]-'0');
	num2=(s2[0]-'0')*10+(s2[1]-'0');
	if(num1==num2){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	int f1=0,f2=0;
	if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'){
		f1=1;
	}
	if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C'){
		f2=1;
	}
	if(f1==f2){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	char az,ay;
	if(s1[2]=='A'){
		az='0';
		ay='B';
	}else if(s1[2]=='B'){
		az='A';
		ay='C';
	}else if(s1[2]=='C'){
		az='B';
		ay='0';
	}else if(s1[2]=='D'){
		az='0';
		ay='F';
	}else if(s1[2]=='F'){
		az='D';
		ay='0';
	}
	if(s2[2]==az||s2[2]==ay){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
} 

