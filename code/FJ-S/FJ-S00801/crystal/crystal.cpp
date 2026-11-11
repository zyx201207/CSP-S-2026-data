#include <bits/stdc++.h>
using namespace std;

long long sum[500005], a[500005], n, m, k, maxn, l, r, ans;

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + n + 1);
	if (n < 5001) {
		for (long long i = 1; i <= n; i++) {
			k = m;
			ans = 1;
			for (long long j = i - 1; j; j--) {
				if (a[i] - a[j] <= k) {
					k -= (a[i] - a[j]);
					ans++;
				} else break;
			}
			maxn = max(maxn, ans);
		}
		cout << maxn;
		return 0;
	}
	for (long long i = 1; i <= n; i++) sum[i] = sum[i - 1] + a[i];
	for (long long i = 1; i <= n; i++) {
		l = 1;
		r = i;
		ans = 1e18;
		while (l <= r) {
			long long mid = l + (r - l) / 2;
			if ((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1]) <= m) {
				ans = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		maxn = max(maxn, i - ans + 1);
	}
	cout << maxn;
	return 0;
}
