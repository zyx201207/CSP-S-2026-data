#include <bits/stdc++.h>
#define int long long
using namespace std;

namespace Creeper{
	const int N = 5e5 + 5;
	int n, m, a[N], s[N], ans;
	void solve() {
		cin >> n >> m;
		for (int i = 1; i <= n; i++) cin >> a[i];
		sort(a + 1, a + n + 1);
		for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
		for (int i = 1; i <= n; i++) {
			int l = 1, r = i, res = 0;
			while (l <= r) {
				int mid = l + r >> 1;
				if (a[i] * (i - mid + 1) - (s[i] - s[mid - 1]) <= m) r = mid - 1, res = mid;
				else l = mid + 1;
			}
			ans = max(ans, i - res + 1);
		} 
		cout << ans;
	}
}

signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int T = 1;
//	cin >> T;
	while (T--) Creeper::solve();
}
