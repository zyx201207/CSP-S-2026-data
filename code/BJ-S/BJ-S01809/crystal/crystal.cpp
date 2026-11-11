/**
 * @file CSP-S 2026
 *       Problem A. crystal
 * @author BJ-S01809
 *         LG-1014842 liuli688
 * @date 2026/10/31
*/
//password: Oct31==Dec25?

// 面对它，击溃它！

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 10;
ll n, m, a[N], s[N], ans;

signed main() {
	cin.tie(nullptr)->sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; ++i)
		s[i] = s[i - 1] + a[i];
	for (int i = 1; i <= n; ++i) {
		// cerr << i << '\n';
		ll l = 1, r = i, mid;
		while (l <= r) {
			mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m)
				r = mid - 1;
			else
				l = mid + 1;
		}
		ans = max(ans, i - r);
	}
	cout << ans << '\n';
	return 0;
}

//14:42