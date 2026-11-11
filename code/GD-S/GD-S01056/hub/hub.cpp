#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int c,t,n,k,cct,dep[1005],f[1005],tp[1005],sz[1005],son[1005];
vector<int>e[1005];
bool dfs(int u,int fa,int s){
	if(u!=1&&((s>>(u-1))&1==0)&&((s>>(fa-1))&1==1))	cct++;
	if(cct>2)	return 0;
	for(int v:e[u])
		if(v!=fa)
			dfs(v,u,s);
	return 1;
}
void dfs1(int u,int fa){
	dep[u]=dep[fa]+1;
	f[u]=fa;
	sz[u]=1;
	for(int v:e[u]){
		if(v==fa)	continue;
		dfs1(v,u);
		if(sz[v]>sz[son[u]])	son[u]=v;
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int top){
	tp[u]=top;
	if(son[u])	dfs2(son[u],top);
	for(int v:e[u])
		if(v!=f[u])	dfs2(v,v);
}
int lca(int x,int y){
	while(tp[x]!=tp[y]){
		if(dep[tp[y]]>dep[tp[x]])	y=f[tp[y]];
		else x=f[tp[x]];
	}
	return dep[x]>dep[y]?y:x;
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int ans=1e18;
		cin>>n>>k;
		for(int i=1;i<=n;i++)	e[i].clear();
		for(int i=1;i<=n;i++)	dep[i]=son[i]=f[i]=tp[i]=sz[i]=0;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			e[u].push_back(v);
			e[v].push_back(u);
		}
		dfs1(1,0);
		f[1]=1;
		dfs2(1,1);
		for(int s=0;s<(1<<n);s++){
			int cnt=0;
			for(int j=15;j>=0;j--)	if((s>>j)&1)	cnt++;
			if(cnt!=k)	continue;
			cct=0;
			if(!dfs(1,0,s))	continue;
			int ass=0;
			cout<<s<<endl;
			for(int i=1;i<=n;i++){
				if((s>>(i-1))&1)	continue;
				for(int j=1;j<=n;j++){
					if(i!=j&&(s>>(j-1))&1)	ass=max(ass,dep[i]+dep[j]-dep[lca(i,j)]*2);
				}
			}
			ans=min(ans,ass);
		}
		cout<<ans<<endl;
	}
	return 0;
}

