#include<bits/stdc++.h>
using namespace std;
string s1,s2,s3,s4;
int rc,xc,rp,xp;
int rz,xz;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s3>>s4;
	rc=(s1[1]-'0')+(s1[0]-'0')*10;
	rp=(s2[1]-'0')+(s2[0]-'0')*10;
	rz=s2[2];
	xc=(s3[1]-'0')+(s3[0]-'0')*10;
	xp=(s4[1]-'0')+(s4[0]-'0')*10;
	xz=s4[2];
	if(rc==xc)cout<<1;
	else{
		cout<<0<<0<<0<<0;
		return 0;	
	}
	if(rp==xp)cout<<1;
	else{
		cout<<0<<0<<0;
		return 0;	
	}
	if((rz=='A'||rz=='B'||rz=='C')&&(xz=='A'||xz=='B'||xz=='C')||(rz=='D'||rz=='F')&&(xz=='D'||xz=='F'))cout<<1;
	else{
		cout<<0<<0;
		return 0;	
	}
	if(rz=='A'&&xz=='B'||rz=='B'&&xz=='A'||rz=='B'&&xz=='C'||rz=='C'&&xz=='B'||rz=='D'&&xz=='E'||rz=='E'&&xz=='D')cout<<1;
	else cout<<0;
	return 0;
}

