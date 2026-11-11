#include <bits/stdc++.h>
using namespace std;
#define int long long
#define up(i, a, b) for(int i = a; i <= b; i++)
#define dn(i, a, b) for(int i = a; i >= b; i--)
#define VI vector <int>
void sub1() {
	int n, d; cin >> n >> d;
	VI x(n + 1), f(n + 2, 0), dp(n + 2, 0);
	up (i, 1, n) cin >> x[i];
	up (i, 1, n) {
		up (j, i, n) {
			if (x[j] > x[i] + d) break;
			if (f[j] == 0) f[j] = f[i] + 1;
			else f[j] = min (f[j], f[i] + 1);
		}
	}
	up (i, 1, n) {
		up (j, i, n) {
			if (x[j] > x[i] + d) break;
			if (f[j] == f[i] + 1) dp[j]++;
		}
	}
	up (i, 1, n) cout << dp[i] << ' ';
	cout << endl;
}
signed main () {
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
//	freopen("migrate1.in", "r", stdin);
//	freopen("migrate.out", "w", stdout);
	int c, t; cin >> c >> t;
//	while (t--) sub1();
	return 0;
}

