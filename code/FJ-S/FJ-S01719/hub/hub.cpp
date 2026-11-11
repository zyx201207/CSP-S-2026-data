#include<bits/stdc++.h>
using namespace std;
const int N=105;
int n,k,dist[N][N],ans,vis[N];
pair<int,int>e[N];
int s[N];
void dfs(int step){
	if(step==k){
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=step;i++)vis[s[i]]=1;
		int cnt=0;
		for(int i=1;i<n;i++){
			int u=e[i].first,v=e[i].second;
			if(vis[u]&&vis[v])cnt++;
		}
		if(cnt<step-2)return;
		int ares=0;
		for(int i=1;i<=n;i++){
			int res=1e9;
			for(int j=1;j<=k;j++)
				res=min(res,dist[i][s[j]]);
			ares=max(ares,res);
		}
		ans=min(ans,ares);
		return;
	}
	for(int i=s[step]+1;i<=n;i++){
		s[step+1]=i;
		dfs(step+1);
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	int c,t;cin>>c>>t;while(t--){
		ans=1e9;
		cin>>n>>k;
		memset(dist,0x3f,sizeof(dist));
		for(int i=1;i<=n;i++)dist[i][i]=0;
		for(int i=1,u,v;i<n;i++){
			cin>>u>>v;
			e[i]={u,v};
			dist[u][v]=dist[v][u]=1;
		}
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++)
					dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
		dfs(0);
		cout<<ans<<'\n';
	}
}
