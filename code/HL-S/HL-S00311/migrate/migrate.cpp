#include <bits/stdc++.h>

using namespace std;

long long x[2000001];
long long dp1[2000001];
long long dp2[2000001];
long long n, d;

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		long long ans = 0;
		for (int i = 1; i <= n; i++) cin >> x[i];
		for (int i = 1; i <= n; i++) {
			memset(dp1, 0, sizeof(dp1));
			memset(dp2, 0x3f, sizeof(dp2));
			dp1[i] = 1;
			dp2[i] = 0;
			for (int j = i; j <= n; j++) {
				ans += dp1[j] == 2;
				for (int k = j + 1; k <= n && x[k] - x[j] <= d; k++) {
					if (dp2[j] + 1 < dp2[k]) {
						dp1[k] = 0;
						dp2[k] = dp2[j] + 1;
					} else if (dp2[j] + 1 > dp2[k]) {
						continue;
					}
					dp1[k] += dp1[j];
				}
			}
		}
		cout << ans << '\n';	
	}
}
