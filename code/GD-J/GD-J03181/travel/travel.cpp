#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b;
	string n,m;
	cin>>a>>n>>b>>m;
	if(a==b) {
		cout<<1;
		if(n[0]==m[0]&&n[1]==m[1]) {
			cout<<1;
			if(n[2]=='A'||n[2]=='B'||n[2]=='C') {
				if(m[2]=='A'||m[2]=='B'||m[2]=='C') {
					cout<<1;
					if(n[2]=='A'||m[2]=='A') {
						if(n[2]=='C'||m[2]=='C') cout<<0;
						else cout<<1;
					}
					else cout<<1;
				}
				else cout<<"00";
			}
			else {
				if(m[2]=='D'||m[2]=='F') cout<<11;
				else cout<<"00";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}
