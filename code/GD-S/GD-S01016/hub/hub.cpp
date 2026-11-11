#include<bits/stdc++.h>
using namespace std;
#define int long long
#define File(x) (freopen(x".in","r",stdin),freopen(x".out","w",stdout))
#define ft first
#define sd second
inline int read(){char ch=getchar();int f=1,x=0;while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}while(ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();return f*x;}
const int N=1e6+5,inf=1e18;
int n,K,ans;
int dfn[N],cnt,id[N];
int col[N];
vector<int>g[N];
//
int vis[N];
int dep[N];
void dfs2(int u,int fa,int c){
	vis[u]=1;
	for(auto v:g[u]){
		if(col[v]!=c||v==fa)continue;
		dfs2(v,u,c);
	}
}
void dfs3(int u,int fa,int c){
	dep[u]=0;
	for(auto v:g[u]){
		if(col[v]!=c||v==fa)continue;
		dfs3(v,u,c),dep[u]=max(dep[u],dep[v]+1);
	}
}
int solve(int RT,int c,int k){
	int mi=inf,rt,Cnt=0;
	for(int i=1;i<=n;i++)vis[i]=0;
	dfs2(RT,0,c);
	for(int i=1;i<=n;i++){
		if(!vis[i])continue;
		vis[i]=0,Cnt++;
		dfs3(i,0,c);
		if(dep[i]<=mi)rt=i,mi=dep[i];
	}
	dfs3(rt,0,c);
	priority_queue<pair<int,int>>q;
	q.push({dep[rt],rt});
	while(k--&&!q.empty()){
		int dis=q.top().ft,u=q.top().sd;q.pop();
		vis[u]=1;
		for(auto v:g[u])
			if(!vis[v]&&col[v]==c)q.push({dep[v],v});
	}
	if(q.empty())return 0;
	else return q.top().ft+1;
} 
void dfs(int u,int fa){
	dfn[u]=++cnt,id[cnt]=u;
	for(auto v:g[u])
		if(v!=fa)dfs(v,u);
	for(int i=dfn[u];i<=cnt;i++)
		col[id[i]]=1;
	if(u!=1)
		for(int k=1;k<K;k++)
			ans=min(ans,max(solve(u,1,k),solve(fa,0,K-k)));
	else ans=min(ans,solve(u,1,K));
	for(int i=dfn[u];i<=cnt;i++)
		col[id[i]]=0;
}
void work(){
	n=read(),K=read(),ans=inf,cnt=0;
	for(int i=2,u,v;i<=n;i++)
		u=read(),v=read(),g[u].push_back(v),g[v].push_back(u);
	dfs(1,0);
	cout<<ans<<"\n";
}
void clear(){
	for(int i=1;i<=n;i++)
		g[i].resize(0);
}
signed main(){
	File("hub");
	int c_id=read(),_=read();
	while(_--)work(),clear();
	return 0;
}