// ЭѕУћбя GZ-J00087 
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll n, m;
vector<ll> a;
vector<bool> is_vis;
ll ans;
void check() {
	ll res;
	bool is_first = true;
	for (ll i = 1; i <= n; ++i)
		if (is_vis[i]) {
			if (is_first)
				is_first = false, res = a[i];
			else
				res &= a[i];
		}
	ans = max(ans, res);
}
void bfs(ll round) {
	if (round > m) {
		check();
		return;
	}
	for (ll i = 1; i <= n; ++i) {
		if (!is_vis[i]) {
			is_vis[i] = true, bfs(round + 1);
			is_vis[i] = false;
		}
	}
}
int main() {
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	
	cin >> n >> m;
	a.resize(n + 1);
	for (ll i = 1; i <= n; ++i)
		cin >> a[i];
	is_vis.resize(n + 1);
	bfs(1);
	cout << ans << '\n';
} 
