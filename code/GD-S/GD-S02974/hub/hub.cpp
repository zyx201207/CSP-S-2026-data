#include<bits/stdc++.h>
using namespace std;
using ll=long long;
ll const maxn=1e6;
ll C,T;
ll n,k;
vector<ll>to[maxn+1];
ll fa[maxn+1];
ll siz[maxn+1];
ll dep[maxn+1];
ll mxd[maxn+1];
ll sxd[maxn+1];
ll dfn[maxn+1];
ll cnt;
void dfs(ll u){
	siz[u]=1;
	mxd[u]=0;
	dfn[u]=++cnt;
	for(auto v:to[u]){
		if(v==fa[u]){
			continue;
		}
		fa[v]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		if(mxd[v]+1>mxd[u]){
			sxd[u]=mxd[u];
			mxd[u]=mxd[v]+1;
		}
		else if(mxd[v]+1>sxd[u]){
			sxd[u]=mxd[v]+1;
		}
		siz[u]+=siz[v];
	}
}
namespace XZA{
	void calc(){
		cout<<(n-k+3)/4<<"\n";
	}
}
namespace BAOLI{
	ll ans;
	ll us[101];
	ll dis[101][101];
	struct DSU{
		ll fa[101];
		ll siz[101];
		inline ll find(ll a){
			return fa[a]==a?a:fa[a]=find(fa[a]);
		}
		void merge(ll u,ll v){
			u=find(u),v=find(v);
			if(u==v){
				return;
			}
			if(siz[u]<siz[v]){
				swap(u,v);
			}
			fa[v]=u;
			siz[u]+=siz[v];
		}
	};
	DSU dsu;
	void init(){
		for(ll u=1;u<=n;u++){
			dsu.fa[u]=u,dsu.siz[u]=1;
		}
		for(ll u=1;u<=n;u++){
			for(ll v=1;v<=n;v++){
				ll p=0;
				ll uu=u,vv=v;
				while(uu!=vv){
					if(dep[uu]<dep[vv]){
						swap(uu,vv);
					}
					uu=fa[uu];
					p++;
				}
				dis[u][v]=dis[v][u]=p;
			}
		}
	}
	void calc(){
		ll ret=0;
		for(ll u=1;u<=n;u++){
			dsu.fa[u]=u,dsu.siz[u]=1;
		}
		for(ll u=1;u<=n;u++){
			if(!us[u]){
				continue;
			}
			for(auto v:to[u]){
				if(!us[v]){
					continue;
				}
				dsu.merge(u,v);
			}
		}
		ll tot=0;
		for(ll u=1;u<=n;u++){
			if(!us[u]){
				continue;
			}
			tot+=dsu.find(u)==u;
		}
		if(tot>2){
			return;
		}
		for(ll u=1;u<=n;u++){
			if(us[u]){
				continue;
			}
			ll res=1e18;
			for(ll v=1;v<=n;v++){
				if(!us[v]){
					continue;
				}
				res=min(res,dis[u][v]);
			}
			ret=max(ret,res);
		}
		ans=min(ans,ret);
//		for(ll u=1;u<=n;u++){
//			cout<<us[u]<<" ";
//		}
//		cout<<"\n";
//		cout<<ret<<"\n";
	}
	void dfs(ll u,ll c){
		if(c==k){
			calc();
			return;
		}
		if(u>n||n-u+1+c<k){
			return;
		}
		us[u]=1;
		dfs(u+1,c+1);
		us[u]=0;
		dfs(u+1,c);
	}
}
void sol(){
	cin>>n>>k;
	for(ll i=1;i<=n;i++){
		to[i].clear();
		fa[i]=0;
		dep[i]=0;
		mxd[i]=0;
		siz[i]=0;
		dfn[i]=0;
	}
	cnt=0;
	for(ll i=1;i<n;i++){
		ll u,v;
		cin>>u>>v;
		to[u].push_back(v);
		to[v].push_back(u);
	}
	dep[1]=1;
	dfs(1);
	for(ll i=1;i<=n;i++){
		sort(to[i].begin(),to[i].end(),[](auto a,auto b){
			return siz[a]<siz[b];
		});
	}
	if(C>=13&&C<=14){
		XZA::calc();
		return;
	}
	if(n<=20){
		BAOLI::init();
		BAOLI::ans=1e18;
		BAOLI::dfs(1,0);
		cout<<BAOLI::ans<<"\n";
		return;
	}
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;
	while(T--){
		sol();
	}
	
	
	return 0;
}
