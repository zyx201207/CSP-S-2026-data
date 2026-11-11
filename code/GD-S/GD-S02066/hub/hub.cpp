#include<bits/stdc++.h>
using namespace std;

const int maxn = 4005;
int n, K, dp[maxn][maxn][3][2], siz[maxn];
vector<int> g[maxn];

void dfs(int u, int f) {
	if(g[u].size() == 1) {
		dp[u][1][1][1] = dp[u][0][0][0] = 0;
		return;
	}
	int mxdis = 0;
	for(auto v : g[u]) {
		if(v == f)	
			continue;
		dfs(v, u);
		mxdis = max(mxdis, dp[v][0][0][0] + 1);
		siz[u] += siz[v];
	}
	dp[u][0][0][0] = mxdis;
	for(auto v : g[u]) {
		if(v == f)	
			continue;
		for(int k = 1; k <= min(siz[u], K); k ++) {
			dp[u][k][1][1] = max(dp[u][k][1][1], dp[v][0][0][0]);
			dp[u][k][2][1] = 
			for(int j = 1; j < k; j ++) {
				if(dp[u][k][1][1] > dp[v][k - j][1][1]) {
					dp[u][k][1][1] = dp[v][k - j][1][1];
				}
			}
		}
	}
}
int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int T;
	cin >> T;
	while(T --) {
		cin >> n >> K;
		for(int i = 1; i <= n; i ++) {
			g[i].clear();
			for(int j = 0; j <= K; j ++) {
				for(int k = 0; k <= 2; k ++) {
					dp[i][j][k][0] = dp[i][j][k][1] = 1e9;
				}
			}
			siz[i] = 1;
		}
		for(int i = 1; i < n; i ++) {
			int u, v;
			cin >> u >> v;
			g[u].push_back(v);
			g[v].push_back(u);
		}
		cout << 0 << '\n';
		dfs(1, 0);
	}
	return 0;
}
