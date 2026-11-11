#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N], val[N], pre[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		// (i - j) * a[i] - (pre[i - 1] - pre[j - 1]) 小于等于m
		// (i - j) * a[i] <= m + pre[i] - pre[j - 1]
		// pre[j - 1] + (i - j) * a[i] >= pre[i] - m(0 <= j <= i)
		int l = 1, r = i, ans = 1e9;
		while (l <= r) {
			int mid = (l + r) / 2;
			if (pre[mid - 1] + (i - mid) * a[i] <= pre[i - 1] + m) ans = mid, r = mid - 1;
			else l = mid + 1;
		}
//		cout << ans << '\n';
		val[i] = i - ans + 1;
//		cout << val[i] << '\n';
	}
	cout << *max_element(val + 1, val + n + 1) << '\n';
	return 0;
}
