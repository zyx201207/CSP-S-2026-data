#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	char ra1,ra2,xa1,xa2;
	char rb1,rb2,r,xb1,xb2,x;
	cin>>ra1>>ra2>>rb1>>rb2>>r;
	cin>>xa1>>xa2>>xb1>>xb2>>x;
	if(ra1!=xa1||ra2!=xa2){
		cout<<"0000";
		return 0;
	}
	if(rb1!=xb1||rb2!=xb2){
		cout<<1000;
		return 0;
	}
	if(((r=='A'&&x!='B')&&x!='C')||((r=='B'&&x!='A')&&x!='C')||((r=='C'&&x!='A')&&x!='B')||(r=='D'&&x!='F')||(r=='F'&&x!='D')){
		cout<<1100;
		return 0;
	}
	if((r=='A'&&x=='B')||(r=='B'&&x=='A')||(r=='B'&&x=='C')||(r=='C'&&x=='B')||(r=='D'&&x=='F')||(r=='F'&&x=='D')){
		cout<<1111;
		return 0;
	}
	cout<<1110;
	return 0;
}
