#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=2000009;
int n,m,T,c;
vector<int> g[N];
int dis[N],dp[N],pos[N];
int bfs(int s){
	for(int i=1;i<=n;i++){
		dis[i]=1e9;
		dp[i]=0;
	}
	dis[s]=0;
	dp[s]=1;
	queue<int> q;
	q.push(s);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(int v:g[u]){
			if(dis[v]==dis[u]+1) dp[v]+=dp[u];
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				dp[v]=dp[u];
				q.push(v);
			}
		}
	}
	int tmp=0;
	for(int i=s;i<=n;i++) tmp+=(dp[i]==2);
	return tmp;
}
void solve(){
	for(int i=1;i<=n;i++) g[i].clear();
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(pos[j]-pos[i]>m) break;
			g[i].push_back(j);
			g[j].push_back(i);
		}
	}
	int ans=0;
	for(int i=1;i<=n;i++) ans+=bfs(i);
	cout<<ans<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--){
		cin>>n>>m;
		for(int i=1;i<=n;i++) cin>>pos[i];
		solve();
	} 
	return 0;
} 
