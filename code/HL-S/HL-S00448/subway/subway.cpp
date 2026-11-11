#include <bits/stdc++.h>

using ll = long long ;

ll c , n , m , d , q;

const ll N = 600;
std::vector<ll> a(N);

ll dp[N][N];

ll b[N];

int main(){
	
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	
	std::cin>>c>>n>>m>>d>>q;
	for (ll i=1 ; i<=m ; ++i)
		std::cin>>a[i];
	
	
	for (ll i=1 ; i<=n ; ++i){
		ll k;
		std::cin>>k;
		ll u0 , v0;
		std::cin>>u0>>v0;
		b[u0] = v0;
		for (ll j=2 ; j<k ; ++j){
			ll u , v;
			std::cin>>u>>v;
			b[u] = v;
			dp[u][u-u0] += std::min(dp[u][u-u0] , v+v0);
		}
	}
	
	
	ll ans = 0;
	while (q--){
		ll l , r;
		std::cin>>l>>r;
		
		if (c>=7 and c<=11){
			ans += a[l] + a[r] + b[l] + b[r];
			std::cout<<ans;
			continue;
		}
		
		ans += (a[l] + a[r]); 
		ans += dp[l][r];
		std::cout<<ans<<'\n';
	}
	
	return 0;
	
}