#include<bits/stdc++.h>

#define FOR(i, j, k) for(ll i = j;i <= k;++i)

using namespace std;

typedef long long ll;
typedef pair<ll, ll> PII;

const ll N = 1e6 + 10;
ll c, k, n, t, u, v, ans = LLONG_MAX, fa[N], dis[N];
vector<ll> g[N];
bitset<N> vis;
queue<PII> q;

void bfs(ll s) {
	q.push({s, 0});
	while(!q.empty()) {
		auto f = q.front();
		q.pop();
		for(auto v : g[f.first]) 
			if(f.second + 1 < dis[v]) {
				dis[v] = f.second + 1;
				q.push({v, f.second + 1});
			}
	}
}

inline ll fid(ll x) { return (x == fa[x] ? x : (fa[x] = fid(fa[x]))); }

inline void merge(ll x, ll y)  {
	ll fx = fid(x), fy = fid(y);
	if(fx != fy) fa[fx] = fy;
}

inline ll calc() {
	ll ret = LLONG_MIN;
	iota(fa + 1, fa + n + 1, 1);
	FOR(i, 1, n) {
		if(!vis[i]) continue;
		for(auto v:g[i]) if(vis[v]) merge(i, v);
	}
	ll cnt = 0;
	FOR(i, 1, n) {
		if(!vis[i]) continue;
		if(fid(i) == i) ++cnt;
		if(cnt > 2) return LLONG_MAX;
	}
	FOR(i, 1, n) {
		if(vis[i]) {
			ret = max(ret, 0ll);
			continue;
		}
		ll tmp = LLONG_MAX;
		FOR(j, 1, n) dis[j] = LLONG_MAX;
		dis[i] = 0;
		bfs(i);
		FOR(j, 1, n) if(vis[j]) tmp = min(tmp, dis[j]);
		ret = max(ret, tmp);
	}
	return ret;
}

void dfs(ll now, ll cnt) {
	if(cnt == k) {
		ans = min(ans, calc());
		return;
	}
	if(now > n) return;
	if(cnt + (n - now) < k) return;
	dfs(now + 1, cnt);
	vis[now] = 1;
	dfs(now + 1, cnt + 1);
	vis[now] = 0;
}

void init() {
	FOR(i, 1, n) g[i].clear();
	ans = LLONG_MAX;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> c >> t;
	while(t--) {
		cin >> n >> k;
		FOR(i, 2, n) {
			cin >> u >> v;
			g[u].emplace_back(v), g[v].emplace_back(u);
		}
		dfs(1, 0);
		cout << (ans == LLONG_MAX ? 1 : ans) << '\n';
		init();
	}
	return 0;
}
/*
What's up
graph test?
*/
