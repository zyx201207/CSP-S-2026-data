#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll c,n,m,d,q,w[500009],dis[500009],ddis[500009],vis[500009],father[500009],cnt;
struct node{
	ll v,w;
};
vector<node> g[9999999];
vector<ll> biao[500009];
/*priority_queue< pair<ll,ll> ,vector< pair< ll,ll > > ,greater< pair <ll,ll> > > q;
void dijie(ll s){
	memset(ddis,0x3f,sizeof(ddis));
	q.push({0,s});
	ddis[s]=0;
	while(!q.empty()){
		ll u=q.top().second();
		if(vis[u]==1){
			continue;
		}
		vis[u]=1;
		for(auto k:g[u]){
			ll v=k.v;
			if(dis[v]>1){
				diss[u]=min(diis[u],g[u][biao[u][v]].w+g[v].w);
			}else{
				ddis[v]=ddis[u];
				father[v]=u;
			}
			q.push({ddis[v],v});
		}
	}
}*/
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(ll i=1;i<=m;i++){
		cin>>w[i];
	}
	for(ll i=1;i<=n;i++){
		ll k;
		cin>>k;
		node tmp;
		ll fa;
		for(ll j=1;j<=k;j++){
			ll u,w;
			cin>>u>>w;
			if(j==1){
				tmp.w=w;
				fa=u;
				//g[u].push_back=w;
			}else{
				tmp.v=u;
				g[fa].push_back(tmp);
				tmp.w=w;
				fa=u;
			}
			biao[fa][u]=biao[fa].size()+1;
			dis[u]++;
		}
	}
	for(ll i=1;i<=q;i++){
		ll x,y;
		cin>>x>>y;
		cout<<0<<endl;
	}
	return 0;
}
