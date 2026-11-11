#include <bits/stdc++.h>
using namespace std;
const int N = 505, M = 5e5 + 5; typedef long long ll; const ll inf = 1e18;
int c, n, m, d, q, w[M], tot[N]; ll dis[N][N]; vector <pair<int,int> > line[N]; vector <pair<int,int> > e[M];
int main() {
	freopen("subway.in", "r", stdin); freopen("subway.out", "w", stdout);
	scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%d", &w[i]);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &tot[i]);
		for(int j = 1; j <= tot[i]; j++) { int a, t; scanf("%d%d", &a, &t); line[i].push_back({a, t}); e[a].push_back({i, t}); }
	}
	for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) if(i != j) dis[i][j] = inf;
	for(int i = 1; i <= n; i++) {
		for(auto x : line[i]) {
			int a = x.first, t = x.second;
			for(auto y : e[a]) {
				int j = y.first, t2 = y.second;
				if(i == j) continue ;
				dis[i][j] = min(dis[i][j], (ll)t + t2), dis[j][i] = min(dis[j][i], (ll)t + t2);
			}
		}
	}
	for(int k = 1; k <= n; k++)
		for(int i = 1; i <= n; i++)
			for(int j = 1; j <= n; j++)
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	while(q--) {
		int x, y; scanf("%d%d", &x, &y); ll ans = inf;
		for(auto u : e[x]) for(auto v : e[y]) {
			int l1 = u.first, l2 = v.first;
			ans = min(ans, dis[l1][l2] + u.second + v.second);
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}