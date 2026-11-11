#include <iostream>
#include <algorithm>
using namespace std;
constexpr int maxn = 5e5 + 10;
long long a[maxn], sum[maxn];
signed main () {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	int n; long long m; cin >> n >> m;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i]; sum[i] = sum[i - 1] + a[i];
	} sort(a + 1, a + n + 1);
	int r = 0, ans = 0; long long now = 0;
	for (int l = 1; l <= n; l ++) {
		while (r + 1 <= n && now + (a[r + 1] - a[r]) * (r - l + 1) <= m) {
			now += (a[r + 1] - a[r]) * (r - l + 1);
			r ++;
		}
		if (now <= m) {
			ans = max(ans, r - l + 1);
		}
		if (r <= n) {
			now -= (a[r] - a[l]);
		}
	} cout << ans;
}
