#include <bits/stdc++.h>
#define int long long
using namespace std;
string cr, cx, sr, sx;
int a, b, c, d;
signed main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin.tie(0);
	cout.tie(0);
	cin >> cr >> sr >> cx >> sx;
	if(cr == cx) {
		a = 1;
		int r, x;
		r = (sr[0]-'0') * 10 + sr[1] - '0';
		x = (sx[0]-'0') * 10 + sx[1] - '0';
		if(r == x)  {
			b = 1;
			int fr, fx;
			fr = 0;
			fx = 0;
			if(sr[2] == 'A' || sr[2] == 'B' || sr[2] == 'C') fr = 1;
			else fr = 2;
			if(sx[2] == 'A' || sx[2] == 'B' || sx[2] == 'C') fx = 1;
			else fx = 2;
			if(fr == fx) {
				c = 1;
				if(fr == 1) {
					int rr, xx;
					rr = sr[2] - 'A';
					xx = sx[2] - 'A';
					if(rr > xx) swap(rr,xx);
					if(xx - rr == 1) d = 1;
				}
			}
		}
	} 
	cout << a << b << c << d;
	return 0;
}
