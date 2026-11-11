#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 510, M = 10510;
int C, n, m, d, q, T, w[N], dis[N][N], cnt, D[M], ans[500010];
vector<int> v[M];
vector<pair<int, int> > aaq[500010];
signed main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0), cin.tie(0),
	cin >> C >> m >> n >> d >> q;
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j <= n; j ++)
			dis[i][j] = 1e18;
	for (int i = 1; i <= n; i ++)
		cin >> w[i], dis[i][i] = 0;
	if (C >= 7 && C <= 11){
		for (int i = 1, k; i <= m && cin >> k; i ++)
			for (int x, t, lx, lt, j = 1; j <= k; j ++){
				cin >> x >> t;
				if (j > 1)
					dis[x][lx] = dis[lx][x] = min(dis[lx][x], t + lt);
				else lx = x, lt = t;
			}
		for (int k = 1; k <= n; k ++)
			for (int i = 1; i <= n; i ++)
				for (int j = 1; j <= n; j ++)
					if (dis[i][j] > dis[i][k] + dis[k][j])
						dis[i][j] = dis[i][k] + dis[k][j];
		for (int i = 1; i <= q; i ++){
			int x, y;cin >> x >> y,
			cout << w[x] + w[y] + dis[x][y] << '\n';
		}
	}else if (C >= 12 && C <= 19 || !C){cnt = n;
		for (int i = 1, k; i <= m && cin >> k; i ++){
			if (k == 1){cin >> k >> k;continue;}cnt ++;
			for (int x, t, j = 1; j <= k; j ++)
				cin >> x >> t, T = t, v[cnt].push_back(x), v[x].push_back(cnt);
		}
		for (int i = 1; i <= q; i ++){
			int x, y;cin >> x >> y;
			if (x > y)swap(x, y);
			aaq[x].push_back({y, i});
		}for (int i = 1; i <= n; i ++){
			for (int j = 1; j <= cnt; j ++)D[j] = 1e18;
			D[i] = 0;
			queue<int> q;q.push(i);
			while (q.size()){
				int u = q.front();
				for (auto e : v[u]){
					if (D[e] != 1e18)continue;
					D[e] = D[u] + 1, q.push(e);
				}
			}for (auto e : aaq[i])ans[e.second] = 2 * D[e.first] * T + w[i] + w[e.first];
		}for (int i = 1; i <= q; i ++)cout << ans[i] << '\n';
	}
	return 0;
}
