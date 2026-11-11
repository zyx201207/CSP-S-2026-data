#include<bits/stdc++.h>
using namespace std;
#define int long long
#define F first
#define S second
const int M = 5e5 + 7, N = 5e2 + 7, inf = 1e15 + 7;
int read() {
	int ans = 0;
	char ch = getchar();
	while (ch < '0' || '9' < ch) ch = getchar();
	while ('0' <= ch && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	return ans;
}
int w[M], dp[N][N];
vector<pair<int, int>> G[M];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	int c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) dp[i][j] = inf;
	}
	for (int i = 1; i <= n; ++i) {
		int len = read();
		for (int j = 1; j <= len; ++j) {
			int x = read(), val = read();
			G[x].push_back({i, val});
		}
		dp[i][i] = 0;
	}
	for (int i = 1; i <= m; ++i) {
		int len = G[i].size();
		for (int j = 0; j < len; ++j) {
			for (int k = 0; k < len; ++k) {
				int x = G[i][j].F, y = G[i][k].F, val = G[i][j].S + G[i][k].S;
				dp[x][y] = min(dp[x][y], val);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			for (int k = 1; k <= n; ++k) {
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	while (q--) {
		int x = read(), y = read(), ans = inf;
		for (int i = 0; i < G[x].size(); ++i) {
			for (int j = 0; j < G[y].size(); ++j) {
				ans = min(ans, G[x][i].S + G[y][j].S + dp[G[x][i].F][G[y][j].F]);
			}
		}
		cout << ans + w[x] + w[y] << endl;
	}
	return 0;
} 
