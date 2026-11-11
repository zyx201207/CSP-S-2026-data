#include <bits/stdc++.h>
using namespace std;
bool c, cl, r, lin;
int cr, cx, rr, rx;
string sr, sx;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> cr >> sr >> cx >> sx;
	if(cr == cx) c = 1;
	cr = (sr[0] - '0') * 10 + (sr[1] -'0');
	cx = (sx[0] - '0') * 10 + (sx[1] -'0');
	if(c && cr == cx) cl = 1;
	rr = sr[2] - 'A', rx = sx[2] - 'A';
	if(cl && ((rr < 3 && rx < 3) || (rr >= 3 && rx >= 3))) r = 1;
	if(r && abs(rr - rx) == 1) lin = 1;
	cout << c << cl << r << lin;
	return 0;
}
