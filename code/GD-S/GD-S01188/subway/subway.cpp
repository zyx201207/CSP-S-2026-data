#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e6;
int c, n, m, d, q, w[N], head[N], cnt, dis[N], ans[N];
bool vis[N];
queue<int> dui;
struct edge {
	int to, nxt, val;
} e[N << 1];
struct problem {
	int s, t, id;
	
	bool operator<(problem x) {
		if (s != x.s) return s < x.s;
		else return t < x.t;
	}
} que[N];

void add(int u, int v, int w) {
	e[++cnt] = {v, head[u], w};
	head[u] = cnt;
}

void SPFA(int s) {
	memset(vis, 0, sizeof vis);
	memset(dis, 0x3f, sizeof dis);
	while (!dui.empty()) dui.pop();
	dui.push(s);
	dis[s] = 0, vis[s] = 1;
	while (!dui.empty()) {
		int u = dui.front();
		dui.pop();
		vis[u] = 0;
		for (int i = head[u], v, w; i; i = e[i].nxt) {
			v = e[i].to, w = e[i].val;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!vis[v]) dui.push(v);
			}
		}
	}
}

signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	scanf("%lld%lld%lld%lld%lld", &c, &n, &m, &d, &q);
	for (int i = 1; i <= m; ++i) scanf("%lld", &w[i]);
	for (int i = 1, k; i <= n; ++i) {
		scanf("%lld", &k);
		for (int j = 1, v, w; j <= k; ++j) {
			scanf("%lld%lld", &v, &w);
			add(i + m, v, w), add(v, i + m, w);
		}
	}
	for (int i = 1; i <= q; ++i) {
		scanf("%lld%lld", &que[i].s, &que[i].t);
		que[i].id = i;
	}
	sort(que + 1, que + 1 + q);
	for (int i = 1; i <= q; ++i) {
		if (i == 1 || que[i].s != que[i - 1].s) SPFA(que[i].s);
		ans[que[i].id] = dis[que[i].t] + w[que[i].s] + w[que[i].t];
	}
	for (int i = 1; i <= q; ++i) printf("%lld\n", ans[i]);
	return 0;
}
