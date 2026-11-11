#include <bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 5;
long long n, m, a[N], ans, sum[N], l, r, res;
int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	sort(a + 1, a + 1 + n);
	for (long long i = 1; i <= n; i++) {
		sum[i] = sum[i - 1] + a[i];
		if (a[i] == a[i + 1]) continue;
		l = 1; r = i; res = 0;
		while (l <= r) {
			long long mid = (l + r) >> 1;
			if (abs((i - mid + 1) * a[i] - (sum[i] - sum[mid - 1])) <= m) {
				res = mid;
				r = mid - 1;
			} else l = mid + 1;
		}
		if (res) ans = max(ans, i - res + 1);
	}
	cout << ans;
	return 0;
} 
