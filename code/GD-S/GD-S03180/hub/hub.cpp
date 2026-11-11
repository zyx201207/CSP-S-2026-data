#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,k,u,v,ans;
int f[15][15],g[15][15],a[15];
bool vis[15],visq[15];
queue<int> q;
void bfs(int s){
	while(!q.empty())
		q.pop();
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		visq[u]=1;
		q.pop();
		for(int i=1;i<=n;++i)
			if(vis[i]&&!visq[i]&&g[u][i]!=0x3f3f3f3f)
				q.push(i);
	}
}
bool check(){
	memset(visq,0,sizeof(visq));
	int cnt=0;
	for(int i=1;i<=k;++i)
		if(!visq[a[i]]){
			cnt++;
			bfs(a[i]);
		}
	return cnt<=2;
}
void dfs(int x){
	if(x<=k){
		for(int i=1;i<=n;++i)
			if(!vis[i]){
				vis[i]=1;
				a[x]=i;
				dfs(x+1);
				vis[i]=0;
				a[x]=0;
			}
		return;
	}
	if(!check())
		return;
	int dis=0;
	for(int i=1;i<=n;++i){
		if(vis[i])
			continue;
		int dis1=1e9;
		for(int j=1;j<=n;++j)
			if(vis[j])
				dis1=min(dis1,f[i][j]);
		dis=max(dis,dis1);
	}
	ans=min(ans,dis);
}
void solve(){
	cin>>n>>k;
	memset(a,0,sizeof(a));
	memset(vis,0,sizeof(vis));
	memset(f,0x3f,sizeof(f));
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;++i)
		f[i][i]=g[i][i]=0;
	for(int i=1;i<n;++i){
		cin>>u>>v;
		f[u][v]=g[u][v]=1;
		f[v][u]=g[v][u]=1;
	}
	for(int k=1;k<=n;++k)
		for(int i=1;i<=n;++i)
			for(int j=1;j<=n;++j)
				f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
	ans=1e9;
	dfs(1);
	cout<<ans<<'\n';
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>C>>T;//15·Ö 
	if(C>3)
		return 0;
	while(T--)
		solve();
	return 0;
}

