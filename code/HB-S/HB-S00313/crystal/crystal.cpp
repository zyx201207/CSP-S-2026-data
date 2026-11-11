#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 7;
int n, m, ans;
int a[MAXN], sum[MAXN];
signed main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	for 
	(int i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++) {
		int l = 0, r = i, tmp = 0;
		while (l <= r) {
			int mid = (l + r) / 2;
			int tot = sum[i] - sum[i - mid];
			int need = mid * a[i] - tot;
			if (need <= m) {
				tmp = mid;
				l = mid + 1;
			} else r = mid - 1;
		}
		ans = max(ans, tmp);
	}
	cout << ans << "\n";
	return 0;
}
