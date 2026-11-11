#include<bits/stdc++.h>
using namespace std;
string c,s,n,m;
int main () {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>n>>m;
	if (c==n) {
		cout<<"1";
	}
	else {
		cout<<"0000";
		return 0;
	}
	if (s[0]==m[0] and s[1]==m[1]) {
		cout<<"1";
	}
	else {
		cout<<"000";
		return 0;
	}
	if (s[2]=='A' or s[2]=='B' or s[2]=='C') {
		if (m[2]=='A' or m[2]=='B' or m[2]=='C') {
			cout<<"1";
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	else {
		if (m[2]=='D' or m[2]=='F') {
			cout<<"1";
		}
		else {
			cout<<"00";
			return 0;
		}
	}
	if (s[2]=='F' or s[2]=='D') {
		cout<<"1";
	}
	else if ((s[2]=='A' and m[2]=='B') or (s[2]=='B' and m[2]=='A') or (s[2]=='B' and m[2]=='C') or (s[2]=='C' and m[2]=='B')){
		cout<<"1";
	}
	else {
		cout<<"0";
	}
	
	
	
	
	
	return 0;
}
 
