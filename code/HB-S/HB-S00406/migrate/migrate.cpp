#include <bits/stdc++.h>
#define int long long
using namespace std;
int c, t;
int n, d;
int x[5005];
int dist[5005][5005];
vector<int> G[5005];
bool vis[5005];
void bfs(int s){
	queue<int> q;
	q.push(s);
	vis[s]=1;
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v: G[u]){
			if(vis[v]) continue;
			dist[s][v]=dist[s][u]+1;
			vis[v]=true;
			q.push(v);
		}
	}
}
signed main(){
	freopen("migrate3.in", "r", stdin);
	freopen("migrate3.out", "w", stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1; i<=n; i++) G[i].clear();
		memset(x, 0, sizeof(x));
		memset(dist, 0, sizeof(dist));
		for(int i=1; i<=n; i++) cin>>x[i];
		for(int i=1; i<=n; i++){
			for(int j=1; j<i; j++){
				if(x[i]-x[j]<=d) G[i].push_back(j), G[j].push_back(i);
			}
		}
		for(int i=1; i<=n; i++){
			memset(vis, 0, sizeof(vis));
			bfs(i);
		}
		int ans=0;
		for(int i=1; i<=n; i++){
			for(int j=i+1; j<=n; j++){
				int cnt=0;
				for(int k=i+1; k<j; k++){
					if(dist[i][j]==dist[i][k]+dist[k][j]) cnt++;
				}
				if(cnt==2) ans++;
			}
		}
		cout<<ans<<'\n';
	}
}
