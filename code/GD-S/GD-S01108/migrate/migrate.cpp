#include <bits/stdc++.h>
using namespace std;
using ll = long long;

const ll N = 2e6 + 10, INF = 0x3f3f3f3f3f3f3f3f;
ll c, t;
ll a[N];
ll n, d;
ll dis[N][2];
ll cnt = 0;
ll ans = 0;

void dfs(ll u, ll v, bool f) {
	if(f == 0) {
		if(u >= v) return;
		for(ll i = u + 1; i <= n && a[i] <= a[u] + d; i ++) {
			dis[i][f] = min(dis[i][f], dis[u][f] + 1);
			dfs(i, v, f);
		}
	}
	else {
		if(u <= v) return;
		for(ll i = u - 1; i >= 1 && a[i] >= a[u] - d; i --) {
			dis[i][f] = min(dis[i][f], dis[u][f] + 1);
			dfs(i, v, f);
		}
	}
}

void solve() {
	cin >> c >> t;
	while(t --) {
		cin >> n >> d;
		ans = 0;
		for(ll i = 1; i <= n; i ++) {
			cin >> a[i];
		}
		for(ll i = 1; i <= n; i ++) {
			for(ll j = i + 1; j <= n; j ++) {
				cnt = 0;
				memset(dis, 0x3f, sizeof dis);
//				printf("%lld -> %lld: ", i, j);
				dis[i][0] = 0;
				dis[j][1] = 0;
				dfs(i, j, 0);
				dfs(j, i, 1);
//				cout << dis[j][0] << '\n';
				for(ll k = i + 1; k < j; k ++) {
//					cout << dis[k][0] << ' ' << dis[k][1] << '\n'; 
					if(dis[k][0] + dis[k][1] == dis[j][0]) cnt ++;
				}
				if(cnt == 2) ans ++;
			}
		}
		cout << ans << '\n';
	}
	return;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	solve();
	
	return 0;
}
