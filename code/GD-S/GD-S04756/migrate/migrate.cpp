#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, t;
void SPEA(int n, int d, vector<int>& x) {
	int DD = x[x.size() - 1] - x[x.size() - 2];
	if (d < DD)
		return cout << "0\n", 0;
	if (d < 2 * DD)
		return cout << "0\n", 0;
	
}
void solve() {
	int n, d;
	cin >> n >> d;
	vector<int> x(n);
	for (int & X: x)
		cin >> X;
	if (c == 1 || c == 2) {
		
	} else if (c == 11 || c == 12) {
		SPEA(n, d, x);
	}
}
signed main() {
	#ifndef LOCALENV
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	#endif
	cin >> c >> t;
	while(t--) {
		solve();
	}
	return 0;
}
