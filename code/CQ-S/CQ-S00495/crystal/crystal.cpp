#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;

ll n, m, a[N], sum[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int l = 1, r = n, res = n;
		while (l <= r) {
			int mid = l + r >> 1;
			if (a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m) r = mid - 1, res = mid;
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans << '\n';
	return 0;
}
//14:40 finished.It's so amazing!!!

