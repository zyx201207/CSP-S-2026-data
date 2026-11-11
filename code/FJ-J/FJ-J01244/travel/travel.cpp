#include <bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=(a);i<=(b);i++)
#define Rof(i,a,b) for(int i=(a);i>=(b);i--)
#define PII pair<int, int>
const int N = 1000010;
const int inf = 1e18;
using namespace std;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	string ax, ay, bx, by;
	cin >> ax >> ay >> bx >> by;
	bool a, b, c, d;
	if(ax == bx) a = 1;
	if(ay[0] == by[0] && ay[1] == by[1] && a) b = 1;
	if(((ay[2] < 'D' && by[2] < 'D') || (ay[2] >= 'D' && by[2] >= 'D')) && b) c = 1;
	if(c && abs(ay[2] - by[2]) == 1) d = 1;
	cout << a << b << c << d;
	return 0;
}
