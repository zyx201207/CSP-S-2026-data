#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double db;
const int N = 5e5 + 10;
ll n, m, a[N];
map<ll, ll> b;
ll ans = LONG_LONG_MIN;
inline bool check(ll x){
	ll ans = 0;
	for(int i = 1; i <= n; i++){
		if(a[i] <= x){
			ans += abs(a[i] - x);
		}
	}
	return (ans <= m);
}
inline void calc(ll L){
	b.clear();
	for(int i = 1; i <= n; i++){
		ll x = abs(a[i] - L);
		if(m >= x && a[i] <= L){
			m -= x;
			a[i] = L;
		}
	}
//	for(int i = 1; i <= n; i++) printf("%lld ", a[i]);
//	printf("\n");
	for(int i = 1; i <= n; i++) b[a[i]]++;
	
	for(int i = 1; i <= n; i++){
		ans = max(ans, b[a[i]]);
	}	
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);	
	
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i++)
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	ll L = -1e12 - 1, R = 1e12;
	while(L + 1 < R){
		ll M = L + (R - L + 1) / 2;
		if(check(M)) L = M;
		else R = M;
	}
	calc(L);
	
	sort(a + 1, a + n + 1, greater<ll>());
	L = -1e12 - 1, R = 1e12;
	while(L + 1 < R){
		ll M = L + (R - L + 1) / 2;
		if(check(M)) L = M;
		else R = M;
	}
	calc(L);
	printf("%lld\n", ans);
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
