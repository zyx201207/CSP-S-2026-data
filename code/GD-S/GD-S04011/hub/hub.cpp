#include<iostream>
#include<cstdio>
#include<vector>
#define N 510
using namespace std;
int n,k,ans,vis[N],fa[N],dis[N][N],dep[N];
vector<int>G[N];
int cx(int x){
	if(x==fa[x])return x;
	return fa[x]=cx(fa[x]);
}
void calc(){
	int cnt=0;
	for(int i=1;i<=n;i++)
		fa[i]=i,cnt+=vis[i];
	if(cnt!=k)return;
	cnt=0;
	for(int i=1;i<=n;i++){
		for(auto j:G[i]){
			if(vis[i]&&vis[j]){
				int x=cx(j),y=cx(i);
				if(x!=i)fa[x]=y;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(fa[i]==i&&vis[i])
			cnt++;
	if(cnt>2)return;
	int DD=0;
	for(int i=1;i<=n;i++){
		int dd=n;
		for(int j=1;j<=n;j++)
			if(vis[j])
				dd=min(dd,dis[i][j]);
//		cout<<i<<' '<<dd<<endl;
		DD=max(DD,dd);
	}
	ans=min(ans,DD);
	return;
}
void dfs(int nw){
	if(nw==n+1){
		calc();
		return;
	}
	vis[nw]=0;dfs(nw+1);
	vis[nw]=1;dfs(nw+1);
	vis[nw]=0;
}
void pre(int u,int ff){
	dep[u]=dep[ff]+1;
	fa[u]=ff;
	for(auto v:G[u]){
		if(v==ff)continue;
		pre(v,u);
	}
}
int lca(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	while(dep[u]>dep[v])u=fa[u];
	if(u==v)return u;
	while(u!=v)u=fa[u],v=fa[v];
	return u;
}
void solve(){
	cin>>n>>k;
	ans=n;
	int u,v;
	for(int i=1;i<=n;i++)
		G[i].clear();
	for(int i=1;i<n;i++){
		cin>>u>>v;
		G[u].push_back(v),G[v].push_back(u);
	}
	pre(1,0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dis[i][j]=dep[i]+dep[j]-2*dep[lca(i,j)];
	dfs(1);
	cout<<ans<<'\n';
	return;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int cid,T;
	cin>>cid>>T;
	while(T--)
		solve();
	return 0;
}
