#include <bits/stdc++.h>
#define int long long
#define rd read()
#define fi first
#define se second
#define pii pair<int, int>
#define rep(i, x, y) for (int i = x; i <= y; i++)
using namespace std;
const int N = 5 + 6e5;
int c, n, m, d, q, w[N], k, dis[N]; 
vector<pair<int, int>> e[N];
int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	return x * f;
}
void write(int x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
void bfs(int s) {
	memset(dis, 0x3f, sizeof dis);
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({0, s}); dis[s] = 0;
	while (!pq.empty()) {
		int u = pq.top().se, we = pq.top().fi;
		pq.pop();
		if (we != dis[u]) continue;
		for (auto i : e[u]) {
			int v = i.fi, w = i.se;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
}
signed main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = rd; n = rd; m = rd; d = rd; q = rd;
	rep(i, 1, m) w[i] = rd;
	rep(i, 1, n) {
		int u = m + i;
		k = rd;
		rep(j, 1, k) {
			int v = rd, r = rd;
			e[u].push_back({v, r});
			e[v].push_back({u, r});
		}
	}
	while (q--) {
		int u = rd, v = rd;
		bfs(u);
		write(dis[v] + w[u] + w[v]), putchar('\n');
	}
}
