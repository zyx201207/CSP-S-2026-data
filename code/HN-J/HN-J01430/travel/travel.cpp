#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string rx,xx,rz,xz;
	cin>>rx>>rz>>xx>>xz;
	int sb=0;
	if(rx==xx) cout<<"1";
	else {
		cout<<"0";
		sb=1;
	}
	int flag=0;
	for(int i=0;i<=1;i++){
		if(rz[i]!=xz[i]){
			flag=1;
			break;
		}
	}
	if(flag==1||sb==1) cout<<"0";
	else cout<<"1";
	if((rz[2]=='A'||rz[2]=='B'||rz[2]=='C')&&(xz[2]=='A'||xz[2]=='B'||xz[2]=='C')&&flag==0&&sb==0)cout<<"1";
	else if((rz[2]=='D'||rz[2]=='F')&&(xz[2]=='D'||xz[2]=='F')&&flag==0&&sb==0)cout<<"1";
	else cout<<"0";
	if((rz[2]=='A'&&xz[2]=='B'||rz[2]=='B'&&xz[2]=='A')&&flag==0)cout<<"1"; 
	else if((rz[2]=='B'&&xz[2]=='C'||rz[2]=='C'&&xz[2]=='B')&&flag==0) cout<<"1";
	else if((rz[2]=='D'&&xz[2]=='F'||rz[2]=='F'&&xz[2]=='D')&&flag==0) cout<<"1";
	else cout<<"0";
	return 0;
} 
