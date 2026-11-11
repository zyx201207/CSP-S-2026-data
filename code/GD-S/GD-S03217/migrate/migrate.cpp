#include <bits/stdc++.h>
using namespace std;
const long long N = 2e6 + 5, inf = 1e18;
long long c, t, n, d, a[N], sum, ans;
void sol() {
	sum = 0;
	cin >> n >> d;
	for (long long i = 1; i <= n; i++) cin >> a[i];
	for (long long i = 1; i + 2 <= n; i++) 
		sum += (a[i + 2] - a[i] <= d);
	cout << sum << '\n';
}
void cal() {
	while (t--) {
		ans = 0;
		cin >> n >> d;
		for (long long i = 1; i <= n; i++) cin >> a[i];
		for (long long len = 3; len <= n; len++)
			for (long long l = 1; l + len - 1 <= n; l++) {
				long long r = l + len - 1;
				if (a[r] - a[l] <= d || a[r - 1] - a[l] > d) break;
				ans++;
			}
		cout << ans << '\n';
	}
	exit(0);
}
int main() {
	cin.tie(0) -> sync_with_stdio(false);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	if (c== 11 || c == 12) cal();
	while (t--) sol();
	return 0;
}
