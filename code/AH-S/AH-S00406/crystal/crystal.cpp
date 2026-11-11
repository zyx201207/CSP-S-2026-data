#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, m;
const int N = 5e5 + 10;
int a[N];
int sum[N];
signed main(void) {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + a[i];
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		int res = i;
		int l = 1, r = i;
		while (l <= r) {
			int mid = l + r >> 1;
			int v = sum[i] - sum[mid - 1];
			v = a[i] * (i - mid + 1) - v;
			if(v <= m) {
				res = mid;
				r = mid - 1;
			}
			else l = mid + 1;
		}
		ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
}