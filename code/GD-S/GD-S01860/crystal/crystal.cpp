#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1000010;
int n, m, a[N], sum[N], ans = 0;
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i, res = i;
		while (l <= r) {
			int mid = (l + r) / 2;
			if ((i - mid) * a[i] - (sum[i] - sum[mid]) <= m) {
				res = mid;
				r = mid - 1;
			}else l = mid + 1;
		}
		ans = max(ans, i - res);
	}
	cout << ans;
	return 0;
}
