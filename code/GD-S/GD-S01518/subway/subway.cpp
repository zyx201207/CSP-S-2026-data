#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
const ll INF = 1e18;
int problem_id, n, m, d, Q;
int a[N];
int u, v, w, tot;
struct Graph {
	int to; ll w; int nxt;
} G[N];
int head[510], g_cnt;
void add(int u, int v, ll w) {
	G[++g_cnt] = {v, w, head[u]};
	head[u] = g_cnt;
}
vector<pair<int, int> > pt[N];
ll Gra[510][510], dis[510][510];
struct node {
	int v;
	ll w;
	bool operator < (const node &o) const {
		return w > o.w;
	} 
}; priority_queue<node> q;
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios :: sync_with_stdio(0);
	cin.tie(0);
	cin >> problem_id >> n >> m >> d >> Q;
	for (int i = 1; i <= m; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i) { 
		cin >> tot;
		while (tot--) {
			cin >> v >> w;
			pt[v].emplace_back(i, w);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			Gra[i][j] = INF;
		}
	}
	int len;
	for (int i = 1; i <= m; ++i) {
		len = pt[i].size();
		for (int j = 0; j < len; ++j) {
			for (int k = j + 1; k < len; ++k) {
				u = pt[i][j].first, v = pt[i][k].first;
				w = pt[i][j].second + pt[i][k].second;
				Gra[u][v] = min(Gra[u][v], 1ll * w);
			}
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = i + 1; j <= n; ++j) {
			add(i, j, Gra[i][j]);
			add(j, i, Gra[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			dis[i][j] = INF;
		}
	}
	for (int st = 1; st <= n; ++st) {
		dis[st][st] = 0;
		q.push({st, 0});
		while (!q.empty()) {
			int u = q.top().v; ll Dis = q.top().w;
			q.pop();
			if (Dis > dis[st][u]) continue;
			for (int i = head[u]; i; i = G[i].nxt) {
				int v = G[i].to; ll w = G[i].w;
				if (dis[st][v] > dis[st][u] + w) {
					dis[st][v] = dis[st][u] + w;
					q.push({v, dis[st][v]});
				}
			}
		}
	}
	int len1, len2;
	ll distan;
	while (Q--) {
		distan = 1e18;
		cin >> u >> v; len1 = pt[u].size(), len2 = pt[v].size();
		for (int i = 0; i < len1; ++i) {
			for (int j = 0; j < len2; ++j) {
				distan = min(distan, dis[pt[u][i].first][pt[v][j].first] + pt[u][i].second + pt[v][j].second);
			}
		}
		cout << distan + a[u] + a[v] << '\n';
	}
	return 0;
}

/*

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3
*/
