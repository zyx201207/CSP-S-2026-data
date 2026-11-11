#include <bits/stdc++.h>
using namespace std;

namespace OI {

#define int long long
#define endl "\n"

int c, n, m, d, q;

namespace force {

constexpr int maxn = 2e6+5;

struct edge {
	int to, w;
};
vector<edge> graph[maxn];

int entrance[maxn];

inline int platform(int i) {
	return i * (d + 1);
}
int cnt[maxn];
inline int line(int i) {
	return i * (d + 1) + cnt[i];
}

int dist[maxn];
struct stat {
	int id, w;
};
struct cmp {
	bool operator() (stat a, stat b) {
		return a.w > b.w;
	}
};
priority_queue<stat, vector<stat>, cmp> heap;
void Dijkstra(int s) {
	memset(dist, 0x3f, sizeof dist);
	dist[s] = 0;
	heap.push({s, 0});
	while (!heap.empty()) {
		int u = heap.top().id, dis = heap.top().w;
		heap.pop();
		if (dist[u] != dis)
			continue;
		for (auto e : graph[u]) {
			int v = e.to;
			if (dist[v] > dis + e.w) {
				dist[v] = dis + e.w;
				heap.push({v, dist[v]});
			}
		}
	}
}

struct query {
	int u, v, id;
};
map<int, vector<query>> queries;
int ans[maxn];

void solve() {
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> entrance[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		vector<int> a(k + 1);
		for (int j = 1; j <= k; j++) {
			cin >> a[j];
			++cnt[a[j]];
			int t;
			cin >> t;
			graph[platform(a[j])].push_back({line(a[j]), t});
			graph[line(a[j])].push_back({platform(a[j]), t});
			if (j != 1)
				graph[line(a[j])].push_back({line(a[j - 1]), 0}),
				graph[line(a[j - 1])].push_back({line(a[j]), 0});
		}
	}
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		queries[u].push_back({u, v, i});
	}
	for (auto q : queries) {
		Dijkstra(platform(q.first));
		for (query que : q.second) {
			ans[que.id] = dist[platform(que.v)] + entrance[q.first] + entrance[que.v];
		}
	}
	for (int i = 1; i <= q; i++)
		cout << ans[i] << endl;
}

}

namespace linear {
	
constexpr int maxn = 5e5+5;

int n, m, d, q;
int entrance[maxn];
int down[maxn][3];

map<int, int> lines[3];

int trans;

void solve() {
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> entrance[i];
	}
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			lines[i][a] = t;
			down[a][i] = t;
		}
	}
	trans = LONG_LONG_MAX;
	for (int i = 1; i <= m; i++) {
		if (lines[1].count(i) && lines[2].count(i))
			trans = min(trans, lines[1][i] + lines[2][i]);
	}
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		int base = entrance[u] + entrance[v];
		int ans = LONG_LONG_MAX;
		if (lines[1].count(u) && lines[1].count(v))
			ans = min(ans, base + down[u][1] + down[v][1]);
		if (lines[1].count(u) && lines[2].count(v))
			ans = min(ans, base + down[u][1] + down[v][2] + trans);
		if (lines[2].count(u) && lines[1].count(v))
			ans = min(ans, base + down[u][2] + down[v][1] + trans);
		if (lines[2].count(u) && lines[2].count(v))
			ans = min(ans, base + down[u][2] + down[v][2]);
		cout << ans << endl;
	}
	
}

}

namespace specialB {

constexpr int maxn = 5e5+5;

int f[505][505];
vector<int> to[maxn];

int entrance[maxn];

int T;

inline int query(int u, int v) {
	int ans = LONG_LONG_MAX;
	for (int x : to[u])
		for (int y : to[v])
			ans = min(ans, f[x][y]);
	return ans + entrance[u] + entrance[v] + 2 * T;
}

void solve() {
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> entrance[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = LONG_LONG_MAX / 2;
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a;
			cin >> a >> T;
			for (int x : to[a])
				f[i][x] = min(f[i][x], T * 2),
				f[x][i] = min(f[x][i], T * 2);
			to[a].push_back(i);
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		cout << query(u, v) << endl;
	}
}
	
}

namespace solution {

constexpr int maxn = 5e5+5;

int f[505][505];
map<int, int> to[maxn];

int entrance[maxn];

inline int query(int u, int v) {
	int ans = LONG_LONG_MAX;
	for (auto x : to[u])
		for (auto y : to[v])
			ans = min(ans, f[x.first][y.first] + x.second + y.second);
	return ans + entrance[u] + entrance[v];
}

void solve() {
	cin >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++) {
		cin >> entrance[i];
	}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			f[i][j] = LONG_LONG_MAX / 2;
	for (int i = 1; i <= n; i++)
		f[i][i] = 0;
	for (int i = 1; i <= n; i++) {
		int k;
		cin >> k;
		for (int j = 1; j <= k; j++) {
			int a, t;
			cin >> a >> t;
			for (auto p : to[a])
				f[i][p.first] = min(f[i][p.first], t + p.second),
				f[p.first][i] = min(f[p.first][i], t + p.second);
			to[a][i] = t;
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		int u, v;
		cin >> u >> v;
		cout << query(u, v) << endl;
	}
}
	
}

void main() {
	cin >> c;
	switch (c) {
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			force::solve();
			break;
		case 12:
		case 13:
		case 14:
		case 15:
		case 16:
		case 17:
		case 18:
		case 19:
			specialB::solve();
			break;
		case 20:
		case 21:
			linear::solve();
			break;
		default:
			solution::solve();
			break;
	}
}

#undef int
#undef endl

}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin.tie(0), cout.tie(0);
	ios::sync_with_stdio(0);
	
	OI::main();
	
	return 0;
}
