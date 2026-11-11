#include <bits/stdc++.h>

#define int long long

const int N = 1e3 + 7;

std::vector<std::pair<int, int> > G[N];
//std::map<int, int> t[N];

bool mark[N][501];
int f[N][501], t[N][501], w[N], k[N], ans[N];
int Case, n, m, d, Q;

struct Node {
	int val, x, type;
	bool operator < (const Node &rhs) const {
		return val < rhs.val;
	}
};

void dijkstra(int S) {
	std::priority_queue<Node> Q;
	for (int i = 1; i <= m; i ++) ans[i] = 1e18;
	for (int i = 1; i <= m; i ++) for (int _ = 0; _ <= n; _ ++) f[i][_] = 1e18, mark[i][_] = 0;
	Q.push((Node){ f[S][0] = 0, S, 0 });
	while (!Q.empty()) {
		int x = Q.top().x, type = Q.top().type; Q.pop();
//		auto [Temp, x, type] = Q.top(); Q.pop();
		ans[x] = std::min(ans[x], f[x][type] + t[x][type]);
//		printf("##f[%lld] = %lld %lld\n", x, f[x], type);
		if (mark[x][type]) continue; mark[x][type] = 1;
		for (int i = 0; i < (int)G[x].size(); i ++) {
//			printf("%lld %lld\n", y, nxtT);
			int y = G[x][i].first, nxtT = G[x][i].second, Nxt = f[x][type]; 
			if (nxtT != type) Nxt += t[x][type] + t[x][nxtT];
//			printf("f[%lld] = %lld, %lld   turn to   %lld\n", y, f[y], type, nxtT);
			if (f[y][nxtT] > Nxt) Q.push((Node){ -(f[y][nxtT] = Nxt), y, nxtT });
		}
	}
}

bool check() { for (int i = 1; i <= n; i ++) if (k[i] > 2) return 0; return 1; }

namespace Subtask {
	struct Edge {
		int x, y, val;
		bool operator < (const Edge &rhs) const {
			return val < rhs.val;
		}
	} E[N * N];
	std::vector<std::pair<int, int> > tr[N];
	int fa[N], dis[N], siz[N], hson[N], dep[N], cnt = 0;
	int top[N];
	int F(int x) { return fa[x] == x ? x : fa[x] = F(fa[x]); }
	void dfs1(int x, int Fa) {
		dep[x] = dep[fa[x] = Fa] + 1; siz[x] = 1;
		for (int _ = 0; _ < tr[x].size(); _ ++) {
			int y = tr[x][_].first, w = tr[x][_].second;
			if (y != Fa) {
				dis[y] = dis[x] + w; dfs1(y, x);
				siz[x] += siz[y]; if (siz[y] > siz[hson[x]]) hson[x] = y; 
			}
		}
	}
	void dfs2(int x, int Top) {
		top[x] = Top; if (hson[x]) dfs2(hson[x], Top);
		for (int _ = 0; _ < tr[x].size(); _ ++) {
			int y = tr[x][_].first;
			if (y != fa[x] && y != hson[x]) dfs2(y, y);
		}
	}
	int LCA(int x, int y) {
		for (; top[x] != top[y]; x = fa[top[x]]) if (dep[top[x]] < dep[top[y]]) std::swap(x, y);
		return dep[x] < dep[y] ? x : y;
	}
	void MAIN() {
		for (int i = 1; i <= m; i ++) {
			fa[i] = i;
			for (int _ = 0; _ < G[i].size(); _ ++)
				E[++ cnt] = (Edge){ i, G[i][_].first, t[i][G[i][_].second] + t[G[i][_].first][G[i][_].second] };
		}
		std::sort(E + 1, E + cnt + 1);
		for (int i = 1, sum = 1; i <= cnt; i ++) {
			int x = F(E[i].x), y = F(E[i].y);
			if (x != y) {
				sum ++, fa[x] = y;
				tr[E[i].x].push_back({ E[i].y, E[i].val }), 
				tr[E[i].y].push_back({ E[i].x, E[i].val });
			}
		}
		for (int i = 1; i <= m; i ++) fa[i] = 0;
		dfs1(1, 0); dfs2(1, 1);
		for (int x, y; Q --; ) {
			scanf("%lld%lld", &x, &y);
			printf("%lld\n", dis[x] + dis[y] + w[x] + w[y] - 2 * dis[LCA(x, y)]);
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout); 

	scanf("%lld%lld%lld%lld%lld", &Case, &n, &m, &d, &Q);
	for (int i = 1; i <= m; i ++) scanf("%lld", &w[i]);
	for (int i = 1; i <= n; i ++) {
		scanf("%lld", &k[i]);
		for (int j = 1, lst = -1, x; j <= k[i]; j ++) {
			scanf("%lld", &x), scanf("%lld", &t[x][i]);
			if (~lst) G[lst].push_back({ x, i }), G[x].push_back({ lst, i }); lst = x;
		}
	}
	if (check()) return Subtask::MAIN(), 0;
	for (int x, y; Q --; ) {
		scanf("%lld%lld", &x, &y);
		dijkstra(x);
		printf("%lld\n", w[x] + w[y] + ans[y]);
	}
	
	return 0;
} 
