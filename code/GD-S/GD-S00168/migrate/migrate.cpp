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
	const ll C = 25 + 5,T = 1e5 + 5,N = 2e6 + 5,SN = 2e6 + 5,D = 2e18 + 5,ABS_XI = 1e18 + 5 ;
	const ll oo = 1e8 + 5 ;//飞行步数的 max 
	ll cid,n,d,x[N] ;
	int dis[5005][5005] ;//95M
	//24'+12'
	void solveBaoli1(){
		For(i,1,n){
			dis[i][i] = 0 ;
			ll rest = 0 ;
			For(j,i + 1,n){
				dis[i][j] = dis[i][j - 1] ;
				if(dis[i][j] == oo)continue ;
				if(x[j] - x[j - 1] > d)
					{ dis[i][j] = oo ; continue ; }
				if(rest < x[j] - x[j - 1])
					++ dis[i][j],rest = d ;
				rest -= x[j] - x[j - 1] ;
			}
		}
		ll ans = 0 ;
		For(i,1,n)For(j,i + 1,n){
			if(dis[i][j] == 1)continue ;
			ll cnt = 0 ;
			For(t,i + 1,j - 1)
				if(dis[i][t] + dis[t][j] == dis[i][j])
					++ cnt ;
			if(cnt == (dis[i][j] - 1) + 1)
				++ ans ;
		}
		cout << ans << '\n' ;
		return ;
	}
	ll ask_pathn(ll lst_bg,ll now_bg,ll j){
		ll res = 0 ;
		For(k,1,2)
			if(lst_bg < now_bg - k)
				if(dis[lst_bg][now_bg - k] + dis[now_bg - k][j - 1] == 2)
					++ res ;
		return res ;
	}
	void solveBaoli2(){
		For(i,1,n){
			dis[i][i] = 0 ;
			ll rest = 0 ;
			For(j,i + 1,n){
				dis[i][j] = dis[i][j - 1] ;
				if(dis[i][j] == oo)continue ;
				if(x[j] - x[j - 1] > d)
					{ dis[i][j] = oo ; continue ; }
				if(rest < x[j] - x[j - 1])
					++ dis[i][j],rest = d ;
				rest -= x[j] - x[j - 1] ;
			}
		}
		//还是先把 dis 求出来 
		
		ll ans = 0 ;
		For(i,1,n){
			ll rest = 0,pathn = 1 ;
			ll lst_bg = 0,now_bg = i ;
			For(j,i + 1,n){
				if(x[j] - x[j - 1] > d)break ;
				if(rest < x[j] - x[j - 1]){
					if(lst_bg){
						pathn += ask_pathn(lst_bg,now_bg,j) ;
						if(pathn > 2)break ;
					}
					lst_bg = now_bg ;
					now_bg = j - 1 ;
					rest = d ;
				}
				rest -= x[j] - x[j - 1] ;
				if(lst_bg)
					if(pathn + ask_pathn(lst_bg,now_bg,j + 1) == 2){
//						cout << "lst_bg=" << lst_bg << " now_bg=" << now_bg << '\n' ;
//						cout << "have ans (" << i << "," << j << ") pathn=" << pathn << '\n' ;
						++ ans ;
					}
			}
		}
		cout << ans << '\n' ;
		return ;
	}
	void solveBaoli_same_sub(){
		if(n == 1){ cout << 0 << '\n' ; return ; }
		ll kn = d / (x[2] - x[1]),also = d % (x[2] - x[1]) ;
		if(kn <= 1){ cout << 0 << '\n' ; return ; }
		ll ans = 0 ;
		For(i,1,n){
			if(also == 0)ans += ll((n - i + 1) >= 2 * kn) ;
			else ans += max(0ll,(n - i) / kn - 1) ;
		}
		cout << ans << '\n' ;
		return ;
	}
	void Main(){
		cin >> n >> d ;
		For(i,1,n)cin >> x[i] ;
		if(cid <= 6){ solveBaoli1() ; return ; }
		if(7 <= cid && cid <= 10){ solveBaoli2() ; return ; }
		if(11 <= cid && cid <= 12){ solveBaoli_same_sub() ; return ; }
		solveBaoli1() ;
		return ;
	}
} ;
int main(){
	//如果需要快读，需要注释掉 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	freopen("migrate.in","r",stdin) ;
	freopen("migrate.out","w",stdout) ;
	int _ = 1 ;
	cin >> LIXUEAN::cid >> _ ;
	while(_ --)LIXUEAN::Main() ;
	return 0 ;
}
