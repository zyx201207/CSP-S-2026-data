#include <bits/stdc++.h>
#define ll long long 
#define mkp make_pair
using namespace std;
const ll N = 5e5 + 10, M = 5e2 + 10;
ll read(ll x = 0, ll f = 1) {
	char c = getchar();
	while (c < '0' || c > '9') c = getchar();
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}
void write(ll x) {
	string s = to_string(x);
	for (int i = 0; i < int(s.size()); i++) putchar(s[i]);
	putchar('\n');
	return;
}
ll c, n, m, q, dd, a[N], w[N], d[M][M], b[M][M];
struct edge{
	ll v, w;
	bool operator < (const edge &other) const {
		return w < other.w;
	}
};
vector <ll> g[M];
vector <pair<ll, ll>> G[N];
ll ans(ll st, ll ts) {
	ll res = 1e18;
	for (int i = 0; i < int(G[st].size()); i++) {
		for (int j = 0; j < int(G[ts].size()); j++) {
			ll u = G[st][i].first, uw = G[st][i].second, v = G[ts][j].first, vw = G[ts][j].second;
			res = min(res, d[u][v] + uw + vw);
		//	cout << u << ' ' << v << ' ' << d[u][v] << '\n';
		}
	}
	return res + w[st] + w[ts];
}

void yu(ll st) {
	for (int i = 1; i <= n; i++) d[st][i] = 1e18;
	d[st][st] = 0;
	priority_queue <edge> q;
	q.push({st, 0});
	while (!q.empty()) {
		ll u = q.top().v, ww = q.top().w;
		q.pop();
		if (ww != d[st][u]) continue;
		for (int i = 0; i < int(g[u].size()); i++) {
			ll v = g[u][i], w = b[u][v];
			if (d[st][u] + w < d[st][v]) {
				d[st][v] = d[st][u] + w;
				q.push({v, d[st][v]});
			}
		}
	}
}
int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	c = read(), n = read(), m = read(), dd = read(), q = read();
	for (int i = 1; i <= m; i++) w[i] = read();
	for (int i = 1; i <= n; i++) {
		ll k;
		k = read();
		while (k--) {
			ll a, t;
			a = read(), t = read();
			G[a].push_back(mkp(i, t));
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) b[i][j] = 1e18;
	}
	for (int i = 1; i <= m; i++) {
		for (int j = 0; j < int(G[i].size()); j++) {
			for (int k = j + 1; k < int(G[i].size()); k++) {
				ll w = G[i][j].second + G[i][k].second, u = G[i][j].first, v = G[i][k].first;
				b[u][v] = min(b[u][v], w), b[v][u] = min(b[v][u], w);
			//	cout << b[u][v] << ' ' << u << ' ' << v << '\n';
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (b[i][j] != 1e18) g[i].push_back(j);
		}
	}
	for (ll i = 1; i <= n; i++) yu(i);
	for (int i = 1; i <= q; i++) {
		ll xr, yr;
		xr = read(), yr = read();
		write(ans(xr, yr));
	}
	return 0;
}
