#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int rc,xc;
	string rz,xz;
	cin>>rc>>rz>>xc>>xz;
	if(rc!=xc){
		cout<<"0000";
		return 0;
	}
	if(rz[0]!=xz[0]||rz[1]!=xz[1]){
		cout<<"1000";
		return 0;
	}
	if(rz[2]>='A'&&rz[2]<='C'&&xz[2]>='D'&&xz[2]<='F'||xz[2]>='A'&&xz[2]<='C'&&rz[2]>='D'&&rz[2]<='F'){
		cout<<"1100";
		return 0;
	}
	if(rz[2]>='A'&&rz[2]<='C'&&xz[2]>='A'&&xz[2]<='C'){
		if(rz[2]=='A'&&xz[2]=='B'||rz[2]=='B'&&xz[2]=='A'||rz[2]=='C'&&xz[2]=='B'||rz[2]=='B'&&xz[2]=='C'){
			cout<<"1111";
			return 0;
		}
		cout<<"1110";
		return 0;
	}
	if(xz[2]>='D'&&xz[2]<='F'&&rz[2]>='D'&&rz[2]<='F'){
		cout<<"1111";
	}
	return 0;
} 
