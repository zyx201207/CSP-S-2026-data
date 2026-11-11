#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
    int bj=0;
	if(c1!=c2){
		cout<<0;
		bj=1;
	}
	else {
		cout<<1;
	}
	int w=s1[0]-'0';
	int ww=s1[1]-'0';
	int www=s2[0]-'0';
	int wwww=s2[1]-'0';
	int h1=w*10+ww;
	int h2=www*10+wwww;
	char wz=s1[2],wz2=s2[2];
	if(h1!=h2||bj==1){
		cout<<0;
		bj=1;
	}
	else {
		cout<<1;
	}
	if((((wz>='A'&&wz<='C')&&(wz2>='A'&&wz2<='C'))||((wz>='D'&&wz<='E')&&(wz2>='D'&&wz2<='E')))&&bj==0){
		cout<<1;
	}
	else {
		bj=1;
		cout<<0;
	}
	if(wz>wz2){
		swap(wz,wz2);
	}
	if(((wz=='A'&&wz2=='B')||(wz=='B'&&wz2=='C')||(wz=='D'&&wz2=='E'))&&bj==0){
		cout<<1;
		
	}
	else {
		cout<<0;
	}
	
	return 0;
} 
