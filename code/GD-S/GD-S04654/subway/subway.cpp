#include <bits/stdc++.h>
using namespace std;
#define int long long
int c, n, m, d, q, dis[505][505], w[500005], k[505], x, y, ans, sum;
vector<pair<int, int> > v[500005];
vector<pair<int, int> > e[505];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	memset(dis, 0x7f, sizeof(dis));
	for(int i = 1; i <= n; i++)dis[i][i] = 0;
	for(int i = 1; i <= m; i++){
		scanf("%lld", w + i);
	}
	for(int i = 1; i <= n; i++){
		scanf("%lld", k + i);
		for(int j = 1; j <= k[i]; j++){
			int a, t;
			scanf("%lld%lld", &a, &t);
			v[a].push_back({i, t});
			e[i].push_back({a, t});
		}
	}
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= k[i]; j++){
			int u = e[i][j - 1].first, cnt = e[i][j - 1].second;
			for(int l = 0; l < (int)(v[u].size()); l++){
				if(v[u][l].first == i)continue;
				int to = v[u][l].first, w = v[u][l].second;
				dis[i][to] = min(dis[i][to], w + cnt);
//				printf("%lld : %lld %lld %lld %lld\n", l, i, to, w, cnt);
			}
		}
	}
	for(int i = 1; i <= n; i++){
		for(int k = 1; k <= n; k++){
			for(int j = 1; j <= n; j++){
				dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
				dis[j][i] = dis[i][j];
			}
		}
	}
	while(q--){
		scanf("%lld%lld", &x, &y);
		ans = -1;
		for(int i = 0; i < (int)(v[x].size()); i++){
			for(int j = 0; j < (int)(v[y].size()); j++){
				sum = dis[v[x][i].first][v[y][j].first] + v[x][i].second + v[y][j].second;
				ans = ans == -1 ? sum : min(sum, ans);
			}
		}
		printf("%lld\n", ans + w[x] + w[y]);
	}
	return 0;
}
