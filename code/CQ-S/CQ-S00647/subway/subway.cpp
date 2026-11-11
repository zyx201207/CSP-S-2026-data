#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1e6 + 10;
//地铁站数为 5e5 + 10

//注意边权爆 int
vector<pair<int, long long> > v[M], edge[N];   //缩点与大厅的，缩点与缩点的 
vector<int> g[N], k[M];   //缩点存了哪些点，地铁站有几条线路
long long val[M];
int c, n, m, d, q;
struct qu {
	int x, y, id;
	inline bool operator < (const qu a) const {
		if (x != a.x) {
			return x < a.x;
		}
		return id < a.id;
	}
} a[M];
long long ans[M], dist[N];
bool vis[N];

void init() {
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> val[i];
	}
	for (int i = 1; i <= n; i++) {
		int o;
		cin >> o;
		for (int j = 1; j <= o; j++) {
			int a, t;
			cin >> a >> t;
			//站厅与缩点建立双向边。
			v[a + n].push_back({i, t});
			v[i].push_back({a + n, t});
			//路线内部建立缩点
			g[i].push_back(a);
			//
			k[a].push_back(i);
		}
		sort(v[i].begin(), v[i].end());
		sort(g[i].begin(), g[i].end());
	}
	for (int i = 1 + n; i <= m + n; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			for (int k = j + 1; k < v[i].size(); k++) {
				edge[v[i][j].first].push_back({v[i][k].first, v[i][j].second + v[i][k].second});
				edge[v[i][k].first].push_back({v[i][j].first, v[i][j].second + v[i][k].second});
			}
		}
	}
}

//----------------------
struct node {
	long long val;
	int x;
};
struct cmp {
	inline bool operator () (const node a, const node b) {
		return a.val > b.val;
	}
};
void dijkstra(int x) {
	for (int j = 1; j <= n; j++) {
		dist[j] = 1e18;
		vis[j] = false;
	}
	priority_queue<node, vector<node>, cmp> q;
	for (int j = 0; j < k[x].size(); j++) {
		int u = k[x][j];
		int ll = 0, rr = v[u].size() - 1;
		while (ll < rr) {
			int mid = (ll + rr + 1) >> 1;
			if (v[u][mid].first <= x + n) {
				ll = mid;
			} else {
				rr = mid - 1;
			}
		}
		q.push({v[u][ll].second, k[x][j]});
		dist[k[x][j]] = v[u][ll].second;
	}
	//开始 dijkstra 
	while (!q.empty()) {
		node t = q.top();
		q.pop();
		if (vis[t.x]) {
			continue;
		}
		vis[t.x] = true;
		for (int j = 0; j < edge[t.x].size(); j++) {
			int u = edge[t.x][j].first;
			long long w = edge[t.x][j].second;
			if (dist[u] > dist[t.x] + w) {
				dist[u] = dist[t.x] + w;
				q.push({dist[u], u});
			}
		}
	}
}
void calc() {
	//j + n 为地铁站 j 的站厅，i 为第 i 号线路（缩点 i。
	//每个缩点跑一边 dij
	for (int i = 1; i <= q; i++) {
		long long res = 1e18;
		if (a[i].x != a[i - 1].x) {
			dijkstra(a[i].x);
		}

		//算出来了从 a[i].x 上地铁的所有线路的最短路
		for (int j = 0; j < k[a[i].y].size(); j++) {
			int u = k[a[i].y][j];   //终点的所有线路
			int ll = 0, rr = v[u].size() - 1;
			while (ll < rr) {
				int mid = (ll + rr + 1) >> 1;
				if (v[u][mid].first <= a[i].y + n) {
					ll = mid;
				} else {
					rr = mid - 1;
				}
			}
			res = min(res, dist[u] + v[u][ll].second);
		}
		ans[a[i].id] = res + val[a[i].x] + val[a[i].y];
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	init();
	for (int i = 1; i <= q; i++) {
		cin >> a[i].x >> a[i].y;
		a[i].id = i;
	}
	sort(a + 1, a + 1 + q);
	calc();
	for (int i = 1; i <= q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}
