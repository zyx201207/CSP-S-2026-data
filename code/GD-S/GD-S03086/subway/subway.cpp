#include <cstdio>
#include <queue>
#include <cstring>
#include <vector>
#define int long long

inline int swap(int &x, int &y) { int temp = x; x = y, y = temp; }

const int N = 1e6 + 1;
const int Q = 1e5 + 1;

struct edge {
	int u, w;
	bool operator<(const edge &e) const { return w > e.w; }
};

struct task { int v, id; };

int ipt, path, n, dir, que, cntd, ans[Q];
int head[N], nxt[N << 1], to[N << 1], wgt[N << 1], tot;
int val[N], dis[N];
bool vis[N];
std::priority_queue<edge> pq;
std::vector<task> ques[Q];

inline void add_edge(int u, int v, int w) { nxt[++tot] = head[u], to[tot] = v, wgt[tot] = w, head[u] = tot; }

inline void dijkstra(int st) {
	memset(dis, 0x3f, sizeof dis); memset(vis, 0, sizeof vis);
	dis[st] = 0; pq.push({st, 0});
	while (!pq.empty()) {
		int u = pq.top().u, uw = pq.top().w; pq.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (int e = head[u], v, w; e; e = nxt[e]) {
			v = to[e], w = wgt[e]; if (uw + w > dis[v]) continue;
			dis[v] = uw + w; if (!vis[v]) pq.push({v, dis[v]});
		}
	}
}

/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17
*/

signed main() {
	std::freopen("subway.in", "r", stdin);
	std::freopen("subway.out", "w", stdout);
	scanf("%lld %lld %lld %lld %lld", &ipt, &path, &n, &dir, &que);
	cntd = n;
	for (int i = 1; i <= n; i++) scanf("%lld", &val[i]);
	for (int i = 1; i <= path; i++) {
		int k; scanf("%lld", &k);
		for (int j = 1; j <= k; j++) {
			int sub, tim; scanf("%lld %lld", &sub, &tim);
			add_edge(++cntd, sub, tim); add_edge(sub, cntd, tim);
			if (j > 1) { add_edge(cntd, cntd - 1, 0); add_edge(cntd - 1, cntd, 0); }
		}
	} for (int i = 1; i <= que; i++) {
		int x, y; scanf("%lld %lld", &x, &y); if (x > y) swap(x, y);
		ques[x].push_back({y, i});
	} for (int i = 1; i <= n; i++) {
		if (ques[i].empty()) continue; dijkstra(i);
		for (task j : ques[i]) ans[j.id] = dis[j.v] + val[i] + val[j.v];
	} for (int i = 1; i <= que; i++) printf("%lld\n", ans[i]);
	return 0;
}

