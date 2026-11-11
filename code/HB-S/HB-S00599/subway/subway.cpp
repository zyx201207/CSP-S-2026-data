#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 5e5 + 5;
const int N = 505;
int c, n, m, d, q, w[M], dis[N + M];
int p[M], ps[M];
// p -> k, ps -> presum of Line_k;
struct Data {
	int f[30], rk[30]; // which Line and rk; 
	int ct;
} g[M]; // g_i -> the sta_i in which Line ans the rk;

int ed[N][N];
bool zl[N][M];

struct Edge {
	int v, w, nxt;
} e[M + N];
int head[N + M], cnt;

void add (int u, int v, int w) {
	++ cnt;
	e[cnt].v = v;
	e[cnt].w = w;
	e[cnt].nxt = head[u];
	head[u] = cnt;
}

// =========================================
struct H {
	int id, val;
} h[N + M + M];
int siz;

void put (H x) {
	h[++ siz] = x;
	int so = siz;
	while (so != 1) {
		int fa = so / 2;
		if (h[fa].val <= h[so].val) break;
		swap (h[fa], h[so]);
		so /= 2;
	}
}

H qry () {
	H res = h[1];
	h[1] = h[siz --];
	int fa = 1;
	while (fa * 2 <= siz) {
		int so = fa * 2;
		if (so < siz && h[so + 1].val <= h[so].val) so ++;
		if (h[fa].val <= h[so].val) break;
		swap (h[fa], h[so]);
		fa = so;
	}
	return res;
}
// =========================================
int dij (int st, int end) {
	dis[st] = 0;
	H nw;
	nw.id = st;
	nw.val = 0;
	put (nw);
	int ans = 1e16;
	while (siz) {
		H pos = qry ();
		int u = pos.id;
//		cout << "ewrgwtreg " << pos.id << "\n"; 
//		cout << u << " " << pos.val << "\n";
		if (u <= 500 && zl[u][end]) {
			for (int i = 1; i <= g[end].ct; i ++) {
				if (g[end].f[i] != u) continue;
				ans = min (ans, pos.val + p[ps[u - 1] + g[end].rk[i]]);
				break;
			}
		}
		for (int i = head[u]; ~i; i = e[i].nxt) {
			int v = e[i].v;
			if (dis[v] <= pos.val + e[i].w) continue;
			dis[v] = pos.val + e[i].w;
			H ne;
			ne.id = v, ne.val = dis[v];
			put (ne);
		}
	}
	return ans;
}

signed main () {
	ios :: sync_with_stdio (0);
	cin.tie (0); cout.tie (0);
	
	freopen ("subway.in", "r", stdin);
	freopen ("subway.out", "w", stdout);
	
	memset (head, -1, sizeof head);
	
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= n; i ++) for (int j = 1; j <= n; j ++) ed[i][j] = 1e16;
	for (int i = 1; i <= m; i ++) cin >> w[i];
	for (int i = 1; i <= n; i ++) {
		int k;
		cin >> k;
		ps[i] = ps[i - 1] + k;
		for (int j = 1; j <= k; j ++) {
			int a, t;
			cin >> a >> t;
			p[ps[i - 1] + j] = t;
			g[a].ct ++;
			g[a].f[g[a].ct] = i;
			g[a].rk[g[a].ct] = j;
			zl[i][a] = true;
		}
	}

	for (int i = 1; i <= m; i ++) {
		for (int j = 1; j <= g[i].ct; j ++)
		for (int k = 1; k <= g[i].ct; k ++) {
			if (j == k) continue;
			int u = g[i].f[j], v = g[i].f[k];
			int w = p[ps[u - 1] + g[i].rk[j]] + p[ps[v - 1] + g[i].rk[k]];
			ed[u][v] = min (ed[u][v], w);
			ed[v][u] = min (ed[v][u], w);
		}
		for (int j = 1; j <= g[i].ct; j ++) {
			int id = ps[g[i].f[j] - 1] + g[i].rk[j];
			add (N + i, g[i].f[j], w[i] + p[id]);
		}
	}
	
	for (int i = 1; i <= n; i ++) for (int j = i + 1; j <= n; j ++) {
		if (ed[i][j] >= 1e15 || ed[j][i] >= 1e15) continue;
		add (i, j, ed[i][j]);
		add (j, i, ed[j][i]);
//		cout  << "AAA" << i <<" " << j << " "<< ed[i][j] << "\n";
	}

	while (q --) {
		for (int i = 1; i < N; i ++) dis[i] = 1e16;
		siz = 0;
		int x, y;
		cin >> x >> y;
		cout << w[y] + dij (N + x, y) << "\n";
	}
	
	return 0;
}
