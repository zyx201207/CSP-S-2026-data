#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll w[500010], a[5010][5010], t[5010][5010], ans = 9999999999999999, k[510];

int main() {
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	ll c, n, m, d, q;
	scanf("%lld %lld %lld %lld %lld", &c, &n, &m, &d, &q);
	for(ll i=1; i<=m; i++){
		scanf("%lld", &w[i]);
	}
	for(ll i=1; i<=n; i++){
		scanf("%lld", &k[i]);
		for(ll j=1; j<=k[i]; j++) scanf("%lld %lld", &a[i][j], &t[i][j]);
	}
	
	while(q--){
		ll x, r, ans = 0;
		scanf("%lld %lld", &x, &r);
		ans += w[x]+w[r];
		ll small = 9999999999999999;
		for(ll i=1; i<=n; i++){
			for(ll j=1; j<=k[i]; j++){
				if(a[i][j] == x){
					for(ll l=j+1; l<=k[i]; l++){
						if(a[i][l] == r) small = min(small, t[i][j]+t[i][l]);
					}
				}
			}
		}
		ans += small;
		printf("%lld\n", ans);
	}
	
	return 0;
}
