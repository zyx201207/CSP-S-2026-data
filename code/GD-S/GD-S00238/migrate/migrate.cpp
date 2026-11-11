#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
constexpr int N = 2e6;
int c, t;
int n;
LL m;
LL a[N + 5];
int f[N + 5], dp[N + 5], s[N + 5];
void solve() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		memset(f + 1, 0x3f, n * sizeof(int));
		memset(dp + 1, 0, n * sizeof(int));
		f[i] = 0;
		for (int j = i + 1, k = i; j <= n; j++) {
			while (k < j && a[j] - a[k] > m) k++;
			f[j] = f[k] + 1;
		}
		dp[i] = s[i] = 1, s[i - 1] = 0;
		for (int j = i + 1, k = i, l = i; j <= n; j++) {
			if (f[j] > n) break;
			while (k + 1 < j && f[k + 1] < f[j]) k++;
			while (l < j && a[j] - a[l] > m) l++;
			dp[j] = min(3, s[k] - s[l - 1]);
			s[j] = s[j - 1] + dp[j];
		}
		for (int j = i + 1; j <= n; j++)
			ans += dp[j] == 2;
	}
	cout << ans << '\n';
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	cin >> c >> t;
	while (t--) solve();
	return 0;
}

