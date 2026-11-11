#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,w[505];
int r[505][505];
int g[505][505];
bool vis[505];
int ans=0;
void dfs(int u,int s,int t,int road){
	if(u==t){
		ans=min(ans,s);
		return;
	}for(int i=1;i<=m;i++){
		if(g[u][i]==0x3f3f3f3f3f3f3f3f)continue;
		if(vis[i])continue;
		vis[i]=1;
		if(road!=r[u][i])dfs(i,s+g[u][i]+g[u][u],t,r[u][i]);
		else dfs(i,s+g[u][i],t,road);
		vis[i]=0;
	}
}
signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	memset(g,0x3f,sizeof(g));
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)cin>>w[i];
	for(int i=1;i<=n;i++){
		int k;
		cin>>k;
		int a,t;
		cin>>a>>t;
		g[i][a]=g[a][i]=t;
		r[a][i]=r[i][a]=i;
		for(int j=2;j<=k;j++){
			int x=a;
			cin>>a>>t;
			r[a][x]=r[x][a]=i;
			g[x][a]=g[a][x]=t;
		}
	}for(int i=1;i<=q;i++){
		int x,y;
		cin>>x>>y;
		ans=1e9;
		dfs(x,w[x]+w[y],y,-1);cout<<ans<<'\n';
	}
	return 0;
}
