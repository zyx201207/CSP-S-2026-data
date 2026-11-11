#include <bits/stdc++.h>
#define cmax(a, b) a = max(a, b)
#define cmin(a, b) a = min(a, b)
#define inf (1e16 +7)
using namespace std;
using ll = long long;
const int N = 5e5 + 10;

int c, n, m, d, q;
ll w[N];
vector<pair<int, ll>> vec[N]; // 记录每个点通过的线路
ll dis[505][505]; 
void solve() {
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; ++i) {
		cin >> w[i];
		vec[i].reserve(d + 1);
	}
	for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) dis[i][j] = inf;
	for(int i = 1, k; i <= n; ++i) {
		cin >> k, dis[i][i] = 0;
		for(int j = 1; j <= k; ++j) {
			int a; ll t;
			cin >> a >> t;
			vec[a].push_back({i, t});
		}
	}
	//按链缩点 
	for(int u = 1; u <= m; ++u) {
		for(int i = 0; i < (int)vec[u].size(); ++i) {
			ll t1 = vec[u][i].second;int a1 = vec[u][i].first;
			for(int j = i + 1; j < (int)vec[u].size(); ++j) {
				ll t2 = vec[u][j].second;int a2 = vec[u][j].first;
				cmin(dis[a1][a2], t1 + t2);
				cmin(dis[a2][a1], t1 + t2);
			}
		}
	}
	
	//floyd
	for(int k = 1; k <= n; ++k) {
		for(int i = 1; i <= n; ++i) {
			for(int j = 1; j <= n; ++j) {
				cmin(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--) {
		int x, y;
		cin >> x >> y;
		ll ans = inf;
		for(auto tmp1 : vec[x]) {
			int a1 = tmp1.first;ll t1 = tmp1.second;
			for(auto tmp2 : vec[y]) {
				int a2 = tmp2.first;ll t2 = tmp2.second;
				cmin(ans, dis[a1][a2] + w[x] + w[y] + t1 + t2);
			}
		}
		cout << ans << "\n";
	}
	return ;
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	solve();
	return 0;
} 
