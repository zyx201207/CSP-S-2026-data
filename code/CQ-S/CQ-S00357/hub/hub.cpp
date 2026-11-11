#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll N=1e6+10;
ll n,k,c,t,mx,ans;
ll dis[N],vis[N],fa[N];
ll find(ll x){
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
vector<ll>e[N];
void add(ll u,ll v){
	e[u].push_back(v);
	e[v].push_back(u);
}
void dfs(ll u,ll f){
	dis[u]=min(dis[u],dis[f]+1);
	for(ll v:e[u]){
		if(v==f)continue;
		dfs(v,u);
		dis[u]=min(dis[v]+1,dis[u]);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin.tie(0)->ios::sync_with_stdio(false);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=LLONG_MAX; 
		for(ll i=1;i<=n;i++)e[i].clear();
		for(ll i=1;i<n;i++){
			ll u,v; 
			cin>>u>>v;
			add(u,v);
		}
		for(ll i=0;i<(1<<n);i++){
			ll c=__builtin_popcount(i);
			if(c!=k)continue;
			vector<ll>vc; 
			ll cnt=k;
			for(ll j=0;j<n;j++){
				if((i>>j)&1)vc.push_back(j+1),vis[j+1]=1,fa[j+1]=j+1;
				else vis[j+1]=0;
			}
			for(ll x:vc){
				for(ll v:e[x]){
					if(vis[v]){
						ll fu=find(x),fv=find(v);
						if(fu!=fv)fa[fu]=fv,cnt--;
					}
				}
			}
			if(cnt<=2){
				mx=0;
				for(ll i=0;i<=n;i++){
					if(!vis[i])dis[i]=1e9;
					else dis[i]=0;
				}
				dfs(1,0);
				dfs(1,0);
				for(ll i=1;i<=n;i++)mx=max(mx,dis[i]);
				ans=min(ans,mx);
			}
		}
		cout<<ans<<'\n';
	}
	return 0;
}
/*

*/

