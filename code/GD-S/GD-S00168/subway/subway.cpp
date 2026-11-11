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
	const ll N = 500 + 5,M = 5e5 + 5,SK = 5e5 + 5,D = 20 + 5,Q = 1e5 + 5,oo = 1e18 ;
	ll c,n,m,d,q,w[M],dis[N][N] ;
	vector<Pir> nxt[M] ; //只需要原点到虚点的边即可 
	inline void Min(ll &a,ll b){ if(b < a)a = b ; return ; }
	void Main(){
		cin >> c >> n >> m >> d >> q ;
		For(i,1,m)cin >> w[i] ;
		For(i,1,n){
			ll nowk = 0,to = 0,len = 0 ;
			cin >> nowk ;
			For(j,1,nowk){
				cin >> to >> len ;
				nxt[to].push_back({i,len}) ;
			}
		}
		For(i,1,n)For(o,1,n)
			dis[i][o] = (i == o ? 0 : oo) ;
		For(i,1,m)
			For(o,0,ll(nxt[i].size()) - 1)
				For(j,o + 1,ll(nxt[i].size()) - 1){
					ll oto = nxt[i][o].fir,jto = nxt[i][j].fir ;
					ll res = nxt[i][o].sec + nxt[i][j].sec ;
					if(res < dis[oto][jto])
						dis[oto][jto] = dis[jto][oto] = res ;
				}
		For(k,1,n)For(i,1,n)For(j,1,n)
			dis[i][j] = min(dis[i][j],dis[i][k] + dis[k][j]) ;
		For(qid,1,q){
			ll s = 0,t = 0 ;
			cin >> s >> t ;
			ll ans = oo ;
			for(auto sit : nxt[s])for(auto tit : nxt[t])
				ans = min(ans,dis[sit.fir][tit.fir] + sit.sec + tit.sec) ;
			cout << ans + w[s] + w[t] << '\n' ;
		}
		return ;
	}
} ;
int main(){
	//如果需要快读，需要注释掉 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	int _ = 1 ;
//	cin >> _ ;
	while(_ --)LIXUEAN::Main() ;
	return 0 ;
}
