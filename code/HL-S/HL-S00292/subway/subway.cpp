#include <bits/stdc++.h>
#define int long long
using namespace std;
/*

这里有严重问题！！！！！！开495能过，501过不了，505过不了？？？？？
放Linux上测一下。Linux直接不给我编译了，笑死。。。可能这是出题人故意的，t数组应当换个写法！ 
换成vector就过了，神了！ 
 
*/
const int N = 505, M = 5e5 + 5, inf = 1e18;
int c, n, m, d, q;
int w[M];
int deg[M]; // deg[i]: 有多少地铁线连接节点 i？ 
vector<pair<int, int> > t[M]; // t[i][MyIndex] = {j, k} 表示 第 i 个站点，进入第 j 条地铁线的站厅，所需时间为 k 
int dis[N][N]; // 两条地铁线之间互相彼此到达的最短用时. 它应该有一个初始值 
void buildGraph() {
	for (int x = 1; x <= n; x++) {
		for (int y = 1; y <= n; y++) {
			dis[x][y] = inf;
		}
	}
	for (int x = 1; x <= n; x++) {
		dis[x][x] = 0;
	}
	for (int i = 1; i <= m; i++) {
		for (pair<int, int> tmpX : t[i]) {
			int X = tmpX.first, tX = tmpX.second;
			for (pair<int, int> tmpY : t[i]) {
				int Y = tmpY.first, tY = tmpY.second;
				if (X == Y) continue;
				dis[X][Y] = min(dis[X][Y], tX + tY);
				dis[Y][X] = min(dis[Y][X], tX + tY);
			}
		}
	}
	for (int u = 1; u <= n; u++) {
		for (int v = 1; v <= n; v++) {
			for (int k = 1; k <= n; k++) {
				dis[u][v] = min(dis[u][v], dis[u][k] + dis[k][v]);
			}
		}
	}
}
signed main() {
	cin.tie(0) -> sync_with_stdio(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, y; cin >> x >> y;
			t[x].push_back({i, y});
		}
	}
	buildGraph();
//	cout << "Dis(1, 2) = " << dis[1][2] << '\n';
	while (q--) {
		int u, v; cin >> u >> v;
		int ansInner = inf, ansOuter = 0, candX = 0, candY = 0;
		for (pair<int, int> tmpU : t[u]) {
			int U = tmpU.first, tU = tmpU.second;
			for (pair<int, int> tmpV : t[v]) {
				int V = tmpV.first, tV = tmpV.second;
				if (dis[U][V] < ansInner) {
					ansInner = dis[U][V];
					candX = tU;
					candY = tV;
				}
			}
		}
		ansOuter = w[u] + candX + candY + w[v];
//		cout << "Cur ansInner = " << ansInner << ", Cur ansOuter = " << ansOuter << '\n';
//		cout << "Ans = ";
		cout << ansInner + ansOuter << '\n';
	}
	return 0;
}

