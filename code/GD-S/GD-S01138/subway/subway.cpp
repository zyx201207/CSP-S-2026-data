#include<bits/stdc++.h>
#define int long long
#define INF 0x3f3f3f3f
#define endl '\n'

using namespace std;

const int N = 505;
int m, n, d, q, p[N], dist[N][N], vis[N];
//int T;
struct Edge {
	int v, w;
};
vector<Edge> ed[N];

inline void dij(int s) {
	memset(vis, false, sizeof vis);
	
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > q;
	q.push({0, s});
	dist[s][s] = 0;
	while (!q.empty()) {
		int dis = q.top().first, u = q.top().second;
		q.pop();
		if (vis[u]) continue;
		vis[u] = true;
		for (int i = 0; i < ed[u].size(); i++) {
			int v = ed[u][i].v, w = ed[u][i].w;
			if (dist[s][u] + w < dist[s][v]) {
				dist[s][v] = dist[s][u] + w;
				q.push({dist[s][v], v});
			}
		}
	} 
}
//inline void bfs(int x, int tar) {
//	queue<int> q, qa;
//	memset(vis, false, sizeof vis);
//	vis[x] = true;
//	q.push(x), qa.push(0);
//	while (!q.empty()) {
//		int topu = q.front(), topa = qa.front();
//		q.pop(), qa.pop();
//		if (topu == tar) {
//			cout << topa * T + p[x] + p[tar] << endl;
//			return ;
//		}
//		for (int i = 0; i < ed[topu].size(); i++) {
//			int v = ed[topu][i].v;
//			if (vis[v]) continue;
//			vis[v] = true, q.push(v), qa.push(topa + 1);
//		}
//	}
//}
//inline void solveB() {
//	while (q--) {
//		int x, y;
//		cin >> x >> y;
//		bfs(x, y);
//	}
//}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);
	int c;
	cin >> c >> m >> n >> d >> q;
	for (int i = 1; i <= n; i++) {
		cin >> p[i];
	}
	for (int i = 1; i <= m; i++) {
		int k;
		vector<pair<int, int> > tmp;
		cin >> k;
//		T = sttim;
		for (int i = 1; i <= k; i++) {
			int t, tt; cin >> t >> tt; tmp.push_back({t, tt});
		}
		if (c <= 3) {
			for (int i = 0; i < tmp.size(); i++) {
				for (int j = i + 1; j < tmp.size(); j++) {
					ed[tmp[i].first].push_back({tmp[j].first, tmp[i].second + tmp[j].second});
					ed[tmp[j].first].push_back({tmp[i].first, tmp[i].second + tmp[j].second});
				}
			}
			continue;
		}
		for (int i = 0; i < tmp.size(); i++) {
			ed[tmp[i].first].push_back({tmp[0].first, tmp[i].second + tmp[0].second});
			ed[tmp[0].first].push_back({tmp[i].first, tmp[i].second + tmp[0].second});
		}
	}
//	if (c >= 12 && c <= 19) {
//		solveB();
//		return 0;
//	}
	memset(dist, 0x3f, sizeof dist);
	for (int i = 1; i <= n; i++) {
		dij(i);
	}
	while (q--) {
		int x, y;
		cin >> x >> y;
		cout << dist[x][y] + p[x] + p[y] << endl;
	}
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

*/
