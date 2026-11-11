#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string r1,r2,s1,s2;
	int pd=1;
	cin>>r1>>r2>>s1>>s2;
	if(r1==s1){
	cout<<1;}
	else{
		pd=0;
	cout<<0;}
	if((r2[1]==s2[1]&&r2[0]==s2[0])&&pd==1){
		cout<<1; 
	}
	else{
	pd=0;
	cout<<0;}
	if((((r2[2]=='D'||r2[2]=='F')&&(s2[2]=='D'||s2[2]=='F'))||(!(r2[2]=='D'||r2[2]=='F')&&!(s2[2]=='D'||s2[2]=='F')))&&pd==1){
		cout<<1;
	}
	else{
	pd=0;
   	cout<<0;}
   	if((r2[2]=='D'||s2[2]=='D'||r2[2]=='B'||s2[2]=='B')&&pd==1){
   	cout<<1;}
   	else{
	   cout<<0;}
	return 0;
}
