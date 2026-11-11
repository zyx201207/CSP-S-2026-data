#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500010], num[300010], pos[300010], ans[300010], use[300010];

int main() {
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for(ll i=1; i<=n; i++) scanf("%lld", &a[i]);

	stack<ll> s;
	for(ll i=1; i<=n; i++){
		for(ll j=i; j<=n; j++){
			if(pos[a[j] ] != 0){
				while(s.top() != a[j]){
					pos[s.top()] = 0;
					s.pop();
				}
			}else{
				s.push(a[j]);
				pos[a[j] ] = 1;
			}
		}
		while(!s.empty() ){
			if(use[s.top()] == 0) ans[s.top()]++;
			use[s.top()] = 1;
			s.pop();
		}
		for(ll j=1; j<=m; j++) use[j] = 0;
		for(ll j=1; j<=m; j++) pos[j] = 0;
	}
	
	for(ll i=1; i<=m; i++) printf("%lld ", ans[i]);
	
	return 0;
}
