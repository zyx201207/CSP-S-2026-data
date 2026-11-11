#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define endl '\n'
using namespace std;
namespace Callisto{
	const ll N = 2e6+10, INF = 1e9;
	ll n, m;
	ll C, T;
	ll a[N], c[N], minn[N], ans;
	ll cnt;
	
	ll dfs(ll x, ll y, ll now, ll maxx){
		if(x == y){
			cnt++;
			if(cnt > 2) return 1;
			return 0;
		}
		if(now == maxx-1) {
			if(a[y]-a[x] <= m) cnt++;
			if(cnt > 2) return 1;
			return 0;
		}
		for(ll i = y; i > x; i--){
			if(a[i]-a[x] <= m){
				if(dfs(i, y, now+1, maxx)) return 1;
			}
		}
		return 0;
	}
	
	signed main(){
		freopen("migrate.in", "r", stdin);
		freopen("migrate.out", "w", stdout);
		ios::sync_with_stdio(false);
		cin.tie(0), cout.tie(0);
		cin >> C >> T;
		while(T--){
			ans = 0;
			cin >> n >> m;
			for(ll i = 1; i <= n; i++){
				cin >> a[i];
				c[i] = a[i]-a[i-1];
			}
			for(ll i = 1; i < n; i++){
				ll p = n;
				for(ll j = i+1; j <= n; j++){
					if(c[j] > m){
						p = j;
						break;
					}
					ll t = lower_bound(a+i, a+j, a[j]-m)-a;
					minn[j] = minn[t] + 1;
				}
				for(ll j = i+1; j <= p; j++){
					cnt = 0;
					dfs(i, j, 0, minn[j]);
					if(cnt == 2) ans++;
					//cout << cnt << ' ';
					minn[j] = 0;
				}
			}
			cout << ans << endl;
		}
		return 0;
	}
}

signed main(){
	Callisto::main();
	return 0;
}