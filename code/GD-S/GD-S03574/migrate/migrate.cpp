#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

ll x[2000010], s[2000010], n, d;
map<ll, ll> mapp;

inline ll find(ll l, ll r){
	ll num = 0;
	for(ll i=l+1; i<=r; i++){
//		if(s[i] > d) return 0;
		num = s[i];
		while(num<d && i<r){
			i++;
			num += s[i];
		}
		if(num > d){
			num -= s[i];
			i--;
		}
//		cout << num << "\n";
	}
	
	num = d-num;
//	cout << num << "\n";
//	cout << l << " " << r << "\n";
	for(ll i=1; i<=num; i++){
		if(mapp[i] >= 1) return 1;
	}
	
	return 0;
}

int main() {
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ll c, t;
	scanf("%lld %lld", &c, &t);
	while(t--){
		ll add = 0;
		scanf("%lld %lld", &n, &d);
		for(ll i=1; i<=n; i++){
			scanf("%lld", &x[i]);
//			if(x[i]<0 && add==0) add = 0-x[i];
//			x[i] += add;
		}
		for(ll i=1; i<=n; i++) s[i] = x[i]-x[i-1];
		for(ll i=1; i<=n; i++) mapp[s[i] ]++;
//		for(ll i=1; i<=n; i++) cout << s[i] << " ";
//		cout << "\n";
		
		ll ans = 0;
		for(ll i=1; i<=n; i++){
			for(ll j=i+3; j<=n; j++){
				ans += find(i, j);
			}
		}
		
		printf("%lld\n", ans);
		for(ll i=1; i<=n; i++) mapp[x[i] ] = 0;
		for(ll i=1; i<=n; i++) x[i] = 0;
	}
	
	return 0;
}
