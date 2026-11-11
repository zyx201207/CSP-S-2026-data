#include<bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e2 + 5, M = 5e5 + 5;
const ll INF = 1e18 + 114514;

int nababa, n, m, d, q;
int w[M];
ll dp[N][N];
vector<pair<int, int> > adj[M];

int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> nababa >> n >> m >> d >> q;
	for(int i = 1; i <= m; i++) cin >> w[i];
	for(int i = 1, l, u, w; i <= n; i++){
		cin >> l;
		for(int j = 1; j <= l; j++){
			cin >> u >> w;
			adj[u].push_back({i, w});
		}
		fill(dp[i] + 1, dp[i] + 1 + n, INF);
		dp[i][i] = 0;
	}
	for(int i = 1; i <= m; i++){
		for(int j = 0; j < adj[i].size(); j++){
			int w1 = adj[i][j].first, t1 = adj[i][j].second;
			for(int k = j + 1; k < adj[i].size(); k++){
				int w2 = adj[i][k].first, t2 = adj[i][k].second;
				dp[w1][w2] = min(dp[w1][w2], 1ll * t1 + t2);
				dp[w2][w1] = min(dp[w2][w1], 1ll * t1 + t2);
			}
		}
	}
	for(int k = 1; k <= n; k++){
		for(int i = 1; i <= n; i++){
			for(int j = 1; j <= n; j++){
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j]);
			}
		}
	}
	for(int i = 1, s, t; i <= q; i++){
		cin >> s >> t;
		ll ans = INF;
		for(int j = 0; j < adj[s].size(); j++){
			for(int k = 0; k < adj[t].size(); k++){
				int w1 = adj[s][j].first, t1 = adj[s][j].second, w2 = adj[t][k].first, t2 = adj[t][k].second;
				ans = min(ans, dp[w1][w2] + t1 + t2);
			}
		}
		cout << ans + w[s] + w[t] << '\n';
	}
	return 0;
}
/*

*/
