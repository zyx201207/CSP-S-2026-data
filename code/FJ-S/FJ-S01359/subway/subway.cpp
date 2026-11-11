#include<bits/stdc++.h>
#define int long long 
#define PII pair<int,int>
using namespace std;
const int N=5005;
const int INF=-1e9;

int c,n,m,z,r,cnt;
int x,y,ans;
vector<PII> e[N];
//int dis[N];
//
//long long dij(int s,int t){
//	priority_queue<PII,vector<PII>,greater<PII>> q;
//	for(int i=1;i<=cnt;i++) dis[i]=INF;
//	dis[s]=0;
//	q.push({dis[s],s});
//	while(!q.empty()){
//		int d=q.top().first,u=q.top().second;
//		q.pop();
//		for(int i=0;i<=e[u].size();i++){
//			int v=e[u][i].first,w=e[u][i].second;
//			if(dis[v]>(dis[u]+w)){
//				dis[v]=dis[u]+w;
//				q.push({dis[v],v});
//			}
//		}
//	}
//	return dis[t];
//}
int vis[N];
void dfs(int u,int sum){
	if(u==y){
		ans=min(ans,sum);
	}
	for(int i=0;i<e[u].size();i++){
		int v=e[u][i].first,w=e[u][i].second;
		if(vis[v]) continue;
		vis[v]=1;
		dfs(v,sum+w);
		vis[v]=0;
	}
}

signed main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>z>>r;
	cnt=m;
	for(int i=1;i<=m;i++){
		int w;cin>>w;
		cnt++;
		e[i].push_back({cnt,w});
		e[cnt].push_back({i,w});
	}
	for(int i=1;i<=n;i++) {
		int k;cin>>k;
		for(int j=1;j<=k;j++){
			int a,t;cin>>a>>t;
			cnt++;
			e[a+m].push_back({cnt,t});
			e[cnt].push_back({a+m,t});
		}
		for(int j=0;j<k-1;j++){
			e[cnt-j].push_back({cnt-j-1,0});
			e[cnt-j-1].push_back({cnt-j,0});
		}
	}
	while(r--){
		cin>>x>>y;
		memset(vis,0,sizeof vis);
		ans=INT_MAX;
		vis[x]=1;
		dfs(x,0);
		vis[x]=0;
		cout<<ans<<endl;
	}
	return 0;
}
