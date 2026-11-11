//GZ-J00152  遵义市第四中学 曾皓宇
#include <bits/stdc++.h>
using namespace std;
string s1,s2,a1,a2;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>a1>>a2;
	if(s1==a1) {
		if(s2[0]==a2[0]&&s2[1]==a2[1]) {
			if((s2[2]=='A'||s2[2]=='B'||s2[2]=='C')&&(a2[2]=='A'||a2[2]=='B'||a2[2]=='C')) {
				if(s2[2]=='A') {
					if(a2[2]=='B') {
						cout<<"1111";
					} else cout<<"1110";
				} else if(s2[2]=='B') {
					if(a2[2]=='A'||a2[2]=='C') {
						cout<<"1111";
					} else cout<<"1110";
				} else {
					if(a2[2]=='B') {
						cout<<"1111";
					} else cout<<"1110";
				}
			} else if((s2[2]=='D'||s2[2]=='F')&&(a2[2]=='D'||a2[2]=='F')) {
				if(s2[2]=='D') {
					if(a2[2]=='F') {
						cout<<"1111";
					} else 	cout<<"1110";
				} else if(s2[2]=='F') {
					if(a2[2]=='D') {
						cout<<"1111";
					} else 	cout<<"1110";
				}
			} else cout<<"1100";
		} else cout<<"1000";
	} else cout<<"0000";
	return 0;
}
