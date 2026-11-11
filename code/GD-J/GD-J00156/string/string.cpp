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
	const ll N = 2e5 + 5 ;
	ll n,a[N],b[N] ;
	char cha[N],chb[N] ;
	void Main(){
		cin >> n ;
		ll sum = 0 ;
		For(i,1,n)
			cin >> a[i] >> cha[i],
			sum += a[i],
			b[n - i + 1] = a[i],
			chb[n - i + 1] = cha[i] ;
		For(i,1,n)
			a[i] += a[i - 1],b[i] += b[i - 1] ;
		ll i = 1,j = 1,mid = (sum + 1) / 2 ;
		ll lef = 1,ans = 0 ;
		while(lef <= mid){
			a[i] = min(a[i],mid) ;
			b[j] = min(b[j],mid) ;
			ll rig = min(a[i],b[j]) ;
			ans += ll(cha[i] != chb[j]) * (rig - lef + 1) ;
			lef = rig + 1 ;
			if(a[i] == rig)++ i ;
			if(b[j] == rig)++ j ;
		}
		cout << ans ;
		return ;
	}
} ;
int main(){
	//写快读的话记得关掉 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	freopen("string.in","r",stdin) ;
	freopen("string.out","w",stdout) ;
	int _ = 1 ;
//	cin >> _ ;
	while(_ --)LIXUEAN::Main() ;
	return 0 ;
}
