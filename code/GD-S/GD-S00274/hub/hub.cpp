#include<bits/stdc++.h>
#define For(a,b,c) for(int a=b;a<=c;a++)
#define Fro(a,b,c) for(int a=b;a>=c;a--)
#define ms(a) memset(a,0,sizeof a)
#define int long long
#define pb push_back
#define Fopen(in) freopen(in".in","r",stdin),freopen(in".out","w",stdout);
using namespace std;
constexpr int N=1e6+5;

int n,k;
int fa[N],dep[N],top[N],son[N],sz[N];
vector<int> g[N],s[N];
vector<int> t[N];
void dfs1(int u,int f){
	fa[u]=f,dep[u]=dep[f]+1,sz[u]=1;
	t[u].pb(u);
	for(auto v:g[u]){
		if(v==f) continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[son[u]]<sz[v])
			son[u]=v;
		for(auto vv:t[v])
			t[u].pb(vv);
	}
	s[sz[u]].pb(u);
}
void dfs2(int u,int tp){
	top[u]=tp;
	if(son[u]) dfs2(son[u],tp);
	for(auto v:g[u]){
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	while(dep[top[u]]<dep[top[v]]){
		if(dep[u]<dep[v]) swap(u,v);
		u=fa[top[u]];
	}
	if(dep[u]<dep[v])
		return u;
	return v;
}
void solve(int c){
	// ms(son),ms(fa),ms(top),ms(dep),ms(sz);
	// For(i,1,n)
	// 	g[i].clear();
	cin>>n>>k;
	For(i,2,n){
		int u,v;
		cin>>u>>v;
		g[u].pb(v);
		g[v].pb(u);
	}
	if(k>=n)
		return cout<<"0\n",void();
	else if(k>=n/2)
		return cout<<"1\n",void();
	else
		return cout<<(int)(1+ceil((n-2*k)/8.0))<<'\n',void();
	// dfs1(1,0);
	// dfs2(1,1);
	int res=1;
	// for(auto i:s[k]){
	// 	cerr<<i<<" single \n";
	// 	int ans=0;
	// 	// cout<<t[i].size()<<'\n';
	// 	for(auto u:t[i]){
	// 		for(auto v:t[i]){
	// 			int l=lca(u,v);
	// 			cerr<<u<<" "<<v<<" lca="<<l<<'\n';
	// 			ans=max(ans,dep[u]+dep[v]-2*dep[l]);
	// 		}
	// 	}
	// 	res=min(res,ans);
	// }
	// For(i,1,n){
	// 	int ans=0;
	// 	if(sz[i]<k){
	// 		cerr<<sz[i]<<" "<<k-sz[i]<<" double \n";
	// 		for(auto j:s[k-sz[i]]){
	// 			if(j==i) continue;
	// 			For(i,1,n){

	// 			}
	// 			// cout<<t[j].size()<<'\n';
	// 			for(auto u:t[j]){
	// 				for(auto v:t[j]){
	// 					int l=lca(u,v);
	// 					cerr<<u<<" "<<v<<" lca="<<l<<'\n';
	// 					ans=max(ans,dep[u]+dep[v]-2*dep[l]);
	// 				}
	// 			}
	// 		}
	// 		for(auto u:t[i]){
	// 			for(auto v:t[i]){
	// 				int l=lca(u,v);
	// 					cerr<<u<<" "<<v<<" lca="<<l<<'\n';
	// 				ans=max(ans,dep[u]+dep[v]-2*dep[l]);
	// 			}
	// 		}
	// 	}
	// 	res=min(res,ans);
	// }
	cout<<res<<'\n';
}
signed main(){
	Fopen("hub")
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t=1;
	cin>>c>>t;
	while(t--)
		solve(c);
	return 0;  
}