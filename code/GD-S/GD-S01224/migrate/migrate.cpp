#include <bits/stdc++.h>

using namespace std;
using ll = long long;

constexpr int N = 2e6 + 5, N12 = 6e3 + 5;

int n, c; ll dp[N12], cnt[N12], eq[N12], d, x[N];

void solve() {
	cin >> n >> d;
	for (int i = 1; i <= n; ++i) cin >> x[i];
	if (n <= 6000) {
		ll ans = 0;
		for (int l = 1, pre = 1; l <= n; ++l) {
			pre = l;
			for (int i = l; i <= n; ++i) dp[i] = 0, eq[i] = cnt[i] = 1;
			int R = n;
			for (int r = l + 1; r <= n; ++r) {
				while (x[r] - x[pre] > d) ++pre;
				if (r == pre) {
					R = r - 1; break;
				}
				dp[r] = dp[pre] + 1;
//				cout << pre << ' ' << dp[pre] << ' ' << "+1" << ' ' << "->" << dp[r] << '\n';
			}
			for (int i = l; i <= R; ++i) {
				if (i > l && dp[i] == dp[i - 1]) eq[i] = eq[i - 1] - 1;
				else {
					int t = i;
					while (t < R && dp[t] == dp[t + 1]) eq[i]++, ++t;
				}
			}
			pre = l;
			for (int r = l; r <= R; ++r) {
				while (x[r] - x[pre] > d) ++pre;
				cnt[r] = cnt[pre] * eq[pre];
//				cout << ' ' << r << ' ' << cnt[r] << '\n';
				ans += (cnt[r] == 2);
			}
//			cout << l << '~' << R << ':' << '\n';
//			for (int i = l; i <= R; ++i) cout << dp[i] << ' '; 
//			cout << '\n';
		}
		cout << ans << '\n';
	} 
	 else
	if (c == 11 || c == 12) {
		int D = x[2] - x[1];
		int cnt1 = d / D; ll ans = 0;
		if (cnt1 <= 1) return cout << 0 << '\n', void();
		for (int l = 1; l <= n; ++l) {
			int ct = (n - l + 1) / cnt1;
			if (ct > 1) ans += ct - 1;
			cout << l << ' ' << ct << ' ' << ct - 1 << ' ' << ans << '\n';
		} 
		cout << ans << '\n';
	} else if (c == 13 || c == 14) {
		if (x[n] - x[1] < 2 * d) return cout << 0 << '\n', void();
		cout << 2 << '\n';
	}
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	int T; cin >> c >> T;
	while (T--) solve();	
} 
