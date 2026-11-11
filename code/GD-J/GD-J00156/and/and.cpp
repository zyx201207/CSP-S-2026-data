#include <bits/stdc++.h>
using namespace std ;
namespace LIXUEAN{
	typedef long long ll ;
	typedef pair<ll,ll> Pir ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	#define fir         first
	#define sec         second
	//1000 ms 1024M
	const ll N = 2e5 + 5,M = N,AI = (1ll << 30) - 1 + 5 ;
	ll n,m,a[N] ;
	void Main(){
		cin >> n >> m ;
		For(i,1,n)cin >> a[i] ;
		ll ans = 0 ;
		RFor(i,29,0){
			ans |= (1ll << i) ;
			ll cnt = 0 ;
			For(o,1,n)
				cnt += ll((a[o] & ans) == ans) ;
			if(cnt < m)ans ^= (1ll << i) ;
		}
		cout << ans ;
		return ;
	}
} ;
int main(){
	//写快读的话记得关掉 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	freopen("and.in","r",stdin) ;
	freopen("and.out","w",stdout) ;
	int _ = 1 ;
//	cin >> _ ;
	while(_ --)LIXUEAN::Main() ;
	return 0 ;
}
