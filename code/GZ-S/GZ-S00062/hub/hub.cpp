//GZ-S00062 ∏∂Í¿‘Û 
#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define vec vector
#define str string
#define fi first
#define se second
using namespace std;

const ll N = 1e6 + 5;

ll sz[N];
vec<ll> t[N];

void dfs(ll f, ll u) {
	sz[u] = 1;
	for(ll i = 0;i < t[u].size();i++) {
		if(f == t[u][i])
		    continue;
		dfs(u, t[u][i]);
		sz[u] += sz[t[u][i]]; 
	}
}

void Solve() {
	ll n, k;
	cin >> n >> k;
	for(ll i = 1;i <= n;i++)
	    t[i].resize(0);
	fill(sz + 1, sz + n + 1, 0);
	for(ll i = 1;i < n;i++) {
		ll u, v; cin >> u >> v;
		t[u].push_back(v), t[v].push_back(u);
	}
	dfs(0, 1);
	ll ans = 1e18;
	for(ll i = 1;i <= n;i++) {
		vec<ll> s;
		s.push_back(sz[1] - sz[i]);
		for(ll j = 0;j < t[i].size();j++)
			s.push_back(sz[t[i][j]]);
		ll l = -1, r = 1e9;
		while(l + 1 != r) {
			ll mid = (l + r) / 2;
			
			ll cnt = 0;
			for(ll j = 0;j < s.size();j++)
			   cnt += s[j] - mid;
			(cnt < k ? r : l) = mid;
		}
		ans = min(ans, l);
	}
	cout << ans << endl;
	return ;
}

int main() {
	freopen("hub.in", "r", stdin);
	freopen("hub.out", "w", stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0), cout.tie(0);

	ll c, t;
	cin >> c >> t;
	while(t--) Solve();
	
	return 0;
}
