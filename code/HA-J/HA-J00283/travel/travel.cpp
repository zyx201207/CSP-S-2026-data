
#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
bool l=false;
bool p=false;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	//1
	if(c1==c2) {
		cout<<1;
		//2
		if(s1[1]==s2[1]) {
			cout<<1;
		} else {
			cout<<0;
		}
		//3
		if(s1[1]==s2[1]) {
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C'&&s1[2]!=s2[2]) {
				if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') {
					cout<<1;
				} else {
					cout<<0;
				}
			}
			if(s1[2]=='D'||s1[2]=='F'&&s1[2]!=s2[2]) {
				if(s2[2]=='D'||s2[2]=='F') {
					cout<<1;
				} else {
					cout<<0;
				}
			}
		} else {
			cout<<0;
		}
		//4
		if(s1[1]!=s2[1]) {
			cout<<0;
		} else {
			if(s1[2]=='A'&&s2[2]=='B'||s1[2]=='B'&&s2[2]=='A') {
				cout<<1;
			} else if(s1[2]=='B'&&s2[2]=='C'||s2[2]=='C'&&s1[2]=='B') {
				cout<<1;
			} else if(s1[2]=='D'&&s2[2]=='F') {
				cout<<1;
			} else if(s2[2]=='F'&&s1[2]=='D') {
				cout<<1;
			} else {
				cout<<0;
			}
		}

	} else
		cout<<"0000";

	return 0;
}
