#include <bits/stdc++.h>
using namespace std ;
namespace LIXUEAN{
	typedef long long ll ;
	typedef pair<ll,ll> Pir ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	#define fir         first
	#define sec         second
	//1000ms 1024M
	const ll N = 5e5 + 5,M = 1e18 + 5 ;
	ll n,m,a[N],sum[N] ;
	void Main(){
		cin >> n >> m ;
		For(i,1,n)cin >> a[i] ;
		sort(a + 1,a + n + 1) ;
		For(i,1,n)sum[i] = sum[i - 1] + a[i] ;
		ll ans = 1 ;
		For(i,1,n){
			ll l = 1,r = i,res = i ;
			while(l <= r){
				ll mid = (l + r) >> 1 ;
				if(a[i] * (i - mid + 1) - (sum[i] - sum[mid - 1]) <= m)
					res = mid,r = mid - 1 ;
				else l = mid + 1 ;
			}
			ans = max(ans,i - res + 1) ;
		}
		cout << ans ;
		return ;
	}
} ;
int main(){
	//如果需要快读，需要注释掉 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	freopen("crystal.in","r",stdin) ;
	freopen("crystal.out","w",stdout) ;
	int _ = 1 ;
//	cin >> _ ;
	while(_ --)LIXUEAN::Main() ;
	return 0 ;
}
