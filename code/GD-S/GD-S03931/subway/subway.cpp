#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
int c,n,m,d,q;
int a[N];
int ce[N],de[N];
bool vis[N];
int dis[20000][20000];
vector<pair<int,int> >e[N];
void init(int s)
{
	for(int i=1;i<=m;i++)dis[s][i]=0x3f3f3f3f,vis[i]=0;//为什么memset会报错啊 
	//memset(-0x3f,dis,sizeof(dis));
	//memset(0,vis,sizeof vis);
}
void dijkstra(int s)
{
	init(s);
	dis[s][s]=0;
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int> > >q;
	q.push({0,s});
	while(q.size())
	{
		int u=q.top().second;q.pop();
		if(vis[u]==1)continue;
		vis[u]=1;
		for(auto ed:e[u])
		{
			int v=ed.first,w=ed.second;
			if(dis[s][u]+w<dis[s][v])
			{
				dis[s][v]=dis[s][u]+w;
				q.push({dis[s][v],v});
			}
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
	{
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d%d",&ce[j],&de[j]);
			for(int z=1;z<j;z++)
			{
				e[ce[z]].push_back({ce[j],de[j]+de[z]});
				e[ce[j]].push_back({ce[z],de[j]+de[z]});
			}
		}
	}
	for(int i=1;i<=m;i++)
	{
		dijkstra(i);
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		printf("%d\n",dis[x][y]+a[x]+a[y]);
	}
	
	return 0;
}
/*
0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

32
17


0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3

35
16

*/
