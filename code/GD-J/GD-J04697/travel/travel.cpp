#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a,b,c,d;
	a=b=c=d=0;
	int car1,car2;
	string seat1,seat2;
	cin>>car1>>seat1;
	cin>>car2>>seat2;
	if(car1==car2){
		a=1;
	}else{
		cout<<a<<b<<c<<d;
		return 0;
	}
	int sit1=(seat1[0]-'0')*10+(seat1[1]-'0');
	int sit2=(seat2[0]-'0')*10+(seat2[1]-'0');
	if(sit1==sit2){
		b=1;
	}else{
		cout<<a<<b<<c<<d;
		return 0;
	}
	char side1=seat1[2],side2=seat2[2];
	if(side1=='A'||side1=='B'||side1=='C'){
		if(side2=='A'||side2=='B'||side2=='C'){
			c=1;
		}else{
			cout<<a<<b<<c<<d;
			return 0;
		}
	}else if(side1=='D'||side1=='F'){
		if(side2=='D'||side2=='F'){
			c=1;
		}else{
			cout<<a<<b<<c<<d;
		}
	}else{
		cout<<a<<b<<c<<d;
		return 0;
	}
	if(side1=='A'&&side2=='B'){
		d=1;
	}else if(side1=='B'&&(side2=='A'||side2=='C')){
		d=1;
	}else if(side1=='C'&&side2=='B'){
		d=1;
	}else if((side1=='D'||side1=='F')&&(side2=='D'||side2=='F')){
		d=1;
	}
	cout<<a<<b<<c<<d;
	return 0;
} 
