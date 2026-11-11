#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;

const long long inf = 0x3f3f3f3f3f3f3f3f;
const int N = 2e5, M = 500, D = 20;

vector < pair <int, int> > Graph[N + M + 1];
long long dis[M + 1][N + M + 1];
bool vis[N + M + 1];
int w[N + 1];

void dijkstra(int start, int n) {
	memset(dis[start - n], 0x3f, sizeof(dis[start - n]));
	memset(vis, false, sizeof(vis));
	
	priority_queue < pair <int, int> > que;
	dis[start - n][start] = 0;
	que.push(make_pair(-dis[start - n][start], start));
	
	while (!que.empty()) {
		int u = que.top().second;
		que.pop();
		
		if (vis[u]) {
			continue;
		}
		vis[u] = true;
		
		for (int i = 0; i < (int)(Graph[u].size()); i++) {
			int v = Graph[u][i].first, w = Graph[u][i].second;
			if (dis[start - n][v] > dis[start - n][u] + w) {
				dis[start - n][v] = dis[start - n][u] + w;
				que.push(make_pair(-dis[start - n][v], v));
			}
		}
	}
	return ;
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int c, n, m, d, q;
	cin >> c >> m >> n >> d >> q;
	
	for (int i = 1; i <= n; i++) {
		cin >> w[i];
	}
	
	for (int i = 1; i <= m; i++) {
		int k;
		cin >> k;
		
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			Graph[a].push_back(make_pair(n + i, t));
			Graph[n + i].push_back(make_pair(a, t));
		}
	}
	
	for (int i = 1; i <= m; i++) {
		dijkstra(n + i, n);
	} 
	for (int i = 1; i <= q; i++) {
		int x, y;
		cin >> x >> y;
		
		long long res = inf;
		for (int j = 0; j < (int)(Graph[x].size()); j++) {
			int u = Graph[x][j].first, tu = Graph[x][j].second;
			res = min(res, dis[u - n][y] + tu);
		}
		cout << res + w[x] + w[y] << "\n";
	}
	
	return 0;
}
// 15:35 (3:35) 44pts 分层图+全源最短路 
// 17:13 (5:13) 或许 100pts? 
// 17:30 (5:30) 被卡空间了 qwq 
// 17:32 (5:32) 可以离线处理 
// 17:36 (5:36) 不行，要周围的所有 
// 17:45 (5:45) 好吧，最大开到2e5，预估60pts，希望能高一些吧 
