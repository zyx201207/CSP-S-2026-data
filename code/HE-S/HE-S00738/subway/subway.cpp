#include <iostream>
#include <vector>
#define int long long
using namespace std;
const int N = 510, M = 5e5 + 10, inf = 1e16;
vector<pair<int, int> > d[M];
int val[N][N], c, n, m, D, q, w[M];
bool vis[N];
void clear() {
	for(int i = 1; i <= n; i ++) 
		for(int j = 1; j <= n; j ++) 
			if(i != j) val[i][j] = inf;
}
void Floyd() {
	for(int k = 1; k <= n; k ++) {
		for(int i = 1; i <= n; i ++) {
			for(int j = 1; j <= n; j ++) {
				val[i][j] = min(val[i][j], val[i][k] + val[k][j]);
			}
		}
	}
	for(int i = 1; i <= n; i ++) 
		for(int j = 1; j < i; j ++) val[i][j] = min(val[i][j], val[j][i]);
}
signed main() {
//	freopen("D:\\P.in", "r", stdin);
//	freopen("D:\\P.out", "w", stdout);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);cin.tie(NULL);
	cin >> c >> n >> m >> D >> q;
	clear();
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		for(int j = 1; j <= k; j ++) {
			int pos, t;
			cin >> pos >> t;
			d[pos].push_back({i, t}); 
		} 
	}
	for(int i = 1; i <= m; i ++) {
		int len = d[i].size();
		for(int j = 0; j < len; j ++) {
			for(int k = j + 1; k < len; k ++) {
				int u = d[i][j].first, w1 = d[i][j].second, v = d[i][k].first, w2 = d[i][k].second;
				val[u][v] = min(val[u][v], w1 + w2);
				val[v][u] = min(val[v][u], w1 + w2);
			}
		}
	}
	Floyd();
	for(int i = 1; i <= q; i ++) {
		int s, t, ans = 0, Mi = inf;
		cin >> s >> t;
		ans += w[s] + w[t];
		for(auto x : d[s]) 
			for(auto y : d[t]) 
				Mi = min(Mi, x.second + y.second + val[x.first][y.first]);
		ans += Mi;
		cout << ans << '\n';
	}
	return 0;
}
 
