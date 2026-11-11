#include <bits/stdc++.h>
#define int long long

constexpr int N = 2e6 + 5, INF = 1e18;

int n, d, x[N], dp[1005][1005], w[1005][1005];

void sol () {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			if (abs (x[i] - x[j]) <= d) {
				dp[i][j] = (i != j);
				w[i][j] = (i != j);
			} else dp[i][j] = INF, w[i][j] = 0;
		}
	}
	for (int k = 1; k <= n; k ++) {
		for (int s = 1; s <= n; s ++) {
			for (int t = 1; t <= n; t ++) {
				if (dp[s][k] + dp[k][t] == dp[s][t]) {
					w[s][t] += w[s][k] * w[k][t];
				}
				else if (dp[s][k] + dp[k][t] < dp[s][t]) {
					w[s][t] = w[s][k] * w[k][t];
					dp[s][t] = dp[s][k] + dp[k][t];
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i ++) {
		for (int j = i + 1; j <= n; j ++) {
//			std :: cout << w[i][j] << ' ';
			ans += w[i][j] == 2;
		}
//		std :: cout << '\n';
	}
	std :: cout << ans << '\n';
}

void solve () {
	std :: cin >> n >> d;
	for (int i = 1; i <= n; i ++) {
		std :: cin >> x[i];
	}
	sol ();
}

signed main () {
	freopen ("migrate.in", "r", stdin);
	freopen ("migrate.out", "w", stdout);
	std :: ios :: sync_with_stdio (false), std :: cin.tie (0), std :: cout.tie (0);
	int TTT; std :: cin >> TTT >> TTT; while (TTT --)
	solve ();

	return 0;
}

