#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 505, M = 5e5 + 5, inf = 1e18;
int c, n, m, d, q, w[M], dis[N][N];
bitset <N> vis;
struct edge{
	int v, w;
};
struct node{
	int point, dist;
	bool operator > (const node &a) const {
		return dist < a.dist;
	}
};
int e[N][N]; 
vector <edge> vt[M], g[N];
void dij(int s){
	dis[s][s] = 0;
	priority_queue <node, vector <node>, greater <node>> q;
	q.push({s, 0});
	while (!q.empty()){
		int u = q.top().point;
		q.pop();
		if (vis[u])continue;
		vis[u] = 1;
		for (auto x : g[u]){
			int v = x.v, w = x.w;
			if (dis[s][v] > dis[s][u] + w){
				dis[s][v] = dis[s][u] + w;
				if (!vis[v])q.push({v, dis[s][v]});
			}
		}
	}
}
signed main(){
	cin.tie(0)->sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; ++i){
		cin >> w[i];
	}
	for (int i = 1, k; i <= n; ++i){
		cin >> k;
		for (int j = 1, x, y; j <= k; ++j){
			cin >> x >> y;
			vt[x].push_back({i, y});
		}
		for (int j = 1; j <= n; ++j){
			if (i != j)e[i][j] = inf;
		}
	}
	for (int i = 1; i <= m; ++i){
		int len = vt[i].size();
		for (int l = 0; l < len; ++l){
			int v = vt[i][l].v, w = vt[i][l].w;
			for (int r = l + 1; r < len; ++r){
				int vv = vt[i][r].v, ww = vt[i][r].w;
				e[v][vv] = e[vv][v] = min(e[v][vv], w + ww);
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			if (i != j && e[i][j] < inf){
				g[i].push_back({j, e[i][j]});
			}
		}
	}
	for (int i = 1; i <= n; ++i){
		for (int j = 1; j <= n; ++j){
			dis[i][j] = inf;
		}
		vis.reset();
		dij(i);
	}
	while (q--){
		int x, y;
		cin >> x >> y;
		int res = inf, lenx = vt[x].size(), leny = vt[y].size();
		for (int i = 0; i < lenx; ++i){
			for (int j = 0; j < leny; ++j){
				edge u = vt[x][i], v = vt[y][j];
				res = min(res, dis[u.v][v.v] + u.w + v.w);
			}
		}
		cout << res + w[x] + w[y] << "\n";
	}
	return 0;
} 
/*
15:25
不是，读题花费时间严格最长。 
1.072s。 
我真气笑了。。 
相信一手评测机。 
不是哥们，subway7 d<=2，？
那我不完蛋了。
那咋改。
加 bitset 怎么还变慢了。 
不是，理论最大只有 4e7 啊，为啥这么慢，是机器的问题吗。我没招了/xk/ll 
坏事了。 
*/
