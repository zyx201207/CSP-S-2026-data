#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair < int, ll > pii;

const int N = 5e5 + 500 + 10, M = 500 + 10;
int n, m, q;
ll w[N], dis[N], dw[M][M]; bool vis[N];
vector < pii > G[N];
struct node {
	int to; ll d;
	bool operator < (const node & rhs) const {
		return d < rhs.d;
	}
};
const ll inf = 1e16;

void dijkstra(int s) {
	priority_queue < node > q;
	for (int i = 1; i <= n + m; i ++) vis[i] = 0, dis[i] = inf;
	dis[s] = 0; q.push(node{s, 0});
	while (!q.empty()) {
		auto tmp = q.top(); q.pop();
		int u = tmp.to;
		if (vis[u]) continue ;
		for (auto x : G[u]) {
			int v = x.first; ll w = x.second;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				q.push(node{v, dis[v]});
			}
		}
	}
}

void solve1() {
	while (q --) {
		int x, y; cin >> x >> y;
		dijkstra(x + n);
		cout << w[x + n] + w[y + n] + dis[y + n] << "\n";
	}
}

void solve2() {
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j <= n; j ++) {
			dw[i][j] = inf;
			if (i == j) dw[i][j] = 0;
		}
	}
	for (int i = n + 1; i <= m + n; i ++) {
		for (int j = 0; j < (int)G[i].size() - 1; j ++) {
			for (int k = j + 1; k < (int)G[i].size(); k ++) {
				int u = G[i][j].first, v = G[i][k].first; ll w1 = G[i][j].second, w2 = G[i][k].second;
//				cout << "i = " << i << " u = " << u << " v = " << v << "\n";
				dw[u][v] = dw[v][u] = min(dw[u][v], w1 + w2);
			}
		}
	}
	for (int k = 1; k <= n; k ++) 
		for (int i = 1; i <= n; i ++) {
			if (dw[i][k] >= inf) continue ;
			for (int j = 1; j <= n; j ++) {
				if (dw[j][k] >= inf) continue ;
				dw[i][j] = min(dw[i][j], dw[i][k] + dw[j][k]);
			}
		}
	while (q --) {
		int x, y; cin >> x >> y;
		ll minn = inf;
		for (auto z1 : G[x + n]) {
			for (auto z2 : G[y + n]) {
				int u = z1.first, v = z2.first;
				minn = min(minn, dw[u][v] + z1.second + z2.second);
			}
		}
		cout << minn + w[x + n] + w[y + n] << "\n";
	}
}

int main() {
	
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	
	int c, d;
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i ++) cin >> w[i + n];
	for (int i = 1; i <= n; i ++) {
		int k; cin >> k;
		for (int j = 1; j <= k; j ++) {
			int u; ll w; 
			cin >> u >> w;
			G[u + n].push_back(make_pair(i, w));
			G[i].push_back(make_pair(u + n, w));
		}
	}
	if (c <= 8) {
		solve1();
		return 0;
	} else solve2();
	
	return 0;
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2
*/
