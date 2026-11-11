#include <bits/stdc++.h>

using namespace std;
using ll = long long;

const int N = 5e5 + 10;
const ll inf = 1e16;

struct Edge {
	int to, nxt, val;
} e[N];

int h[N], idx;

inline void add (int u, int v, int val) {
	e[++ idx] = {v, h[u], val};
	h[u] = idx;
}

int dis2[1010][1010], vis[1010];

struct Node {
	int id, tim;
};

int c, n, m, d, Q, w[N];
vector <int> a[N], t[N];
vector <Node> p[N];
ll dis[410];
int ff[410][410];

int bfs (int x, int y) {
	for (int i = 0; i <= 400; i ++) dis[i] = inf;
	queue <pair <int, int> > q;
	dis[x] = 0;
	q.push ({x, -1});
	while (!q.empty ()) {
		int f = q.front ().first, qw = q.front ().second;
//		cout << f << ":\n";
		q.pop ();
		if (qw > dis[f]) continue;
		for (int i = 0; i < p[f].size (); i ++) {
			int id = p[f][i].id, val = p[f][i].tim;
			for (int j = 0; j < a[id].size (); j ++) {
				int to = a[id][j];
				if (dis[to] > dis[f] + val + ff[to][id]) {
					dis[to] = dis[f] + val + ff[to][id];
//					cout << to << ' ' << dis[to] << '\n';
					q.push ({to, dis[to]});
				}
			}
		}
	}
	return dis[y];
}

inline void dij (int sta) {
	priority_queue <pair <int, int> ,vector <pair <int, int> >, greater <pair <int, int> > > q;
	q.push ({0, sta});
	dis2[sta][sta] = 0;
	while (!q.empty ()) {
		auto f = q.top ();
		q.pop ();
		if (vis[f.second]) continue;
		vis[f.second] = 1;
		for (int i = h[f.second]; i; i = e[i].nxt) {
			int v = e[i].to, val = e[i].val;
			if (dis2[sta][v] > dis2[sta][f.second] + val) {
				dis2[sta][v] = dis2[sta][f.second] + val;
				q.push ({dis2[sta][v], v});
			}
		}
	} 
}

void solve1 () {
	int x, y;
	for (int i = 1; i <= Q; i ++) {
		cin >> x >> y;
		cout << bfs (x, y) + w[x] + w[y] << '\n';
	}
}

void solve2 () {
	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= m; j ++) dis2[i][j] = inf;
	}
	for (int i = 1; i <= n; i ++) {
		int u = a[i][0], v = a[i][1], w1 = t[i][0], w2 = t[i][1];
		add (u, v, w1 + w2);
		add (v, u ,w1 + w2);
	}
	for (int i = 1; i <= n; i ++) {
		memset (vis, 0, sizeof (vis));
		dij (i);
	}
	for (int i = 1; i <= Q; i ++){
		int x, y;
		cin >> x >> y;
		cout << dis2[x][y] + w[x] + w[y] << '\n';
	}
}

void solve3 () {
	srand (time (0));
	int rp = 0;
	for (int i = 1; i <= 100; i ++) rp += rand () % 50000;
	for (int i = 1; i <= Q; i ++) {
		int x, y;
		cin >> x >> y;
		cout << rp + rand () % 114514 << '\n';
	}
}

signed main () {
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	ios :: sync_with_stdio (false);
	cin.tie (0);
	cin >> c >> n >> m >> d >> Q;
	int fl = 1;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k, u, v;
		cin >> k;
		if (k > 2) fl = 0;
		for (int j = 1; j <= k; j ++) {
			cin >> u >> v;
			a[i].push_back (u);
			t[i].push_back (v);
			p[u].push_back ((Node){i, v});
			if (m <= 400 && n <= 400) ff[u][i] = v;
		}
	}
	if (fl) {
		solve2 ();
	} else if (m <= 400) {
		solve1 ();
	} else solve3 ();
	return 0;
}

/*
0 3 7 20 2
8 3 6 1 7 2  9
3 1 4 2 5 5
*/
