//GZ-J00070 张善之 贵阳市云岩区中天中学 
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e5+10 ;
#define ll long long
ll a[N] ;
int main () {
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0) , cout.tie(0) ;
	ll n ,  m ;
	cin >> n >> m ;
	if(m==1){
		ll ans = -1e9 ;
		for(int i=1;i<=n;i++) {
			ll a ; cin >> a ;
			ans = max(a,ans) ;
		}
		cout << ans ;
	}
	if(m==n) {
		ll ans = 0 ;
		for(int i=1;i<=n;i++) cin >> a[i] ;
		ans = a[1] ;
		for(int i=2;i<=n;i++) {
			ans=ans&a[i] ;
		}
		cout << ans ;
	}
	if(m==2) {
		ll ans = 0 ;
		for(int i=1;i<=n;i++) cin >> a[i] ;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++) {
				ans = max(ans,a[i]&a[j]) ;
			}
		}
		cout << ans ;
	}
	return 0 ;
}

