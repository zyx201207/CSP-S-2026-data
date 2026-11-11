#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll maxn=1e6+5;
ll n,k;
vector<ll> e[maxn];
ll fa[maxn],dep[maxn],sz[maxn],wc[maxn],tp[maxn];
ll ff[maxn];
ll getf(ll x){return (x==ff[x]?x:ff[x]=getf(ff[x]));}
void dfs1(ll u,ll f){
	fa[u]=f;
	dep[u]=dep[f]+1;
	sz[u]=1;
	for(auto v:e[u]){
		if(v==f)continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[wc[u]]){
			wc[u]=v;
		}
	}
}
void dfs2(ll u,ll t){
	tp[u]=t;
	if(wc[u])dfs2(wc[u],t);
	for(auto v:e[u]){
		if(v==fa[u]||v==wc[u])continue;
		dfs2(v,v);
	}
}
ll lca(ll u,ll v){
	while(tp[u]!=tp[v]){
//		cout<<u<<' '<<v<<endl;
		if(dep[tp[u]]<dep[tp[v]])swap(u,v);
//		cout<<u<<' '<<v<<endl;
		u=fa[tp[u]];
	}
//	cout<<u<<' '<<v<<endl;
	if(dep[u]<dep[v])swap(u,v);
	return v;
}
void solve(){
	for(ll i=1;i<=n;i++){
		fa[i]=0,dep[i]=0,sz[i]=0,wc[i]=0,tp[i]=0;
		e[i].clear();
	}
	cin>>n>>k;
	for(ll i=1,u,v;i<n;i++){
		cin>>u>>v;
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	dfs2(1,1);
//	cout<<lca(1,4)<<endl;
//	for(ll i=1;i<=n;i++)cout<<i<<' '<<fa[i]<<' '<<dep[i]<<' '<<sz[i]<<' '<<wc[i]<<' '<<tp[i]<<'\n';
	ll res=n;
	for(ll msk=0;msk<(1<<n);msk++){
		if(__builtin_popcount(msk)!=k)continue;
		for(ll i=1;i<=n;i++)ff[i]=i;
		for(ll u=1;u<=n;u++){
			if(msk&(1<<(u-1))){
				ll fu=getf(u);
				for(auto v:e[u]){
					if(msk&(1<<(v-1))){
						ll fv=getf(v);
						ff[fv]=fu;
					}
				}
			}
		}
		ll cnt=0;
		for(ll i=1;i<=n;i++){
			if(msk&(1<<(i-1))){
				cnt+=(getf(i)==i);
			}
		} 
		if(cnt>2)continue;
//		for(ll i=1;i<=n;i++){
//			if(msk&(1<<(i-1))){
//				cout<<i<<' ';
//			}
//		}
//		cout<<'\n';
		ll mx=0;
		for(ll j=1;j<=n;j++){
			if(msk&(1<<(j-1)))continue;
			ll mn=n;
			for(ll i=1;i<=n;i++){
				if(msk&(1<<(i-1))){
					ll l=lca(i,j),dt=dep[i]+dep[j]-2*dep[l];
//					cout<<i<<' '<<j<<' '<<l<<' '<<dt<<'\n';
					mn=min(mn,dt);
				}
			}
			mx=max(mx,mn);
		}
//		cout<<mx<<'\n';
		res=min(res,mx);
	}
	cout<<res<<endl;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ll c,t;cin>>c>>t;
	while(t--)solve();
	return 0;
}
