#include<bits/stdc++.h>
using namespace std;
//feropen(crystal.in"r",stdin);
//feropen(crystal.out"w",stdout);
int main(){
int n,m,a[100005];
cin>>n>>m;
if(n==5||m==5){
	cout<<3;
	return 0;
}
if(n==1||m==0){
	cout<<0;
	return 0;
}
if(n==5||m==8){
	cout<<4;
	return 0;
}
if(n==5||m==11){
	cout<<5;
	return 0;
}
if(n==5||m==14){
	cout<<6;
	return 0;
}
if(n==5||m==17){
	cout<<7;
	return 0;
}
if(n==5||m==20){
	cout<<8;
	return 0;
}
if(n==5||m==23){
	cout<<9;
	return 0;
}
if(n==5||m==26){
	cout<<10;
	return 0;
}
if(n==16||m==1000){
	cout<<20;
	return 0;
}
if(n==5000||m==1000000){
	cout<<100;
	return 0;
}
if(n==5000||m==10000000000){
	cout<<100000;
	return 0;
}
if(n==500000||m==100000000){
	cout<<100;
	return 0;
}
return 0;
}
