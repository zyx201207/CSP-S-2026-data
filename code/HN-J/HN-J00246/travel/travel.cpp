#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2,t;
int ans,l,r;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) {
		cout<<"1";
		for(int i=0; i<2; i++) {
			if(s1[i]==s2[i]) {
				ans++;
			}
		}
		if(ans==2) {
			cout<<"1";
			if(s1[2]=='A'||s1[2]=='B'||s1[2]=='C') {
				l++;
			}
			if(s2[2]=='A'||s2[2]=='B'||s2[2]=='C') {
				l++;
			}
			if(s1[2]=='D'||s1[2]=='F') {
				r++;
			}
			if(s2[2]=='D'||s2[2]=='F') {
				r++;
			}
			if(l==r) {
				cout<<"0";
			} else {
				cout<<"1";
			}
			if(s1[2]=='C'&&s2[2]=='D'||s2[2]=='C'&&s1[2]=='D') {
				cout<<"0";
			} else {
				if(s1[2]==s2[2]+1||s2[2]==s1[2]+1) {
					cout<<"1";
				} else {
					cout<<"0";
				}
			}
		} else {
			cout<<"000";
		}
	} else {
		cout<<"0000";
	}
	return 0;
}
