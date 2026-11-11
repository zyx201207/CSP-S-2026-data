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
	const ll N = 5e5 + 5,M = 3e5 + 5 ;
	ll n,m,a[N],lst[M],w[N],ans[M] ;
	void Main(){
		cin >> n >> m ;
		For(i,1,n)
			cin >> a[i],
			lst[a[i]] = i ;
		For(i,1,n){
			++ w[i] ;
			ans[a[i]] += w[i] ;
			w[lst[a[i]] + 1] += w[i] ;
		}
		For(i,1,m)
			cout << ans[i] << " \n"[i == m] ;
		return ;
	}
} ;
int main(){
	//写快读的话记得关掉 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	freopen("card.in","r",stdin) ;
	freopen("card.out","w",stdout) ;
	int _ = 1 ;
//	cin >> _ ;
	while(_ --)LIXUEAN::Main() ;
	return 0 ;
}
