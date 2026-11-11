//8 pts
#include<bits/stdc++.h>
using namespace std;
long long a[2005];
vector <int> g[2005];
int dist[2005]; //从指定起点出发的地方到其他点的最短路。
bool vis[2005];
void bfs(int st) {
	memset(vis,0,sizeof vis);
	memset(dist,0x3f,sizeof dist);
	queue <int> q;
	vis[st] = 1,dist[st] = 0;
	q.push(st);
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		for (int i = 0;i<g[u].size();i++) {
			int v = g[u][i];
			if (vis[v]) continue;
			dist[v] = dist[u]+1;
			vis[v] = 1;
			q.push(v);
		}
	}
}
int ways(int st,int now) {
	if (st==now) return 1;
	int sum = 0;
	for (int i = 0;i<g[now].size();i++) {
		int to = g[now][i];
		if (dist[to]+1==dist[now]) sum+=ways(st,to);
	}
	return sum;
}
void solve() {
	//若(i,j)间有2条路径，则在他们的最短路上，有且仅有一个点出度为2，其余点出度必须为1。 
	memset(dist,0x3f,sizeof dist);
	memset(vis,0,sizeof vis);
	int n,d;
	int ans = 0;
	cin>>n>>d;
	for (int i = 1;i<=n;i++) g[i].clear();
	for (int i = 1;i<=n;i++) cin>>a[i];
	for (int i = 1;i<=n;i++)
		for (int j = i+1;j<=n;j++)
			if (a[j]-a[i]<=d) {
				g[i].push_back(j);
				g[j].push_back(i);
			}
	for (int i = 1;i<=n;i++) {
		bfs(i);
		for (int j = i+1;j<=n;j++)
			if (ways(i,j)==2) ans++;
	}
	cout<<ans<<endl;
}
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	int c,t;
	cin>>c>>t;
	while (t--) solve();
}
