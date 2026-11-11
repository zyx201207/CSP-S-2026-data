#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int a,b,x,y;
string s,t;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cin>>s;
	a=(s[0]-'0')*10+(s[1]-'0');
	cin>>s>>t;
	b=(t[0]-'0')*10+(t[1]-'0');
	cin>>t;
	if(a!=b) cout<<"0000";
	else {
		cout<<'1';
		x=(s[0]-'0')*10+(s[1]-'0');
		y=(t[0]-'0')*10+(t[1]-'0');
		if(x!=y) cout<<"000";
		else {
			cout<<'1';
			if((s[2]<='C' && t[2]<='C') || (s[2]>'C' && t[2]>'C')) {
				if(abs((int)s[2]-(int)t[2])<=1) cout<<"11";
				else cout<<"10";
			}
			else cout<<"00";
		}
	}
	return 0;
}
// csp-j 2026 1=
// 求求了，给我1=吧 
