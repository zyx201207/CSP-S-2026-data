#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll, ll>
using namespace std;
inline ll read() {
	ll x = 0, f = 1;
	char c = getchar();
	while (c < '0' || c > '9') {
		if (c == '-') {
			f = 0;
		}
		c = getchar();
	}
	while ('0' <= c && c <= '9') {
		x = (x << 3) + (x << 1) + (c ^ 48);
		c = getchar();
	}
	if (f) {
		return x;
	}
	return -x;
}
inline void write(ll s) {
	if (s < 10) {
		putchar(s ^ 48);
		return ;
	}
	write(s / 10);
	putchar(s % 10 ^ 48);
}
const ll inf = 0x3f3f3f3f3f3f;
ll c, n, m, d, q, w[500005], f[505][505], ans[505][505];
vector<int> dt[505];
vector<pii> hc[500005], g[500005];
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), d = read(), q = read();
	memset(f, 0x3f, sizeof(f));
	memset(ans, 0x3f, sizeof(ans));
	for (int i = 1; i <= m; i++) {
		w[i] = read();
	}
	for (int i = 1; i <= n; i++) {
		f[i][i] = 0;
		int k;
		k = read();
		for (int j = 1; j <= k; j++) {
			ll x, t;
			x = read(), t = read();
			dt[i].push_back(x);
			hc[x].push_back({i, t});
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int x : dt[i]) {
			int ti = 0;
			for (pii kx : hc[x]) {
				if (kx.first == i) {
					ti = kx.second;
					break;
				}
			}
			for (pii kx : hc[x]) {
				f[i][kx.first] = min(f[i][kx.first], ti + kx.second);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j) {
				continue;
			}
			if (f[i][j] >= inf) {
				continue;
			}
			g[i].push_back({j, f[i][j]});
		}
	}
	for (int i = 1; i <= n; i++) {
		priority_queue<pii, vector<pii>, greater<pii> > pq;
		pq.push({i, 0});
		ans[i][i] = 0;
		while (!pq.empty()) {
			pii tp = pq.top();
			pq.pop();
			ll x = tp.first, dis = tp.second;
			for (pii yy : g[x]) {
				ll y = yy.first, z = yy.second;
				if (dis + z < ans[i][y]) {
					ans[i][y] = dis + z;
					pq.push({y, ans[i][y]});
				}
			}
		}
	}
	for (int i = 1; i <= q; i++) {
		ll x, y, now = inf;
		x = read(), y = read();
		for (pii kk1 : hc[x]) {
			for (pii kk2 : hc[y]) {
				now = min(now, ans[kk1.first][kk2.first] + kk1.second + kk2.second);
			}
		}
		now += w[x];
		now += w[y];
		write(now);
		putchar('\n');
	}
	return 0;
}
