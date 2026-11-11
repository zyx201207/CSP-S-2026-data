#include <bits/stdc++.h>
using namespace std;
#define LL long long

const int N = 510,M = 50010,D = 25;
const LL inf = 1e18;

struct Node{
	int u;
	LL dis;
	bool operator < (const Node& cmp) const{
		return dis > cmp.dis;
	}
};

int ceshi,n,m,d,q,l[N];
LL w[M];
vector<int> g[M];
int a[N][M]; LL t[N][M]; LL pos[N][M];
LL dist[D * D + M + 10];
vector<pair<int,LL>> lg[D * M];

void add(int x,int y,LL z)
{
	//cout<<x<<"<->"<<y<<":"<<z<<"\n";
	lg[x].push_back({y,z});
	lg[y].push_back({x,z});
}
int to(int x,int lv)
{
	return x + (lv - 1) * d;
}
LL dijkstra(int st,int ed)
{
	//cout<<"M:"<<d * d + m + 5<<"\n";
	for (int i = 1;i <= d * d + m + 5;i++) dist[i] = inf;
	dist[st] = 0;
	priority_queue<Node> q;
	q.push({st,0});
	while (!q.empty())
	{
		Node c = q.top(); q.pop();
		int u = c.u;
		if (dist[u] < c.dis) continue;
		for (auto p : lg[u]){
			int v = p.first; LL w = p.second;
//			cout<<u<<"--->"<<v<<":"<<w<<" ";
//			cout<<dist[u]<<" "<<dist[v]<<"\n";
			if (dist[u] + w < dist[v]){
				dist[v] = dist[u] + w;
				q.push({v,dist[v]});
				//cout<<"y\n";
			}
			//else cout<<"n\n";
		}
	}
	return dist[ed];
}

int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%d%d%d%d%d",&ceshi,&n,&m,&d,&q);
	for (int i = 1;i <= m;i++) scanf("%lld",&w[i]);
	for (int i = 1;i <= n;i++)
	{
		cin>>l[i];
		for (int j = 1;j <= l[i];j++){
			cin>>a[i][j]>>t[i][j];
			pos[i][a[i][j]] = t[i][j];
			g[a[i][j]].push_back(i);
		}
		for (int j = 1;j < l[i];j++){
			add(to(a[i][j],i),to(a[i][j + 1],i),0);
		}
	}
	for (int i = 1;i <= m;i++){
		for (int j = 0;j < (int)g[i].size();j++){
			add(to(i,g[i][j]),to(i,d + 1),pos[g[i][j]][i]);
		}
	}
	while (q--)
	{
		int x,y; cin>>x>>y;
		LL ret = dijkstra(to(x,d + 1),to(y,d + 1));
		cout<<w[x] + w[y] + ret<<"\n";
	}
	return 0;
}
