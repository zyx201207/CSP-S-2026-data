#include<bits/stdc++.h>
#define ll long long
#define N 100100

using namespace std;

ll n;
string s,a,b,x,y;
char c='1';

signed main() {
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> x >> y;
	if(a==x) {
		s+=c;
		string e,f;
		for(int i = 0; i < 2; ++i) {
			e+=b[i];
			f+=y[i];
		}
		if(e==f) {
			s+=c;
			if(((b[2]=='A'||b[2]=='B'||b[2]=='C')&&(y[2]=='A'||y[2]=='B'||y[2]=='C'))||((b[2]=='D'||b[2]=='F')&&(y[2]=='D'||y[2]=='F'))) {
				s+=c;
				if((b[2]=='A'&&y[2]=='B')||(b[2]=='B'&&y[2]=='C')||(b[2]=='B'&&y[2]=='A')||(b[2]=='C'&&y[2]=='B')||(b[2]=='D'&&y[2]=='F')||(b[2]=='F'&&y[2]=='D')) {
					s+=c;
				}
				else {
					s+='0';
				}
			}
			else {
				s+='0';
				s+='0';
			}
		}
		else {
			s+='0';
			s+='0';
			s+='0';
		}
		cout << s << "\n";
	}
	else {
		cout << "0000\n";
	}
	return 0;
} 
