#include <bits/stdc++.h>
#define re read()
#define wr(x) write(x)
#define sp putchar(' ')
#define endl puts("")
#define int long long

const int N = 5e5 + 10, INF = 0x3f3f3f3f3f3f3f3f;

using namespace std;

int read() {
	int y = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') f = c == '-' ? -1 : f, c = getchar();
	while (c >= '0' && c <= '9') y = (y << 1) + (y << 3) + (c ^ 48), c = getchar();
	return y * f;
}

void write(int x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + 48);
}

int n, k;
bool edge[1010][1010];
int fa[N];
int a[N];
bool flag[N];
vector<int> g[N];

int find(int x) {
	return x == fa[x] ? x : fa[x] = find(fa[x]);
}

int popcount(int s) {
	int cnt = 0;
	while (s) cnt += s & 1, s >>= 1;
	return cnt;
}

int X;

void dfs(int u, int fa) {
	for (auto v : g[u]) {
		if (v == fa) continue;
		if (flag[u] && flag[v]) X--;
		dfs(v, u);
	}
}

int dis[110][1010];
bool vis[N];

using pii = pair<int, int>;

void dij(int s) {
	memset(vis, 0, sizeof vis);
	for (int i = 1; i <= n; i++) dis[s][i] = INF;
	priority_queue<pii, vector<pii>, greater<pii> > q;
	dis[s][s] = 0, q.push({0, s});
	while (!q.empty()) {
		int u = q.top().second; q.pop();
		if (vis[u]) continue;
		vis[u] = 1;
		for (auto v : g[u]) if (dis[s][v] > dis[s][u] + 1) dis[s][v] = dis[s][u] + 1, q.push({dis[s][v], v});
	}
}

void solve() {
	n = re, k = re;
	for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i < n; i++) {
		int u = re, v = re;
		edge[u][v] = edge[v][u] = 1;
		g[u].push_back(v), g[v].push_back(u);
	} 
	int ans = INF;
	for (int s = 0; s < (1 << n); s++) {
		if (popcount(s) == k) {
			int tot = 0;
			for (int i = 1; i <= n; i++) if ((s >> i - 1) & 1) a[++tot] = i, flag[i] = 1;
			X = k;
			dfs(1, 0);
			if (X <= 2) {
				for (int i = 1; i <= k; i++) dij(a[i]);
				int sum = 0;
				for (int i = 1; i <= n; i++) if (!flag[i]) {
					int cnt = INF;
					for (int j = 1; j <= k; j++) cnt = min(cnt, dis[a[j]][i]);
					sum = max(sum, cnt);
				}
				ans = min(ans, sum);
			}
			for (int i = 1; i <= k; i++) flag[i] = 0;
		}
	}
	wr(ans), endl;
}

signed main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	int XXXXX = re, t = re;
	while (t--) solve();
}
/*
0 2
5 2
1 2
2 3
3 4
4 5

*/

