#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,Q,tot,val[1000010],oth[2000010],dis[4010][4010],dis2[40040],vis[2010],vis2[40040];
vector<pair<long long,long long> >G[2000010];
priority_queue<pair<long long,long long> >q;
void dij(long long s)
{
	dis[s][s]=0;q.push({0,s});
	while(!q.empty())
	{
		long long u=q.top().second;q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(auto [v,w]:G[u])
		{
			if(dis[s][v]>dis[s][u]+w)
			{
				dis[s][v]=dis[s][u]+w;
				q.push({-dis[s][v],v});
			}
		}
	}
}
void dij2(long long s)
{
	memset(vis2,0,sizeof vis2);
	memset(dis2,0x3f,sizeof dis2);
	dis2[s]=0;q.push({0,s});
	while(!q.empty())
	{
		long long u=q.top().second;q.pop();
		if(vis2[u]) continue;
		vis2[u]=1;
		for(auto [v,w]:G[u])
		{
			if(dis2[v]>dis2[u]+w)
			{
				dis2[v]=dis2[u]+w;
				q.push({-dis2[v],v});
			}
		}
	}
}
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	cin>>c>>n>>m>>d>>Q;
	for(int i=1;i<=m;i++)
	{
		cin>>val[i];
	}
	if(c<=11)
	{
		tot=m;memset(dis,0x3f,sizeof dis);
		for(int i=1,k;i<=n;i++)
		{
			cin>>k;
			for(int j=1,x,w;j<=k;j++)
			{
				cin>>x>>w;
				G[x].push_back({++tot,w});
				G[tot].push_back({x,w});
				if(j!=1)
				{
					G[tot].push_back({tot-1,0});
					G[tot-1].push_back({tot,0});
				}
			}
		}
		for(int i=1;i<=m;i++)
		{
			memset(vis,0,sizeof vis);
			dij(i);
		}
//		for(int i=1;i<=m;i++)
//		{
//			for(int j=i;j<=m;j++)
//			{
//				cout<<i<<" "<<j<<" "<<dis[i][j]<<'\n';
//			}
//		}
		for(int i=1;i<=Q;i++)
		{
			long long x,y;
			cin>>x>>y;
			cout<<val[x]+val[y]+dis[x][y]<<'\n';
		}
	}
	else
	{
		tot=m;
		for(int i=1,k;i<=n;i++)
		{
			cin>>k;
			for(int j=1,x,w;j<=k;j++)
			{
				cin>>x>>w;
				G[x].push_back({++tot,w});
				G[tot].push_back({x,w});
				if(j!=1)
				{
					G[tot].push_back({tot-1,0});
					G[tot-1].push_back({tot,0});
				}
			}
		}
		for(int i=1,x,y;i<=Q;i++)
		{
			cin>>x>>y;
			dij2(x);
			cout<<dis2[y]+val[x]+val[y]<<'\n';
		}
	}
	return 0;
}
/*
在说什么。。。
复杂的题面
n<=500,m<=sigma k<=5e5 ,d<=20,q<=1e5 
分析一下，有地铁站，地铁站包括地铁口和站厅与i个线路的站台
每个地铁站都有个w_v记录其地铁口到站厅的时间以及站厅到站台i的时间(不太清楚这个东西的意义)
有k条线路，在某站换乘时需要花费i站台到站厅的时间加上站厅到j站台的时间 
有q次询问，每次问x到y的最小时间(坐地铁不算在内，只有进出站与换乘时间)

先考虑d较小的情况，d=2时，每个点最多两条线路，换乘花费定死了，直接在所有换乘站上搞一个换乘权值跑dij即可
拆点即可，每个点最多被拆成d份,也就是说至多有n*d(1e4)个点，5e5条边，跑一次最短路就可以得到答案
但是q<=1e5，再呈上一个nlogm显然爆炸
n^2预处理所有答案再O(1)输出，CCF神机助我
欸不对，线路才是n,点数是m=5e5的。。。
每条线路会贡献k个点，2k条边，sigma k=5e5，总计1e6个点,1e6条边，还有诡异的q=1e5次询问
往好处想有44pts了
q<=2000可以一边跑一边询问,4e8我相信是能过的吧 ,有60pts了
感觉分还是没拼够啊。。。 
*/
