#include<bits/stdc++.h>
using namespace std;
const int N=1005;
int n,k;
int dis[N][N],mark[N],vis[N];
vector<int> g[N];
void dfs(int u,int fa,int rt){
	for(auto v:g[u]){
		if(v==fa) continue;
		dis[rt][v]=dis[rt][u]+1;
		dfs(v,u,rt);
	}
}
void dfscheck(int u,int fa){
	vis[u]=1;
	for(auto v:g[u]){
		if(v==fa||vis[v]||!mark[v]) continue;
		dfscheck(v,u);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,T;
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v),g[v].push_back(u);
		}
		for(int i=1;i<=n;i++) dfs(i,0,i);
		int ans=2e9;
		for(int s=0;s<(1<<n);s++){
			int cnt=0;
			for(int i=1;i<=n;i++) mark[i]=((s>>(i-1))&1),cnt+=mark[i],vis[i]=0;
			if(cnt!=k) continue;
			cnt=0;
			for(int i=1;i<=n;i++) if(mark[i]&&!vis[i]) cnt++,dfscheck(i,0);
			if(cnt>2) continue;
			int mx=0;
			for(int i=1;i<=n;i++){
				int mn=2e9;
				for(int j=1;j<=n;j++) if(mark[j]) mn=min(mn,dis[i][j]);
				mx=max(mx,mn);
			}
			ans=min(ans,mx);
		}
		cout<<ans<<'\n';
	}
	return 0;
}
