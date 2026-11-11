#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<map>
using namespace std;
#define int long long
#define fi first
#define se second
const int inf = 0x3f3f3f3f3f3f3f3f;
int C, n, m, d, q, w[1000010], dis[510][510];
vector<pair<int, int> > av[1000010];
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	memset(dis, 0x3f, sizeof(dis));
	scanf("%lld%lld%lld%lld%lld", &C, &n, &m, &d, &q);
	for(int i = 1; i <= m; i++) scanf("%lld", &w[i]);
	for(int i = 1; i <= n; i++) {
		int j, u, t; scanf("%lld", &j);
		while(j--) {
			scanf("%lld%lld", &u, &t);
			av[u].push_back({i, t});
		}
	}
	for(int i = 1; i <= n; i++) dis[i][i] = 0;
	for(int u = 1; u <= m; u++) {
		for(int i = 0; i < (int)av[u].size(); i++) {
			for(int j = 0; j < (int)av[u].size(); j++) {
				int uu = av[u][i].fi, vv = av[u][j].fi, ww = av[u][i].se + av[u][j].se;
				dis[uu][vv] = min(dis[uu][vv], ww);
			}
		}
	}
	for(int k = 1; k <= n; k++) {
		for(int i = 1; i <= n; i++) {
			for(int j = 1; j <= n; j++) {
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
			}
		}
	}
	while(q--) {
		int XrR, YrR, Ans = inf; scanf("%lld%lld", &XrR, &YrR);
		for(int i = 0; i < (int)av[XrR].size(); i++) {
			for(int j = 0; j < (int)av[YrR].size(); j++) {
				int u = av[XrR][i].fi, v = av[YrR][j].fi;
				int TtT = av[XrR][i].se + av[YrR][j].se;
				TtT += dis[u][v];
				Ans = min(Ans, TtT);
			}
		}
		printf("%lld\n", Ans + w[XrR] + w[YrR]);
	}
	return 0;
}
