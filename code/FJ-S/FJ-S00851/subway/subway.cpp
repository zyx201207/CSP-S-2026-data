#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10, INF = 0x3f3f3f3f3f3f3f3fll;
int c, n, m, d, q, w[N];
struct node {
	int idx, v;
};
vector<node> g[N];
vector<pair<int, int> > e[N];
struct point {
	int opt;
	int to;  // opt = 1 : 在地铁站里 
	int fr, sub;  // opt = 2 : 在地铁上面 
	int v;  // 已经用的时间 
	bool operator>(const point a) const {
		return v > a.v;
	}
};
int dis[N], vis[N];
void Dijkstra(int st, int ed) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, 0, sizeof vis);
	priority_queue<point, vector<point>, greater<point> > q;
	q.push({1, st, 0, 0, 0});
	dis[st] = 0;
	while (!q.empty()) {
		auto tp = q.top();
		q.pop();
		int opt = tp.opt, to = tp.to, sub = tp.sub, v = tp.v;
		//cout << opt << " " << v << " ";
		if (opt == 1) {
			//cout << to << "\n";
			if (vis[to] == 1) {
				continue;
			}
			vis[to] = 1;
			for (auto it : g[to]) {
				// 上地铁
				int nt = it.idx, nv = it.v;
				q.push({2, 0, to, nt, dis[to] + nv});
			}
		}
		else {
			int fr = tp.fr;
			//cout << fr << " " << sub << "\n";
			for (auto it : e[sub]) {
				// 下地铁 
				int nt = it.first, nv = it.second;
				if (dis[nt] > v + nv) {
					dis[nt] = v + nv;
					q.push({1, nt, 0, 0, dis[nt]});
				}
			}
		}
	}
//	for (int i = 1;i <= m; i++) {
//		cout << dis[i] << " ";
//	}
//	cout << "\n";
	//cout << w[st] << " " << w[ed] << "\n";
	cout << dis[ed] + w[st] + w[ed] << "\n";
	//cout << "\n";
	return ;
}

signed main() {
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1;i <= m; i++) {
		cin >> w[i];
	}
	for (int i = 1;i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1;j <= k; j++) {
			int to, v;
			cin >> to >> v;
			g[to].push_back({i, v});
			e[i].push_back({to, v});
		}
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		Dijkstra(x, y);
	}
	return 0;
}
