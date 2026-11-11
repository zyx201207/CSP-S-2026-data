#include <bits/stdc++.h>
using namespace std;
const long long INF = 4e18;
const int M = 2e4 + 5, N = 505, MN = 1005; 
int c, n, m, d, q, k, u, v, head, tail, w[M];
long long dis[M][N], t[M][N], ans[MN][MN]; 
vector<int> g[N], num[M];
struct Node { int now, id; long long nowdis; } Q[M * N];
int read() {
	int x = 0, f = 0; char ch = getchar();
	while (!isdigit(ch)) f |= (ch == '-'), ch = getchar();
	while (isdigit(ch)) x = x * 10 + ch - '0', ch = getchar();
	return f ? -x : x;
}
void write(long long x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void bfs1(int st) {
	head = tail = 1;
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) dis[i][j] = INF;
	for (int i : num[st]) Q[++tail] = (Node){st, i, dis[st][i] = t[st][i]};
	while (head <= tail) {
		int now = Q[head].now, id = Q[head].id;
		long long nowdis = Q[head++].nowdis;
		if (nowdis > dis[now][id]) continue; 
		for (int i : num[now])
			for (int nxt : g[i]) 
				if (t[now][i] != INF && t[nxt][i] != INF) {
					if (i == id && dis[now][id] + t[nxt][i] < dis[nxt][i]) 
						Q[++tail] = (Node){nxt, i, dis[nxt][i] = dis[now][id] + t[nxt][i]};
					else if (dis[now][id] + t[now][i] + t[nxt][i] < dis[nxt][i])
						Q[++tail] = (Node){nxt, i, dis[nxt][i] = dis[now][id] + t[now][i] + t[nxt][i]};
				}
	}
	for (int i = 1; i <= m; ++i) 
		for (int j = 1; j <= n; ++j)
			ans[st][i] = min(ans[st][i], dis[i][j]);
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	for (int i = 1; i <= m; ++i) w[i] = read();
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= n; ++j) t[i][j] = INF;
	for (int i = 1; i <= n; ++i) {
		k = read();
		for (int j = 1; j <= k; ++j) 
			u = read(), v = read(), t[u][i] = v,
			g[i].push_back(u), num[u].push_back(i);
	}
	for (int i = 1; i <= m; ++i)
		for (int j = 1; j <= m; ++j) ans[i][j] = INF; 
	for (int i = 1; i <= m; ++i) bfs1(i);
	while (q--) u = read(), v = read(), write(ans[u][v] + w[u] + w[v]), putchar('\n');
	return 0;
}
