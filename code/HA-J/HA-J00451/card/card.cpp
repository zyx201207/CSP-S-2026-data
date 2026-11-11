#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 500010, M = 300010;
ll n, m, a[N], lst[M], cnt[M], ans[M];
vector<ll> g[M];
void dfs(ll u) {
	for (ll i = 0; i < g[u].size(); i++) {
		ll v = g[u][i];
		dfs(v);
		ans[u] += ans[v];
	}
	ans[u] += cnt[u];
}
int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> m;
	for (ll i = 1; i <= n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	for (ll i = n; i >= 1; i--) {
		if (!lst[a[i]]) {
			lst[a[i]] = i;
		}
	}
	for (ll i = 1; i <= m; i++) {
		g[a[lst[i] + 1]].push_back(i);
	}
	dfs(a[n]);
	for (ll i = 1; i <= m; i++) {
		cout << ans[i] << " ";
	}
	return 0;
}
