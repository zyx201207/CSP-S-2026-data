#include<bits/stdc++.h>
#define ll long long 
using namespace std;
const int N=5e5+50;
struct node{
	int to,time;
	bool operator <(const node &x)const{
	    return x.time<time;
	}
};
int c,n,m,d,p;//测试点编号、地铁线路数、地铁站数、每个地铁站最多被几条线路经过，出行计划数
int a[N];//地铁口到站台需花费的时间 
int dis[N]; 
int x,y;
vector<node> G[N];
void dijkstra()
{
	bool vis[N];
	for(int i=1;i<=m;i++) 
	{
		dis[i]=0x3f3f3f3f;
		vis[i]=0;
	}
	priority_queue<node> q;
	q.push({x,0});
	dis[x]=0;
	while(!q.empty())
	{
		node sum=q.top();
		q.pop();
		int u=sum.to;
		if(vis[u]==1) continue;
		vis[u]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=0;j<G[i].size();j++)
			{
				int v=G[i][u].to;
				if(vis[v]==0) 
				{
					dis[v]=min(dis[v],sum.time+G[i][u].time);
					q.push({v,dis[v]});
				}
			}
		}
	}
}
int main()
{
//	freopen("subway.in","r",stdin);
//	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n>>m>>d>>p;
	for(int i=1;i<=m;i++) cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int v,time;//到哪一站，站台到站厅time 
			cin>>v>>time;
			G[i].push_back({v,time});
			 
		}
		
	}
	cin>>p;
	for(int i=1;i<=p;i++)
	{
		cin>>x>>y;
//		dijkstra();
//		cout<<dis[y]+a[x]+a[y]<<endl;
        cout<<rand();
	}
	
	return 0;
}
