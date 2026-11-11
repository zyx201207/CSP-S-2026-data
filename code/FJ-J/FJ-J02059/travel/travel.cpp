#include<bits/stdc++.h>
using namespace std;
string rx,rz,xx,xz;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>rx>>rz>>xx>>xz;
	if(rx[0]==xx[0] && rx[1]==xx[1]) cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(rz[0]==xz[0] && rz[1]==xz[1]) cout<<1;
	else {
		cout<<0<<0<<0;
		return 0;
	}
	if((rz[2]<='C' && rz[2]>='A' && xz[2]<='C' && xz[2]>='A')||(rz[2]<='F' && rz[2]>='D' && xz[2]<='F' && xz[2]>='D'))
		cout<<1;
	else {
		cout<<0<<0;
		return 0;
	}
	if(abs(rz[2]-xz[2])==1 && !((rz[2]=='D' && xz[2]=='c')||(rz[2]=='C' && xz[2]=='D'))) cout<<1;
	else {
		cout<<0;
		return 0;
	}
	return 0;
}
