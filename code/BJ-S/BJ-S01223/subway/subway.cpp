#include<bits/stdc++.h>
using namespace std;
const int N=1010;
struct node
{
	int to,edge;
};
int w[N];
int c,n,m,d,qu;
int dis[N],vis[N];
vector<node> a[N];
priority_queue<pair<int,int> > q;
void dijkstra(int s)
{
	for(int i=1;i<=m;i++) dis[i]=0x3f3f3f3f;
	dis[s]=0;
	memset(vis,0,sizeof vis);
	q.push({0,s});
	while(q.size())
	{
		int u=q.top().second;
		q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto v:a[u])
		{
			int y=v.to;
			int z=v.edge;
			if(dis[u]+z<dis[y])
			{
				dis[y]=dis[u]+z;
				q.push({-dis[y],y});
			}
		}
	}
}
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>qu;
	for(int i=1;i<=m;i++) cin>>w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		if(k==2)
		{
			int a1,a2,t1,t2;
			cin>>a1>>t1>>a2>>t2;
			a[a1].push_back({a2,t1+t2});
			a[a2].push_back({a1,t1+t2});
		}
	}
	while(qu--)
	{
		int x,y;
		cin>>x>>y;
		dijkstra(x);
		cout<<w[x]+w[y]+dis[y]<<"\n";
	}
	return 0;
}
