#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
const int inf=1e18;
int c,t;
int n,d;
int ans;
int a[N];
bool vis[N];
int dis[N];
int cnt[N];
vector<int> e[N];

void bfs(int s){
	for(int i=1;i<=n;i++) dis[i]=inf;
	for(int i=1;i<=n;i++) vis[i]=0;
	for(int i=1;i<=n;i++) cnt[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>> >q;
	q.push({0,s});
	dis[s]=0;
	while(q.size()){
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int v:e[u]){
			if(dis[v]>dis[u]+1){
				dis[v]=dis[u]+1;
				cnt[v]++;
				q.push({dis[v],v});
			}
			else if(dis[v]==dis[u]+1) cnt[v]++;
			
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		ans=0;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				int t=a[j]-a[i];
				if(t<=d) e[i].push_back(j);
			}
		}
		for(int i=1;i<=n;i++){
			bfs(i);
			for(int j=1;j<=n;j++){
				if(cnt[j]==2) ans++;
			}
		}
		cout<<ans<<'\n';
		for(int i=1;i<=n;i++) e[i].clear();
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
