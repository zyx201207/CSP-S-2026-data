#include <bits/stdc++.h>
using namespace std;
string num1,seat1,num2,seat2;
string k3,k4;
string a,a1;
int b,b1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>num1>>seat1>>num2>>seat2;
	if(num1==num2){
		cout<<"1";
	}else{
		cout<<"0000";
		return 0;
	}
	k3=seat1.substr(0,2);
	k4=seat2.substr(0,2);
	if(k3==k4){
		cout<<"1";
	}else{
		cout<<"000";
		return 0;
	}
	a=seat1[2];
	a1=seat2[2];
	if((a=="A"||a=="B"||a=="C")&&(a1=="A"||a1=="B"||a1=="C")){
		cout<<"1";
	}else if((a=="E"||a=="F")&&(a1=="E"||a1=="F")){
		cout<<"1";
	}else{
		cout<<"00";
		return 0;
	}
	if((a=="A"||a=="B")&&(a1=="A"||a1=="B")){
		cout<<1;
	}else if((a=="B"||a=="C")&&(a1=="B"||a1=="C")){
		cout<<1;
	}else if((a=="E"||a=="F")&&(a1=="E"||a1=="F")){
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
}
