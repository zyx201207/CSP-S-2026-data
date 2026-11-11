#include <bits/stdc++.h>
#define int long long
#define N (int)(5e5 + 5)
using namespace std;
int n, m, a[N], ans;
inline int Get_ans (int l, int r) {
	return (a[r] - a[r - 1]) * (r - l) - a[r - 1] + a[l - 1];
} 
inline int Check (int l, int r) {
	int id = 0, g = l;
	while (l <= r) {
		int mid = (l + r) >> 1;
		if (Get_ans (g, mid) <= m) {
			l = mid + 1;
			id = mid;
		} else
			r = mid - 1;
	}
	return id;
}
signed main () {
	ios::sync_with_stdio (0);
	cin.tie (0), cout.tie (0);
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	sort (a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++)
		a[i] += a[i - 1];
	for (int i = 1; i <= n; i ++)
		ans = max (ans, Check (i, n) - i + 1);
	cout << ans << '\n';
	return 0;
}
