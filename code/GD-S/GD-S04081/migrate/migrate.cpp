#include <bits/stdc++.h>
using namespace std;
int dp[7500][7500], n, cnt, d, x[200006];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios_base::sync_with_stdio();
	cin.tie(0);
	int c, t;
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
			dp[i][i] = 1;
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i; j <= n; j++) {
				if (x[j] - x[i] <= d) {
					for (int k = 1; k <= d; k++) {
						dp[i][j] = min (dp[i][j], dp[i][k] + 1);
					}
				}
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (dp[i][j] == 2) {
					cnt++;
				}
			}
		}
		cout << cnt << "\n";
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = 0;
			}
		}
		cnt = 0;
	}
	return 0;
} 
