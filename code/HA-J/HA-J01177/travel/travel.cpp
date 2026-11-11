#include<bits/stdc++.h>
using namespace std;
#define int long long
const int mod = 998244353;
signed main() {
	freopen("travel.in", "r", stdin);
	freopen("travel.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	bool q = 0, w = 0, e = 0, r = 0;
	if(a == c) q = 1;
	if(b.substr(0, 2) == d.substr(0, 2) && a == c) w = 1;
	if(w == 1 && (b[2] <= 'C' && d[2] <= 'C' || b[2] > 'C' && d[2] > 'C')) e = 1;
	if(e == 1 && abs(b[2] - d[2]) == 1) r = 1;
	cout << q << w << e << r;
	return 0;
}
