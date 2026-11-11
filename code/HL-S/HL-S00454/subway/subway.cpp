#include<bits/stdc++.h>
using namespace std ;
typedef long long ll ;
const int maxn = 5e5+10 ;
ll dis[maxn],ans[maxn],T,c,n,m,d,q ;
vector<ll> G[maxn] ;
void dij(ll s){
	queue<ll> q ;
	q.push(s) ;
	for(ll i=1;i<=m;i++){
		ans[i]=dis[i] ;
	}
	while(!q.empty()){
		ll pos=q.front() ;
		q.pop() ;
		for(auto v:G[pos]){
			q.push(v) ;
			if(ans[v]+T+T<ans[pos]){
				ans[pos]=ans[v]+T+T ;
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin) ;
	freopen("subway.out","w",stdout) ;
	ios::sync_with_stdio(false) ;
	cin.tie(0),cout.tie(0) ;
	cin>>c>>n>>m>>d>>q ;
	for(int i=1;i<=m;i++){
		cin>>dis[i] ;
	}
	for(int i=1;i<=n;i++){
		ll k,last_a ; cin>>k ;
		cin>>last_a>>T ;
		for(int j=2;j<=k;j++){
			ll a,t ; cin>>a>>t ;
			G[last_a].push_back(a),G[a].push_back(last_a) ;
			last_a=a ;
		}
	}
	while(q--){
		memset(ans,0,sizeof ans) ;
		ll l,r ; cin>>l>>r ;
		dij(l) ;
		cout<<ans[r]<<'\n' ;
	}
	return 0 ;
}
