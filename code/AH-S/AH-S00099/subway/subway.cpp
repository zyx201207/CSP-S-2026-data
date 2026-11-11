//20 pts
#include<bits/stdc++.h>
using namespace std;
#define N 1005
#define int unsigned int
struct Node{
	int line,time;
	bool operator< (const Node &b) const {
		return time<b.time;
	}
	Node (int _line,int _time) {
		line = _line,time = _time;
	}
};
int c,n,m,d,q;
int w[N];
long long dist[N][N];
vector <Node> g[N];
signed main() {
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	if (m>1000) {
		cout<<"Error\n";
		return 0;
	}
	//输入
	for (int i = 1;i<=m;i++)
		for (int j = 1;j<=m;j++)
			dist[i][j] = 2147483647;
	for (int i = 1;i<=m;i++) dist[i][i] = 0;
	for (int i = 1;i<=m;i++) cin>>w[i];
	for (int i = 1;i<=n;i++) {
		int k;
		cin>>k;
		for (int j = 1;j<=k;j++) {
			int a,t;
			cin>>a>>t;
			g[a].push_back(Node(i,t));
		}
	}
	//建边
	for (int i = 1;i<=m;i++) {
		if (g[i].size()==1) continue;
		for (int j = 0;j<g[i].size();j++)
			for (int k = j+1;k<g[i].size();k++) {
				int lu = g[i][j].line,lv = g[i][k].line;
				long long tu = g[i][j].time,tv = g[i][k].time;
				dist[lu][lv] = min(dist[lu][lv],tu+tv);
			}
	}
	for (int i = 1;i<=n;i++)
		for (int j = i+1;j<=n;j++)
			dist[j][i] = dist[i][j];
	//floyd求最短路
	for (int i = 1;i<=n;i++)
		for (int j = 1;j<=n;j++)
			if (i!=j)
				for (int k = 1;k<=n;k++)
					if (i!=k&&j!=k)
						dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
	//对于每次输出答案
	for (int i = 1;i<=q;i++) {
		int x,y;
		long long ans = 0xffffffffffffff;
		cin>>x>>y;
		for (int j = 0;j<g[x].size();j++)
			for (int k = 0;k<g[y].size();k++) {
				int u = g[x][j].line,v = g[y][k].line;
				long long t1 = g[x][j].time,t2 = g[y][k].time;
				ans = min(dist[u][v]+t1+t2,ans);
			}
		cout<<ans+w[x]+w[y]<<endl;
	}
	return 0;
}
