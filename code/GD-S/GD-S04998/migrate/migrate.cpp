#include<bits/stdc++.h>
using namespace std;
int n,d,a[505],dis[505][505],cnt[505][505],ans;//dis:从第i个岛屿到第j个岛屿的最短路径 cnt:从第i个岛屿到第j个岛屿最短路径的数量
bool vis[505];
vector<int>g[505];
int dfs(int u,int p,int e,int ans,int lim,int step){
	if(u==p) return ans;
	if(u==e){
		if(step==lim){
			ans++;
			return ans;
		}
	}
	vis[u]=true;
	for(int i=0;i<g[u].size();i++){
		int v=g[u][i];
		if(!vis[v]){
			dfs(v,u,e,ans,lim,step+1);
			vis[v]=false;
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>n>>d;
 	for(int i=1;i<=n;i++) cin>>a[i];
 	for(int i=1;i<=n;i++){
 		for(int j=1;j<=n;j++){
 			if((abs(a[i]-a[j])/d)%2==0) dis[i][j]=abs(a[i]-a[j])/d;
 			else dis[i][j]=abs(a[i]-a[j])/d+1;
		}
	}
	 for(int i=1;i<=n;i++){
 		for(int j=1;j<=n;j++){
 			g[i].push_back(j);
		}
	}
	for(int i=1;i<=n;i++){
 		for(int j=1;j<=n;j++){
 			memset(vis,false,sizeof(vis));
 			cnt[i][j]=dfs(i,-1,j,0,dis[i][j],0);
 			if(cnt[i][j]==2) ans++;
		}
	}
	cout<<ans;
	return 0;

}
