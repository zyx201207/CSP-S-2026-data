#include<bits/stdc++.h>
using namespace std;
int c,T;
int n,k;
int ans;
vector<int> G[1010];
int num[1010],cnt=0;
bool vis[1010];
bool used[1010];
int f[1010];
int now;
void dfs2(int u,int fa){
	if(used[u]) f[u]=0;
	for(int i=0;i<G[u].size();i++){
		if(G[u][i]==fa) continue;
		dfs2(G[u][i],u);
		f[u]=min(f[u],f[G[u][i]]+1);
	}
}
void dfs3(int u,int fa){
	for(int i=0;i<G[u].size();i++){
		if(G[u][i]==fa) continue;
		f[G[u][i]]=min(f[G[u][i]],f[u]+1);
		dfs3(G[u][i],u);
	}
}
void check(){
	memset(vis,0,sizeof(vis));
	memset(f,10,sizeof(f));
	int t=0;
	for(int i=1;i<=cnt;i++){
		if(!vis[num[i]]) t++;
		if(t>2) return;
		for(int j=0;j<G[num[i]].size();j++) vis[G[num[i]][j]]=true;
	}
	now=0;
	dfs2(1,0);
	dfs3(1,0);
	for(int i=1;i<=n;i++) now=max(now,f[i]);
	ans=min(ans,now);
}
void dfs(int x,int sum){
	if(sum==k){
		check();
		return;
	}
	if(x>n) return;
	dfs(x+1,sum);
	num[++cnt]=x;
	used[x]=true;
	dfs(x+1,sum+1);
	cnt--;
	used[x]=false;
}
void solve(){
	ans=1e9;
	cin>>n>>k;
	for(int i=1;i<=n;i++) G[i].clear();
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	dfs(1,0);
	cout<<ans<<"\n";
}
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--) solve();
	return 0;
}
