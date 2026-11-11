#include<iostream>
#include<algorithm>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
using ll = long long;
const int M = 20005;
struct edge {
	int v,c,w;
};
struct node {
	int dis,u,c;
	
	bool operator>(const node& a) const {
		return dis>a.dis;
	}
};
int c,n,m,d,qr;
int s[M];
int dis[M][505];
bool vis[M][505];
edge g[M][505][3];
priority_queue<node,vector<node>,greater<node>> q;
void dijkstra(int s) {
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	dis[s][0]=0;
	q.push({0,s,0});
	while (!q.empty()) {
		int u=q.top().u,c=q.top().c;
		q.pop();
		if (vis[u][c])
			continue;
		vis[u][c]=true;
		for (int i=0; i<3; i++) {
			int v=g[u][c][i].v,vc=g[u][c][i].c,w=g[u][c][i].w;
			if (v==0)
				continue;
			if (dis[v][vc]>dis[u][c]+w) {
				dis[v][vc]=dis[u][c]+w;
				q.push({dis[v][vc],v,vc});
			}
		}
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	
	cin>>c>>n>>m>>d>>qr;
	for (int i=1; i<=m; i++)
		cin>>s[i];
	for (int i=1; i<=n; i++) {
		int k;
		int last=0;
		cin>>k;
		for (int j=1; j<=k; j++) {
			int a,t;
			cin>>a>>t;
			if (last!=0) {
				g[last][i][2]={a,i,0};
				g[a][i][1]={last,i,0};
			}
			g[a][0][0]={a,i,t};
			g[a][i][0]={a,0,t};
			last=a;
		}
	}
	for (int i=1; i<=qr; i++) {
		int x,y;
		cin>>x>>y;
		ll ans=s[x]+s[y];
		dijkstra(x);
		cout<<ans+dis[y][0]<<'\n';
	}
	
	return 0;
}
