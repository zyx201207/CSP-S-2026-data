#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c, n, m, d, q;
ll w[500005];
int main(){
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(ll i = 1; i <= m; i++){
		cin >> w[i];
	}
	ll ans = 0;
	for(ll i = 1; i <= n; i++){
		ll t;
		cin >> t;
		for(ll j = 1; j <= t; j++){
			ll a, b;
			cin >> a >> b;
			ans += b;
		}
	}
	for(ll i = 1; i <= q; i++){
		ll in, out;
		cin >> in >> out;
	}
	cout << ans << "\n";
	return 0;
}
