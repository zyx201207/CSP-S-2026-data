#include <bits/stdc++.h>
#include<iostream>
using namespace std;
char a1,a2,a3,a4,b1,b2,b3,b4,a5,b5;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>a3>>a4>>a5;
	cin>>b1>>b2>>b3>>b4>>b5;
	if(a1==b1&&a2==b2){
		cout<<"1";
	}else {
		cout<<"0000";
		return 0;
	}
	if(a3==b3&&a4==b4){
		cout<<"1";
	}else {
		cout<<"000";
		return 0;
	}
	if((a5=='F'&&b5=='D')||(a5=='D'&&b5=='F')||((a5!='D'&&b5!='F')&&(a5!='F'&&b5!='D'))){
		cout<<"1"; 
	}else {
		cout<<"00";
		return 0;
	}
	if((a5=='F'&&b5=='D')||(a5=='F'&&b5=='D')){
		cout<<"1";
	}else if((a5=='A'&&b5=='B')||(a5=='B'&&b5=='A')||(a5=='B'&&b5=='C')||(a5=='C'&&b5=='B')){
		cout<<"1";}else {
	cout<<"0";
	}
return 0;
}

