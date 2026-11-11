#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 2000010
#define il inline
int n,d;
int x[N],dis[N],g[N];
bool vis[N];
vector<int> G[N];
void bfs(int s){
	for(int i=1;i<=n;i++) dis[i]=0x3f3f3f3f,vis[i]=false,g[i]=1;
	dis[s]=0;
	queue<int> q;
	q.push(s);
	g[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		if(vis[u]) continue;
		vis[u]=true;
		for(int v:G[u]){
			if(dis[u]+1<dis[v]){
				dis[v]=dis[u]+1;
				g[v]=g[u];
				q.push(v);
			}else if(dis[u]+1==dis[v]) g[v]+=g[u];
		}
	}
}
void solve(){
	int ans=0;
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		G[i].clear();
	}
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(x[j]-x[i]>d) break;
			G[i].emplace_back(j);
			G[j].emplace_back(i);
		}
	}
	for(int i=1;i<=n;i++){
		bfs(i);
		for(int j=i+1;j<=n;j++) if(g[j]==2) ++ans;
	}
	cout<<ans<<'\n';
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--){
		solve();
	}
	return 0;
}
/*
0 6
4 2
1 2 3 4
5 2
1 2 3 4 5
4 2
1 2 3 4
5 2
1 2 3 4 5
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

