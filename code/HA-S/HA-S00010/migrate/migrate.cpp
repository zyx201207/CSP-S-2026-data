#include<bits/stdc++.h>
using namespace std;
#define int long long
void solve()
{
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	a.push_back(a[n] + 1);
	vector<int> nex(n + 2, -1);
	for (int i = 1; i <= n; i++) {
		int l = i + 1, r = n, res = -1;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (a[mid] > a[i] + d) {
				r = mid - 1;
			} else {
				l = mid + 1;
				res = mid;
			}
		}
		nex[i] = res;
//		cout << res << ' ';
	}
//	cout << '\n';
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		vector<int> dp1(n + 2, 1e9), dp2(n + 2, 0);
		dp1[i] = 0;
		dp2[i] = 1;
		for (int j = i; j <= n; j++) {
			ans += (dp2[j] == 2);
			if (nex[j] == -1) {
				continue;
			}
			for (int k = j + 1; k <= nex[j]; k++) {
				if (dp1[k] > dp1[j] + 1) {
					dp1[k] = dp1[j] + 1;
					dp2[k] = 0;
				}
				dp2[k] += dp2[j] * (dp1[k] == dp1[j] + 1);
			}
//			cout << dp1[j] << ' ' << dp2[j] << '\n';
		}
	}
	cout << ans << '\n';
}
void solve2()
{
	int n, d;
	cin >> n >> d;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int k = a[2] - a[1];
	if ((d / k) <= 1) {
		cout << 0 << '\n';
		return;
	}
	int tp = d / k, ans = 0;
	for (int i = 1; i <= n; i++) {
		ans += (n - i >= 2 * tp - 1);
	}
	cout << ans << '\n';
}
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	int c, T;
	cin >> c >> T;
	if (11 <= c && c <= 12) {
		while (T--) {
			solve2();
		}
		return 0;
	}
	while (T--) {
		solve();
	}
	return 0;
}