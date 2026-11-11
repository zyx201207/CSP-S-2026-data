#include <bits/stdc++.h>
using namespace std;

long long d, x[2000010], m[5100][5100], dp[5010][5010];
int c, t, n, cnt[5010][5010], ans;
void dfs(int x1, int y, int u, int sum) {
	if (u == y) {
		if (m[x1][y] == sum) {
			cnt[x1][y]++;
		} else if (m[x1][y] > sum) {
			m[x1][y] = sum;
			cnt[x1][y] = 1;
		}
		return ;
	}
	for (int i = u + 1; i <= y; i++) {
		if (x[i] - x[u] <= d) {
			dfs(x1, y, i, sum + 1);
		}
	}
}
int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin >> c >> t;
	while (t--) {
		cin >> n >> d;
		ans = 0;
		memset(m, 127, sizeof m);
		memset(cnt, 0, sizeof cnt);
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				dfs(i, j, i, 0);
				dp[i][j] = cnt[i][j];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = i + 1; j <= n; j++) {
				if (cnt[i][j] == 2) {
				//	cout << i << " " << j << "\n";
					ans++;
				}
			}
		}
		cout << ans << "\n";
	}
	return 0;
} 
