//GZ-S00053 张善之 贵阳市云岩区中天中学 
#include <bits/stdc++.h>
using namespace std ;
const int N = 5e5+10;
#define ll long long 
ll s[N] , a[N] , c[N] , n , m ;
bool cmp(ll a,ll b) {
	return a<b;
}
int main () {
	ios::sync_with_stdio(false) ;
	cin.tie(0),cout.tie(0);
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin >> a[i];
	sort(a+1,a+n+1,cmp);
	for(ll i=1;i<=n;i++) {
		s[i] = s[i-1]+a[i] ;
	}
	ll ans = -1e9 ;
	for(ll i=1;i<=n;i++) {
		for(ll j=n;j>=1;j--) {
			if((j-i+1)*a[j]-(s[j]-s[i])-1<=m) {
				ans = max(ans,j-i+1) ;
				break ; 
			}
		}
	}
	cout << ans ;
	return 0 ;
}

