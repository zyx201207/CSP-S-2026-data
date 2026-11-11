#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 505, M = 5e5 + 5;
int c, n, m, d, q, w[M], a[N][N], t[N][N], k[N], dis[M];
bool vis[M];
struct edge {
	int v, id, w;
};
vector<edge> g[M];
struct node {
	ll u, dis, id;
	bool operator > (const node &other) const {
		return dis > other.dis;
	}
};
void dijkstra(int s) {
	memset(dis, 0x3f, sizeof dis);
	memset(vis, false, sizeof vis);
	//for (int i = 1; i <= n; i++) dis[s][i] = 0;
	priority_queue<node, vector<node>, greater<node>> q;
	q.push({s, 0});
	dis[s] = 0;
	while (!q.empty()) {
		int u = q.top().u, id = q.top().id; q.pop();
	//	cout << u << " " << dis[u] << '\n';
		if (vis[u]) continue;
		vis[u] = true;
		for (edge ed : g[u]) {
			int v = ed.v, w = ed.w, idd = ed.id;
//			if (u == 5 && v == 4) {
//				cout << "!!!";
//				cout << dis[u] << " " << dis[v] << '\n';
//			}
//			if (id == idd) {
//				if (dis[v] > dis[u] - t[id][mp[id][u]] + t[id][mp[id][v]]) dis[v] = dis[u] - t[id][mp[id][u]] + t[id][mp[id][v]];
//				q.push({v, dis[u] - t[id][mp[id][u]] + t[id][mp[id][v]], id});
//			}
			if (dis[v] > dis[u] + w) dis[v] = dis[u] + w, q.push({v, dis[v], id});
		}
	}
}
signed main() {
//	system("fc my.out subway5.ans");
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(nullptr);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	for (int i = 1; i <= n; i++) {
		cin >> k[i];
		int lst, lstw;
		for (int j = 1; j <= k[i]; j++) {
			cin >> a[i][j] >> t[i][j];
//			mp[i][a[i][j]] = i;
//			// t ÊÇÕ¾Ìüµ½Õ¾Ì¨£¡£¡£¡ 
//			if (j > 1) g[a[i][j]].push_back({lst, i, t[i][j] + lstw}), g[lst].push_back({a[i][j], i, t[i][j] + lstw});
//			lst = a[i][j], lstw = t[i][j];
		}
		for (int j = 1; j <= k[i]; j++) {
			for (int x = j + 1; x <= k[i]; x++) {
				g[a[i][j]].push_back({a[i][x], i, t[i][j] + t[i][x]});
				g[a[i][x]].push_back({a[i][j], i, t[i][j] + t[i][x]});
			}
		}
	}
	while (q--) {
		int s, t;
		cin >> s >> t;
		dijkstra(s);
//		for (int i = 1; i <= m; i++) {
//			cout << dis[i] << " ";
//		} 
//		cout << '\n';
		cout << dis[t] + w[s] + w[t] << '\n';
	}
	return 0;
}
//n=500?floyd????no, n is the number of line.
//what's the meaning of d <= 20??? zhuangya???? no, it isn't zhuangya....
/*
0 2 5 20 2

4 1 9 2 5

3 1 5 2 7 4 6

3 2 3 3 4 5 7

1 3

1 2

*/
// oh nooo!!! It seems to only accept 1-11, and it can get 44points.It's not good enough.
// 1 zhengjie 2.pianfen?????
// subway5:3s.
// oh no! building edge seems to be slow, but idk how to solve it!!! let's start brutes of t3 and t4
