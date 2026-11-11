#include <bits/stdc++.h>
using namespace std ;
namespace LIXUEAN{
	typedef long long ll ;
	typedef pair<ll,ll> Pir ;
	#define For(i,s,t)  for(ll i = s;i <= t;++ i)
	#define RFor(i,s,t) for(ll i = s;i >= t;-- i)
	#define fir         first
	#define sec         second
	//3000ms 1024M
	const ll CID = 20 + 5,T = 5 + 5,N = 1e6 + 5,SN = 2e6 + 5,K = N ;
	ll cid,n,k ;
	vector<ll> nxt[N] ;
	bool vis[N] ;
	ll dis[N] ;
	void dfs(ll p,ll code){
		vis[p] = true ;
		for(auto it : nxt[p])
			if(((code >> (it - 1)) & 1) && !vis[it])
				dfs(it,code) ;
		return ;
	}
	ll bfs(ll code){
		memset(dis,0x3f,sizeof(ll) * (n + 1)) ;
		queue<ll> q ;
		For(i,1,n)if((code >> (i - 1)) & 1)
			dis[i] = 0,q.push(i) ;
		while(!q.empty()){
			ll p = q.front() ; q.pop() ;
			for(auto it : nxt[p])
				if(dis[it] > n)dis[it] = dis[p] + 1,q.push(it) ;
		}
		ll maxx = 0 ;
		For(i,1,n)
			maxx = max(maxx,dis[i]) ;
		return maxx ;
	}
	void solveBaoli_pw2n(){
		ll pn = (1ll << n) - 1,ans = 1e8 ;//1e8 一定大于 n 
		vector<int> one(pn + 1,0) ;
		For(code,1,pn){
			one[code] = one[code & (code - 1)] + 1 ;
			if(one[code] != k)continue ;
			memset(vis,0,sizeof(bool) * (n + 1)) ;
			ll block = 0 ;
			For(i,1,n)if(((code >> (i - 1)) & 1) && !vis[i]){
				++ block ;
				if(block > 2)break ;
				dfs(i,code) ;
			}
			if(block > 2)continue ;
			ans = min(ans,bfs(code)) ;
		}
		cout << ans << '\n' ;
		return ;
	}
	void Main(){
		cin >> n >> k ;
		For(i,1,n)vector<ll>().swap(nxt[i]) ;
		ll u = 0,v = 0 ;
		For(i,1,n - 1){
			cin >> u >> v ;
			nxt[u].push_back(v) ;
			nxt[v].push_back(u) ; 
		}
		//15'
		if(cid <= 3){ solveBaoli_pw2n() ; return ; }
		solveBaoli_pw2n() ;
		return ;
	}
} ;
int main(){
	//如果需要快读，需要注释掉 
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0) ;
	freopen("hub.in","r",stdin) ;
	freopen("hub.out","w",stdout) ;
	int _ = 1 ;
	cin >> LIXUEAN::cid >> _ ;
	while(_ --)LIXUEAN::Main() ;
	return 0 ;
}
