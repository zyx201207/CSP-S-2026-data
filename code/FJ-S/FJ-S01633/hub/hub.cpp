#include<bits/stdc++.h>
using namespace std;
#define N 100005
typedef long long ll;
inline ll read(){
	register ll x=0,f=1ll;char ch=getchar();
	while(!isdigit(ch)){if (ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){x=(x<<3ll)+(x<<1ll)+(ch^48);ch=getchar();}
	return x*f;
}
int C,T;
int n,k,ans;
int f[N],tp[N],hs[N],sz[N],dep[N];
bool flag[N],vis[N];
vector<int> G[N];
inline void dfs1(int u,int p){
	dep[u]=dep[p]+1;f[u]=p;sz[u]=1;
	for(int v:G[u]){
		if (v==p)continue;
		dfs1(v,u);
		sz[u]+=sz[v];
		if (sz[v]>sz[hs[u]])hs[u]=v;
	}
}
inline void dfs2(int u,int t){
	tp[u]=t;
	if (!hs[u])return;
	dfs2(hs[u],t);
	for(int v:G[u]){
		if (v==f[u]||v==hs[u])continue;
		dfs2(v,v);
	}
}
inline int lca(int u,int v){
	for(;tp[u]!=tp[v];u=f[tp[u]])
		if (dep[tp[u]]<dep[tp[v]])swap(u,v);
	return dep[u]<dep[v]?u:v;
}
inline int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[lca(u,v)];
}
inline int count(int x){
	int ans=0;
	while(x)ans+=(x&1),x>>=1;
	return ans;
}
inline int calc(int u,int p){
	for(int v:G[u]){
		if (v==p)continue;
		if (flag[v]&&!vis[v])vis[v]=1;
		calc(v,u);
	}
}
inline void clear(int n){
	ans=2e9;
	memset(f,0,sizeof(f));
	memset(tp,0,sizeof(tp));
	memset(hs,0,sizeof(hs));
	memset(dep,0,sizeof(dep));
	for(int i=1;i<=n;i++)G[i].clear();
}
inline void solve(){
	n=read();k=read();
	clear(n);
	for(int i=1;i<n;i++){
		int u=read(),v=read();
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs1(1,0);dfs2(1,1);
	for(int mask=0;mask<(1<<n);mask++){
		if (count(mask)!=k)continue;
		memset(vis,0,sizeof(vis));
		memset(flag,0,sizeof(flag)); 
		for(int i=1;i<=n;i++)
			if ((mask>>(i-1))&1)flag[i]=1;
		int tmp=0;
		for(int i=1;i<=n;i++)
			if (flag[i]&&!vis[i])calc(i,0),tmp++;
		if (tmp>2)continue;
		int anss=0;
		for(int i=1;i<=n;i++){
			if (flag[i])continue;
			int res=2e9;
			for(int j=1;j<=n;j++)
				if (flag[j])res=min(res,dis(i,j));
			anss=max(anss,res);
		}
		ans=min(ans,anss);
	}
	cout<<ans<<'\n';
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();T=read();
	while(T--)solve();
	return 0;
}
/*
0 1
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10

*/
