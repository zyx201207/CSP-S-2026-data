#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2e6+10;
int C,T;
int n,d;
int x[N];
queue<int> q;
vector<int> g[N];
int dis[N],vis[N];
int ans[N],sum[N];
void bfs(int p){
	for(int i=1;i<=n;i++){
		dis[i]=ans[i]=INT_MAX;
		vis[i]=sum[i]=0;
	}
	dis[p]=0;
	q.push(p);
	while(!q.empty()){
		int u=q.front();
		q.pop();
//		if(vis[u]) continue;
//		vis[u]=1;
		for(int i=0;i<g[u].size();i++){
			int v=g[u][i];
			if(dis[u]+1<=dis[v]){
				dis[v]=dis[u]+1;
				if(v>u) q.push(v);
				if(dis[v]<ans[v]){
					ans[v]=dis[v];
					sum[v]=1;
				}else if(dis[v]==ans[v]){
					sum[v]++;
				}
			}
		}
	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&C,&T);
	while(T--){
		int mn=0;
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=n;i++){
			scanf("%lld",&x[i]);
			for(int j=i-1;j>=1;j--){
				if(x[i]-x[j]<=d){
					g[j].push_back(i);
				}
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=i;j<=n;j++){
				if(sum[j]==2){
					mn++;
				}
			}
		}
		printf("%lld\n",mn);
	}
	return 0;
} 
