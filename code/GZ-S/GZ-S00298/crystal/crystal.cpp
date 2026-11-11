// GZ-S00298 游景智 
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
typedef long long ll;
ll a[N];
ll n, m, sum[N];
// 简单二分题
// 固定最大值即可 
ll ans;
bool check(ll x, ll mid){
	return (x - mid + 1) * a[x] - (sum[x] - sum[mid - 1]) <= m;
}
int main(){
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout); 
	scanf("%lld%lld", &n, &m);
	for(ll i = 1; i <= n; i++){
		scanf("%lld", &a[i]);
	}
	sort(a + 1, a + n + 1);
	for(ll i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + a[i];
	for(ll i = 1; i <= n; i++){
		ll l = 1, r = i;
		while(l < r){
			ll mid = (l + r) / 2;
			if(check(i, mid)){
				r = mid;				
			}else l = mid + 1;
		} 
		ans = max(ans, i - l + 1); // 注意是i! 
	}
	printf("%lld\n", ans);
	return 0;
}
