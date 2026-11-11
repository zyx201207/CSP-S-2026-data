#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n;
int l, r;
ll m, a[N], sum[N];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	sort(a+1, a+n+1);
	for (int i = 1; i <= n; ++i) sum[i] = sum[i - 1] + a[i];
	int res = 1;
	for (int i = 1; i <= n; ++i) {
		l = 1, r = i;
		while (l <= r) {
			int mid = (l + r) >> 1;
			if (1ll * mid * a[i] - sum[i] + sum[i - mid] <= m) l = mid + 1;
			else r = mid - 1;
		}
		res = max(res, l - 1);
	}
	cout << res << '\n';
	return 0;
} 
