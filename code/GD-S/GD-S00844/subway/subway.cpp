#include<bits/stdc++.h>
using namespace std;
using ll=long long;
using arr=array<ll,2>;
const ll N=3010+10;
const ll x=1510+10;
const ll K=510*1010+100;
ll m,n,value[N],c,d,q,dis[510][N];
vector<arr>g[K];
void solve(){
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>value[i];
	}
	ll f=1;
	for(ll i=1;i<=n;i++){
		ll k;cin>>k;
		ll lst=-1;
		for(ll j=1;j<=k;j++){
			ll v,w;cin>>v>>w;
			if(j!=1)g[lst].push_back({0,(i-1)*m+v});
			g[x+v].push_back({w,(ll)((i-1)*m+v)});
			g[(i-1)*m+v].push_back({w,x+v});
			lst=(i-1)*m+v;
		}
	}
	for(ll st=1;st<=n;st++){
		for(ll i=1;i<=x+m;i++){
			dis[st][i]=1e18;
		}
		priority_queue<arr,vector<arr>,greater<arr>>pq;
		pq.push({0,x+st});
		while(pq.size()){
			auto now=pq.top();pq.pop();
			ll u=now[1],w=now[0];
			if(dis[st][u]<=w) continue;
			dis[st][u]=w;
		//cout<< u<<" ";
			for(auto v:g[u]){
				if(dis[st][v[1]]>w+v[0]){
					pq.push({w+v[0],v[1]});
				}
			}
		}
	}
	while(q--){
		ll st,ed;cin>>st>>ed;
		//cout<<"\n";
		cout<<dis[st][ed+x]+value[ed]+value[st]<<"\n";
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	//ll t;cin>>t;while(t--)
	solve();
	return 0;
}
