#include<bits/stdc++.h>
using namespace std;
string a[3];
string b[3];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a[1];
	cin>>a[2];
	cin>>b[1];
	cin>>b[2];
	if(a[1]==b[1]) {
		cout<<'1';
	} else {
		cout<<'0';
		cout<<'0';
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if(a[2][0]==b[2][0]&&a[2][1]==b[2][1]) {
		cout<<'1';
	} else {
		cout<<'0';
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if(a[2][2]<='C'&&a[2][2]>='A'&&b[2][2]<='C'&&b[2][2]>='A') {
		cout<<'1';
	} else if(a[2][2]<='F'&&a[2][2]>='D'&&b[2][2]<='F'&&b[2][2]>='D') {
		cout<<'1';
	} else {
		cout<<'0';
		cout<<'0';
		return 0;
	}
	if(a[2][2]+1==b[2][2]) {
		cout<<'1';
	} else if(a[2][2]-1==b[2][2]) {
		cout<<'1';
	} else if(a[2][2]=='D'&&b[2][2]=='C') {
		cout<<'1';
	} else if(b[2][2]=='D'&&a[2][2]=='C') {
		cout<<'1';
	} else {
		cout<<'0';
		return 0;
	}
	return 0;
}
