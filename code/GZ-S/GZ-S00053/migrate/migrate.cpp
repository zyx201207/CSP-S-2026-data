//GZ-S00053 张善之 贵阳市云岩区中天中学
#include <bits/stdc++.h>
using namespace std ;
const int N = 2e6+10 ;
#define ll long long
ll a[N] ;
ll n , d , ans ;
int main () {
	ios::sync_with_stdio(false) ;
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	ll C , T ;
	cin >> C >> T ;
	while(T--) {
		ans=0;cin >> n >> d ;
		for(int i=1;i<=N;i++) a[i] = 0 ;
		for(int i=1;i<=n;i++) {
			cin >> a[i] ;
		}
		for(ll i=1;i<=n;i++) {
			for(ll j=i+3;j<=n;j++){
				ll q = abs(a[j]-a[i]) , q1=0;
				if(q%2==1) q1=q/2+1 ;
				else q1=q/2 ;
				if(d>=q1&&d<q&&a[upper_bound(a+1,a+n+1,q1)-a]<a[j]&&a[i]+2*d>a[j]){
					ans++;
				} 
			}
		} 
		cout << ans << "\n" ;
	}
	return 0 ;
}

