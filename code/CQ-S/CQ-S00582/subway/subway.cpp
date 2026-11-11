#include <bits/stdc++.h>
#define int long long int
using namespace std;

const int MAXN = 505, MAXK = 5e5 + 5, MAXQ = 1e5 + 5, INF = 1e18;

int op, n, m, d, q, w[MAXK], dis[MAXN][MAXN], cnt, lst[MAXN], len;

struct Node {
	int x, y, z, nxt;
}ls[MAXN * MAXN];

vector<pair<int, int> > g[MAXK];

void add(int x, int y, int z) {
	ls[++len].x = x, ls[len].y = y, ls[len].z = z, ls[len].nxt = lst[x], lst[x] = len;
}

struct P {
	int x, dis;
	P (int _x, int _dis) {
		x = _x, dis = _dis; 
	}
};

bool operator < (P a, P b) {
	return a.dis > b.dis;
}

priority_queue<P> pq;

void dij(int S) {
	for (int i = 1; i <= n; i++) dis[S][i] = INF;
	dis[S][S] = 0;
	pq.push(P(S, 0));
	while (!pq.empty()) {
		P t = pq.top(); pq.pop();
		for (int j = lst[t.x]; j; j = ls[j].nxt) {
			int y = ls[j].y;
			if (dis[S][y] > dis[S][t.x] + ls[j].z) {
				dis[S][y] = dis[S][t.x] + ls[j].z;
				pq.push(P(y, dis[S][y])); 
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false); cin.tie(0);
	cin >> op >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) cin >> w[i];
	cnt = m;
	for (int i = 1; i <= n; i++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j++) {
			int x, z; cin >> x >> z;
			g[x].push_back(make_pair(i, z));
		}
	}
	for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) dis[i][j] = INF;
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < g[i].size(); j++) {
			for (int k = j + 1; k < g[i].size(); k++) {
				int x = g[i][j].first, y = g[i][k].first, z = g[i][j].second + g[i][k].second;
//				cout << x << ' ' << y << '\n';
				dis[x][y] = dis[y][x] = min(dis[x][y], z);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			if (dis[i][j] >= INF) continue;
			add(i, j, dis[i][j]), add(j, i, dis[i][j]);
		}
	}
//	cout << dis[1][2] << '\n';
	for (int i = 1; i <= n; i++) dij(i);
//	q = 1;
	while (q--) {
		int x, y; cin >> x >> y;
		int ans = INF;
		for (auto i : g[x]) {
			for (auto j : g[y]) {
				ans = min(ans, dis[i.first][j.first] + j.second + i.second);
			}
		}
		cout << ans + w[x] + w[y] << '\n'; 
	}
	return 0;
}
/*

*/
