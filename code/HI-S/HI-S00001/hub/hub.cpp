#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,dis[1010][1010],d[100010],vis[1000010],ans=-1000000;
vector<int>g[1000010];
void dfs(int cnt,int sum){
	if(cnt==n+1){
		if(sum==k){
			int res=-10000000;
			for(int i=1;i<=n;i++) d[i]=1000000;
			for(int i=1;i<=n;i++){
				if(vis[i]){
					d[i]=0;
					continue;
				}
				for(int j=1;j<=n;j++){
					if(vis[j]&&i!=j){
						d[i]=min(d[i],dis[i][j]);
					}
				}
			}
			for(int i=1;i<=n;i++) res=max(res,d[i]);
			cout<<res<<"\n";
			ans=min(ans,res);
		}
		return;
	}
	vis[cnt]=1;
	dfs(cnt+1,sum+1);
	vis[cnt]=0;
	dfs(cnt+1,sum);
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ans=2e9;
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
				dis[i][j]=10000000;
			}
		}
		for(int i=1;i<=n-1;i++){
			int u,v;
			cin>>u>>v;
			g[u].push_back(v);
			g[v].push_back(u);
			dis[u][v]=1;
			dis[v][u]=1;
		}
		for(int k=1;k<=n;k++){
			for(int i=1;i<=n;i++){
				for(int j=1;j<=n;j++){
					dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		dfs(1,0);
		cout<<ans<<"\n";
	}
	return 0;
}


