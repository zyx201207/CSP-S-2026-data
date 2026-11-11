#include <bits/stdc++.h>
using namespace std;

int c, n, m, d, q, w[500010], k[510];
long long dis[510][510];
vector<pair<int, int>> edge[500010];

int main(){
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	scanf ("%d%d%d%d%d", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; i++)
		scanf ("%d", &w[i]);
	for (int i = 1; i <= n; i++){
		scanf ("%d", &k[i]);
		for (int j = 1; j <= k[i]; j++){
			int x, t;
			scanf ("%d%d", &x, &t);
			edge[x].push_back({m + i, t});
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j)
				dis[i][j] = 1LL << 60LL;
	for (int i = 1; i <= m; i++){
		int len = (int)edge[i].size();
		for (int j = 0; j < len; j++){
			int x = edge[i][j].first - m, z1 = edge[i][j].second;
			for (int k = j + 1; k < len; k++){
				int y = edge[i][k].first - m, z2 = edge[i][k].second;
				dis[x][y] = min(dis[x][y], (long long)(z1 + z2));
				dis[y][x] = dis[x][y];
			}
		}
	}
	for (int k = 1; k <= n; k++)
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= n; j++)
				if (dis[i][k] < 1LL << 60LL && dis[k][j] < 1LL << 60LL)
					dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
	for (; q--; ){
		int x, y;
		scanf ("%d%d", &x, &y);
		long long ans = 1LL << 60LL;
		for (auto it : edge[x])
			for (auto it2 : edge[y])
				ans = min(ans, dis[it.first - m][it2.first - m] + it.second + it2.second);
		printf ("%lld\n", w[x] + w[y] + ans);
	}
	return 0;
}
