#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 510, M = 5e5 + 10;
const ll inf = 1e16;
int c, n, m, d, _, w[M], head[M + N], hd[N], tot, cnt;
ll g[N][N], dis[N][N];
struct Node {int num, val, nxt;} t[M << 1];
struct Edge {int to, nxt; ll dis;} e[M];
bitset<N> vis;
priority_queue<pair<ll, int>> q;
void rd(int &n) {
	int x = 0;
	char ch = getchar();
	while (!isdigit(ch)) ch = getchar();
	while (isdigit(ch)) x = x * 10 + (ch - '0'), ch = getchar();
	n = x;
}
void wt(ll n) {
	int len = 0; char out[20];
	while (n) out[++len] = '0' + n % 10, n /= 10;
	while (len) putchar(out[len--]);
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	rd(c), rd(n), rd(m), rd(d), rd(_);
	for (int i = 1; i <= m; i++) rd(w[i]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i ^ j) g[i][j] = inf;
			else g[i][j] = 0;
	for (int i = 1; i <= n; i++) {
		int k; rd(k);
		while (k--) {
			int num, val; rd(num), rd(val);
			t[++tot] = {i + m, val, head[num]}, head[num] = tot;
			t[++tot] = {num, val, head[i + m]}, head[i + m] = tot;
		}
	}
	for (int i = 1; i <= n; i++)
		for (int j = head[i + m]; j; j = t[j].nxt) {
			int k = t[j].num;
			for (int o = head[k]; o; o = t[o].nxt) {
				int _ = t[o].num - m;
				g[i][_] = min(g[i][_], (ll)t[j].val + (ll)t[o].val);
			}
		}
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i ^ j && g[i][j] ^ inf) e[++cnt] = {j, hd[i], g[i][j]}, hd[i] = cnt;
	for (int s = 1; s <= n; s++) {
		for (int i = 1; i <= n; i++) dis[s][i] = inf;
		while (!q.empty()) q.pop();
		dis[s][s] = 0, q.push({0, s}), vis.reset();
		while (!q.empty()) {
			int u = q.top().second; q.pop();
			if (vis[u]) continue;
			vis[u] = 1;
			for (int i = hd[u]; i; i = e[i].nxt) {
				int v = e[i].to; ll w = e[i].dis;
				if (dis[s][v] > dis[s][u] + w) {
					dis[s][v] = dis[s][u] + w;
					if (!vis[v]) q.push({-dis[s][v], v});
				}
			}
		}
	}
	while (_--) {
		int x, y; rd(x), rd(y);
		if (x == y) {
			putchar('0'), putchar('\n');
			continue;
		}
		ll ans = inf;
		for (int i = head[x]; i; i = t[i].nxt)
			for (int j = head[y]; j; j = t[j].nxt)
				ans = min(ans, (ll)w[x] + (ll)w[y] + (ll)t[i].val + (ll)t[j].val + dis[t[i].num - m][t[j].num - m]);
		wt(ans), putchar('\n');
	}
	return 0;
}
