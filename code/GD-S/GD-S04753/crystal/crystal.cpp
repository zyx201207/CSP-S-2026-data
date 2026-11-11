#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int a[N];
signed main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	int n, m, cnt = 0, ans, l = 1, r = 1, val;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	while (cnt <= m && r <= n) {
		val = (r - 1) * (a[r] - a[r - 1]);
		if (cnt + val > m) break;
		cnt += (r - 1) * (a[r] - a[r - 1]);
		r++;
	}
	ans = r - l;
	for (; r <= n; r++) {
		cnt += (r - l - 1) * (a[r] - a[r - 1]);
		while (cnt > m && l < r) {
			cnt -= a[r] - a[l];
			l++;
		}
		ans = max(ans, r - l);
	}
	cout << ans;
	return 0;
}
