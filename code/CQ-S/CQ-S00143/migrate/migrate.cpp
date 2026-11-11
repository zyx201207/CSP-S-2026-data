#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N = 1e6 + 10;
ll c, T, n, m, num;
ll a[N];
void dfs(ll u, ll g, ll maxx, ll sum){
	if (sum > maxx) return;
	if (u == g){
		num++;
		return;
	}
	for (ll i = u + 1; i <= n && a[i] - a[u] <= m; i++){
		dfs(i, g, maxx, sum + 1);
		if (num >= 3) return;
	}
}
int main(){
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> T;
	while (T--){
		cin >> n >> m;
		ll ans = 0;
		for (ll i = 1; i <= n; i++) cin >> a[i];
		for (ll i = 1; i <= n; i++)
			for (ll j = i + 1; j <= n; j++){
				ll res = 0;
				for (ll k = i; k < j; res++){
					ll l = k;
					while (l <= j && a[l] - a[k] <= m) l++;
					if (l == k + 1) break;
					k = l - 1;
				}
				dfs(i, j, res, 0);
				if (num == 2) ans++;
				num = 0;
			}
		cout << ans << endl;
	}
	return 0;
}
