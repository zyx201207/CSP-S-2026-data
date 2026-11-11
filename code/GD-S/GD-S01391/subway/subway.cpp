#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define endl "\n"
using namespace std;
const ll INF = 0x3f3f3f3f3f3f3f3f;
const ll MAXN = 1e7 + 5;
const ll MAXM = 1e7 + 5;
ll c, n, m, d, q, x, y, head[MAXN], cntE, cntV, dis[MAXN], a[MAXM], t[MAXM];
bool inque[MAXN];

inline void write(ll x) {
	string s;
	if (!x) s = "0";
	while (x) s += (x % 10) + '0', x /= 10;
	for (ll i = s.size() - 1; i >= 0; i--) putchar(s[i]);
	putchar('\n');
}

struct Edge {
	ll to, nxt, w;
} edges[MAXM];

inline void add(ll u, ll v, ll w) {
	edges[++cntE] = {v, head[u], w};
	head[u] = cntE;
}

inline void dijkstra(ll src) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pq;
	fill(dis + 1, dis + cntV + 1, INF);
	pq.push({0, src});
	dis[src] = 0;
	while (!pq.empty()) {
		ll d = pq.top().first;
		ll u = pq.top().second;
		pq.pop();
		if (d != dis[u]) continue;
		for (ll i = head[u]; i != -1; i = edges[i].nxt) {
			ll v = edges[i].to;
			ll w = edges[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				pq.push({dis[v], v});
			}
		}
	}
}

inline void spfa(ll src) {
	fill(dis + 1, dis + cntV + 1, INF);
	queue<ll> q;
	q.push(src);
	dis[src] = 0;
	inque[src] = true;
	while (!q.empty()) {
		ll u = q.front();
		q.pop();
		inque[u] = false;
		for (ll i = head[u]; i != -1; i = edges[i].nxt) {
			ll v = edges[i].to;
			ll w = edges[i].w;
			if (dis[v] > dis[u] + w) {
				dis[v] = dis[u] + w;
				if (!inque[v]) {
					q.push(v);
					inque[v] = true;
				}
			}
		}
	}
}

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(false);
	cout.tie(0), cin.tie(0);
	memset(head, -1, sizeof(head));
	cin >> c >> n >> m >> d >> q;
	for (ll i = 1, w; i <= m; i++) {
		cin >> w;
		add(i, i + m, w);
		add(i + m, i, w);
	}

	cntV = m << 1;
	for (ll i = 1, k; i <= n; i++) {
		cin >> k;
		for (ll j = 1; j <= k; j++) {
			cin >> a[j] >> t[j];
			add(a[j] + m, ++cntV, t[j]);
			add(cntV, a[j] + m, t[j]);
		}
		for (ll j = 2; j <= k; j++) {
			add(cntV - j + 2, cntV - j + 1, 0);
			add(cntV - j + 1, cntV - j + 2, 0);
		}
	}

	while (q--) {
		cin >> x >> y;
		
		spfa(x);
		
		write(dis[y]);
	}
	return 0;
}

