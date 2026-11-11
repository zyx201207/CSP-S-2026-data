#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[500010], d[500010];

int main() {
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ll n, m;
	scanf("%lld %lld", &n, &m);
	for(ll i=1; i<=n; i++) scanf("%lld", &a[i]);
	sort(a+1, a+n+1);
	for(ll i=1; i<=n; i++) d[i] = a[i]-a[i-1];
	d[1] = 0;
	
	
	ll l = 1, use = 0, ans = 0, tem = 1;
	for(ll r=2; r<=n; r++){
		use += d[r]*tem;
		tem++;
		if(use > m){
			ans = max(ans, tem-1);
			use -= a[r]-a[l];
			l++;
			tem--;
		}
	}
	
	printf("%lld", ans);
		
	return 0;
}
