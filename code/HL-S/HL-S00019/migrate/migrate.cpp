#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
int n, d, nxt[N], l[N], r[N], pre[N];
ll x[N];

void Solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	ll ans = n;
	if (x[2] - x[1] >= d) cout << "0\n";
	else {
		ans = ans - d / (x[2] - x[1]) * 2 + 1;
		if (ans < 0) cout << "0\n";
		else cout << ans << "\n";
	}
}
signed main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T = 1, c;
	cin >> c >> T;
	while (T--) Solve();
	return 0;
}
/*
求出来 k 的 floyd
*/