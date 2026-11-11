#include <bits/stdc++.h>
using namespace std;
string rc,rz,xc,xz,s="0000";
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel,out","w",stdout);
	cin>>rc>>rz>>xc>>xz;
	if(rc!=xc){
		cout<<s;
		return 0;
	}
	else s[1]='1';
	if(rz[1]==xz[1]){
		s[2]='1';
		if(rz[2]==xz[2]) s[3]='0';
		else if((rz[2]=='A' || rz[2]=='B' || rz[2]=='C') || (xz[2]=='A' || xz[2]=='B' || xz[2]=='C')) s[3]='1';
	}
	int ra=(int)rz[2],xa=(int)xz[2];
	if(max(ra,xa)-min(ra,xa)==1) s[4]='1';
	else s[4]='0';
	cout<<s;
	return 0;
}
