#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	bool a=0,b=0,c=0;
	string R1,R2,X1,X2;
	cin>>R1>>R2>>X1>>X2;
	if(R1[0]==X1[0]&&R1[1]==X1[1]){
		cout<<1;
		a=1;
	}
	else{
		cout<<0;
	}
	if(R2[0]==X2[0]&&R2[1]==X2[1]&&a){
		cout<<1;
		b=1;
	}
	else{
		cout<<0;
	}
	if(a&&b&&((R2[2]=='A'||R2[2]=='B'||R2[2]=='C')&&(X2[2]!='F'&&X2[2]!='D')||(R2[2]=='D'||R2[2]=='F')&&(X2[2]=='D'&&X2[2]=='F'))&&(R2[0]==X2[0]&&R2[1]==X2[1])){
		cout<<1;
		c=1;
	}
	else{
		cout<<0;
	}
	if(a&&b&&c&&((R2[2]=='D'||R2[2]=='F')&&(X2[2]=='D'||X2[2]=='F')||(R2[2]=='A'||R2[2]=='B')&&(X2[2]=='A'||X2[2]=='B')||(R2[2]=='B'||R2[2]=='C')&&(X2[2]=='B'||X2[2]=='C'))){
		cout<<1;
	}
	else{
		cout<<0;
	}
	return 0;
}
