#include<bits/stdc++.h>
using namespace std;
int digit(string s){
	return (s[0]-'0')*10+(s[1]-'0');
}
int main(){
	//freopen("travel.in","r",stdin);
	//freopen("travel.out","w",stdout);
	int ch1,ch2,a,b;
	string p1,p2;
	cin>>ch1>>p1>>ch2>>p2;
	if(ch1!=ch2){
		cout<<"0000";
		return 0;
	}
	cout<<"1";
	if(digit(p1)!=digit(p2)){
		cout<<"000";
		return 0;
	}
	cout<<"1";
	a=p1[2]-'A'+1;
	b=p2[2]-'A'+1;
	if(a>3&&b>3){
		cout<<"11";
		return 0;
	}
	if(a<=3&&b<=3){
		cout<<"1";
	}
	else{
		cout<<"00";
		return 0;
	}
	if(abs(a-b)==1)cout<<"1";
	else cout<<"0";
	return 0;
} 
