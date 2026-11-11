#include<bits/stdc++.h>
using namespace std;
string c[5],s[5];
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]==c[2]) {
		cout<<1;
		if(s[1][0]==s[2][0]&&s[1][1]==s[2][1]) {
			cout<<1;
			if(s[1][2]=='A'||s[1][2]=='B'||s[1][2]=='C') {
				if(s[2][2]=='A'||s[2][2]=='B'||s[2][2]=='C') {
					cout<<1;
					if(s[1][2]=='A') {
						if(s[2][2]=='B') cout<<1;
						else cout<<0;
					}
					if(s[1][2]=='B') cout<<1;
					if(s[1][2]=='C') {
						if(s[2][2]=='B') cout<<1;
						else cout<<0;
					}
				} else cout<<"00";
			} else if(s[1][2]=='D'||s[1][2]=='F') {
				if(s[2][2]=='D'||s[2][2]=='F') cout<<11;
				else cout<<"00";
			}
		} else cout<<"000";
	} else cout<<"0000";
	return 0;
}
