#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 510, M = 5e5 + 10, INF = 0x3f3f3f3f3f3f3f3f, p = 13331, MOD = 998244353, Q = 1e5 + 10, D = 30;
ll c, n, m, d, q, w[M], val[M], tot = 0, fa[M], top[N], tot1 = 0, tot2 = 0, dis[N][N], frm[M];
pair<ll, ll> bel[M], qu[Q], ed[N][N];
bitset<M> vis, vis1[N];
vector<pair<ll, pair<ll, ll> > > e[N];
vector<pair<ll, ll> > R[M];
unordered_map<ll, ll> mp;
ll find(ll x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
void merge(ll x, ll y) { fa[find(x)] = find(y); }

ll BEL(ll x, ll y, ll val = 0) {
	long long QWQ = x % MOD;
	QWQ = (QWQ * p + y) % MOD;
	if(val) mp[QWQ] = val;
	return mp[QWQ];
}

void dij(ll s) {
	priority_queue<pair<ll, ll>, vector<pair<ll, ll> >, greater<pair<ll, ll> > > pq;
	memset(dis[s], INF, sizeof dis[s]);
	dis[s][s] = 0, pq.push(make_pair(dis[s][s], s));
	while(!pq.empty()) {
		pair<ll, ll> p = pq.top(); pq.pop();
		ll u = p.second;
		for(pair<ll, pair<ll, ll> > P : e[u]) {
			ll v = P.first, w = P.second.first, pos = P.second.second;
			if(dis[s][v] > dis[s][u] + w) {
				dis[s][v] = dis[s][u] + w;
				pq.push(make_pair(dis[s][v], v));
			}
		}
	}
}

int main() {
	ios :: sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++) cin >> w[i];
	iota(fa, fa + m + 1, 0);
	for(ll i = 1; i <= n; i++) {
		ll cnt = 0, u; cin >> cnt;
		cin >> u >> val[++tot];
		bel[tot] = make_pair(u, i), top[i] = tot, frm[tot] = i, vis1[i][u] = true, BEL(u, i, val[tot]), R[u].emplace_back(make_pair(i, tot));
//		cerr << tot << ' ' << i << '\n';
		--cnt;
		while(cnt--) {
			ll v; cin >> v >> val[++tot];
			bel[tot] = make_pair(v, i), vis1[i][v] = true, BEL(v, i, val[tot]), R[v].emplace_back(make_pair(i, tot));
			merge(v, u);
		}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			ed[i][j] = make_pair(INF, INF);
		}
	}
	for(ll k = 1; k <= m; k++) {
		for(pair<ll, ll> p : R[k]) 
			for(pair<ll, ll> P : R[k]) {
				ll i = p.first, j = P.first;
				if(i == j) continue;
				pair<ll, ll> p = make_pair(BEL(k, i) + BEL(k, j), k);
				ed[i][j] = min(ed[i][j], p), ed[j][i] = min(ed[j][i], p);
			}
	}
	for(ll i = 1; i <= n; i++) {
		for(ll j = 1; j <= n; j++) {
			if(i != j && ed[i][j] != make_pair(INF, INF)) {
				e[i].emplace_back(make_pair(j, ed[i][j])), e[j].emplace_back(make_pair(i, ed[j][i]));
			}
		}
	}
	for(ll i = 1; i <= n; i++) dij(i);
//	for(ll i = 1; i <= n; i++) {
//		for(ll j = 1; j <= n; j++) {
//			cerr << dis[i][j] << '\n';
//		}
//	}
	for(ll i = 1; i <= q; i++) {
		ll u, v; cin >> u >> v;
		ll ans = INF;
		for(pair<ll, ll> p : R[u]) {
			for(pair<ll, ll> P : R[v]) {
				ll j = p.first, k = P.first, w1 = p.second, w2 = P.second;
				ans = min(ans, dis[j][k] + val[w1] + val[w2] + w[u] + w[v]);
//				cerr << u << ' ' << v << ' ' << j << ' ' << k << ' ' << w1 << ' ' << w2 << ' ' << dis[j][k] << ' ' << val[w1] << ' ' << val[w2] << ' ' << w[u] << ' ' << w[v] << '\n';
			}
		}
		cout << ans << '\n';
	}
	return 0;
}
/*
0 4 5 20 1
4 1 9 2 5
2 1 1 2 2
2 2 2 3 3
2 3 3 4 4
2 4 4 5 5
2 5
*/

