// faraway or by the road.
#include <bits/stdc++.h>
#define PII pair<long long, int>
using namespace std;

inline int read() {
	int x = 0; char ch = getchar();
	while (ch < '0' || ch > '9') ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}

const int N = 5e5 + 5e3 + 5, M = N << 1;
const long long INF = 1e18;
int c, n, m, d, qry, a[N], W;
int h[N], e[M], w[M], ne[M], idx;
inline void add(int a, int b, int c) { e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++; }
inline void addedge(int a, int b, int c) { add(a, b, c), add(b, a, c); }

priority_queue< PII > q;
long long dis[N];
bool st[N];
int St[N], Ed[N];
long long Ans[N];

void dijk(int S) {
	for (int i = 1; i <= n + m; i++) dis[i] = INF, st[i] = 0;
	q.push({0, S}), dis[S] = 0;
	while (q.size()) {
		int u = q.top().second; q.pop();
		if (st[u]) continue;
		st[u] = 1;
		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i];
			if (dis[v] > dis[u] + w[i]) dis[v] = dis[u] + w[i], q.push({-dis[v], v});
		}
	}
	for (int i = 1; i <= qry; i++) Ans[i] = min(Ans[i], dis[St[i]] + dis[Ed[i]]);
}

queue<int> que;
int dd[N];
int bfs(int st, int ed) {
	while (que.size()) que.pop();
	for (int i = 1; i <= n + m; i++) dd[i] = 0;
	que.push(st);
	while (que.size()) {
		int u = que.front(); que.pop();
		for (int i = h[u]; ~i; i = ne[i]) {
			int v = e[i]; if (v == st || dd[v]) continue;
			dd[v] = dd[u] + 1, que.push(v);
			if (v == ed) return dd[v];
		}
	}
	return -1;
}
void subB() {
	while (qry--) {
		int u, v; scanf("%d%d", &u, &v);
		long long Dist = bfs(u, v);
		printf("%lld\n", Dist * W + a[u] + a[v]);
	}
}

long long X[3][N];
// 第 i 班列车，在 j 点所需时间 
void subn2() {
	for (int u = 1; u <= m; u++)
		for (int i = h[u]; ~i; i = ne[i]) X[e[i] - m][u] = w[i];
	if (n == 1) {
		while (qry--) {
			int u = read(), v = read();
			// connected!
			printf("%lld\n", X[1][u] + X[1][v] + a[u] + a[v]);
		}
		return;
	}
	// n == 2
	long long trans = 1e18;
	for (int i = 1; i <= m; i++) if (X[1][i] && X[2][i]) trans = min(trans, X[1][i] + X[2][i]);
	while (qry--) {
		int u = read(), v = read();
		long long ans = 1e18;
		if (X[1][u] && X[1][v]) ans = min(ans, X[1][u] + X[1][v]);	// line1
		if (X[2][u] && X[2][v]) ans = min(ans, X[2][u] + X[2][v]);	// line2
		if (trans != 1e18) {	// 换乘 
			if (X[1][u] && X[2][v]) ans = min(ans, X[1][u] + trans + X[2][v]);
			if (X[2][u] && X[1][v]) ans = min(ans, X[2][u] + trans + X[1][v]);
		}
		printf("%lld\n", ans + a[u] + a[v]);
	}
}

int main() {
//	freopen("subway7.in", "r", stdin);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), qry = read();
	// c <= 8
	for (int i = 1; i <= n + m; i++) h[i] = -1; idx = 0;
	for (int i = 1; i <= m; i++) a[i] = read();
	for (int i = 1, k; i <= n; i++) {
		k = read();
		for (int j = 1, x, t; j <= k; j++) x = read(), t = read(), addedge(x, i + m, t), W = t;
	}
	
	if (c >= 12 && c <= 19) return subB(), 0;
//	if (!(m <= 400 && qry <= 200) && n <= 2) return subn2(), 0;
	
//	while (qry--) {
//		int u = read(), v = read();
//		dijk(u);
//		printf("%lld\n", dis[v] + a[u] + a[v]);
////		for (int i = 1; i <= n + m; i++) cout << dis[i] << ' '; puts("");
//	}
	for (int i = 1; i <= qry; i++) St[i] = read(), Ed[i] = read(), Ans[i] = 1e18;
	for (int i = m + 1; i <= n + m; i++) dijk(i);
	
	for (int i = 1; i <= qry; i++) printf("%lld\n", Ans[i] + a[St[i]] + a[Ed[i]]);
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
