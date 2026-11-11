#include <bits/stdc++.h>
using namespace std ;
const int N = 5e5 + 5 ;
typedef long long ll ;
int n, ans ; ll m ;
ll a[N], sum[N] ;
bool check(ll x, ll y){
	return 1ll * (y - x + 1) * a[y] - 1ll * (sum[y] - sum[x - 1]) <= m ;
}
int pos_search(int rt){
	int l = 1, r = rt, ans, mid ;
	while(l <= r){
		mid = l + r >> 1 ;
		if(check(mid, rt)) r = mid - 1, ans = mid ;
		else l = mid + 1 ;
	}
	return ans ;
}
int main(){
	freopen("crystal.in", "r", stdin) ;
	freopen("crystal.out", "w", stdout) ;
	scanf("%d%lld", &n, &m) ;
	for(int i = 1; i <= n; i++)
		scanf("%lld", a + i) ;
	sort(a + 1, a + n + 1) ;
	for(int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i] ;
	for(int i = 1; i <= n; i++)
		ans = max(ans, i - pos_search(i) + 1) ;
	printf("%d\n", ans) ;
	return 0 ;
} 
