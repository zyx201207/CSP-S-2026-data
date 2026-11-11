/*
Oct31==Dec25?
freopen neuvillette.in/out r/w stdin/out
crystal subway migrate hub
14:30~18:30
一定要多开long long！！！！！1 
*/
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
constexpr int N=507;  //地铁线路数 
constexpr int M=5e5+7;  //地铁站台数 
constexpr ll inf=1e18;
struct stationx{int a; ll t;};
vector<stationx> line[N];   //地铁线路
//点数是m不是n，m也不是边数！！ 
ll wt[M];
int n,m,d,q;
namespace bruteforce
{
	vector<pair<int,ll>> g[M];
	inline void add(int u,int v,ll w)
	{
		g[u].push_back({v,w});
		g[v].push_back({u,w});
//		cerr<<u<<' '<<v<<' '<<w<<'\n';
	}
	ll dis[M];
	bitset<M> vis;
	inline ll solve(int x,int y)
	{
		if(x==y) return wt[x]+wt[y];
		for(int i=1;i<=m;i++) dis[i]=inf;
		vis.reset();
		dis[x]=0;
		priority_queue<pair<ll,int>> q;
		q.push({0,x});
		while(!q.empty())
		{
			int u=q.top().second; q.pop();
			if(!vis[u])
			{
				vis[u]=1;
				for(auto E:g[u])
				{
					auto v=E.first;
					auto w=E.second;
					if(dis[v]>dis[u]+w)
					{
						dis[v]=dis[u]+w;
						q.push({-dis[v],v});
					}
				}
			}
		}
		return dis[y]+wt[x]+wt[y];
	}
	inline void main()
	{
		for(int i=1;i<=n;i++)
		{
			for(int x=0;x<(int)line[i].size();x++)
			{
				for(int y=x+1;y<(int)line[i].size();y++)
				{
//					cerr<<x<<' '<<y<<'\n';
					add(line[i][x].a,line[i][y].a,line[i][x].t+line[i][y].t);
				}
			}
		}
		int u,v;
		while(q--)
		{
			cin>>u>>v;
			cout<<solve(u,v)<<'\n';
		}
	}
}
namespace neuvillette
{
	//对于任意两条线路，找出他们的交集点 
	ll dis[N][N];  //两条线路之间的距离 
	vector<pair<int,ll>> belong[M];  //地铁站所在的线路以及权值 
	inline ll solve(int u,int v)
	{
		ll ans=1e18;
		for(int l1=0;l1<(int)belong[u].size();l1++)
		{
			auto uline=belong[u][l1].first;
			auto ut=belong[u][l1].second;
			for(int l2=0;l2<(int)belong[v].size();l2++)
			{
				auto vline=belong[v][l2].first;
				auto vt=belong[v][l2].second;
				ans=min(ans,ut+dis[uline][vline]+vt);
			}
		}
		return ans+wt[u]+wt[v];
	}
	inline void main()
	{
		for(int i=1;i<=n;i++) for(int j=1;j<=n;j++) dis[i][j]=inf;
		for(int i=1;i<=n;i++) dis[i][i]=0;
		
		for(int i=1;i<=n;i++)
			for(auto F:line[i])
				belong[F.a].push_back({i,F.t});
		
		for(int i=1;i<=m;i++)
		{
			for(int l1=0;l1<(int)belong[i].size();l1++)
			{
				for(int l2=l1+1;l2<(int)belong[i].size();l2++)
				{
					int u=belong[i][l1].first;
					int v=belong[i][l2].first;
					ll w=belong[i][l1].second+belong[i][l2].second;
					dis[u][v]=min(dis[u][v],w);
					dis[v][u]=min(dis[v][u],w);
				}
			}
		}
		
		for(int k=1;k<=n;k++)
			for(int i=1;i<=n;i++)
				for(int j=1;j<=n;j++) dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		
		int u,v;
		while(q--)
		{
			cin>>u>>v;
			cout<<solve(u,v)<<'\n';
		}
	}
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	int cid;
	cin>>cid>>n>>m>>d>>q;
	for(int i=1;i<=m;i++) cin>>wt[i];
	stationx tmp;
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			cin>>tmp.a>>tmp.t;
			line[i].push_back(tmp);
		}
	}
	if(cid>0&&cid<=11) bruteforce::main();
	else neuvillette::main();
	cout.flush();
	return 0;
}
/*
需要从地铁口走到站厅，然后站厅走到站台 注意是从地铁口到地铁口
每次换乘都和地铁口到站台的时间无关，所以w[x]+w[y]是固定的，只需要考虑t

一个猜想：有用的地铁站只能是起点线路和重点线路的交集。很可能是错的
考虑图论建模,n<=500,m<=5e5,d<=20
两种思路：1.地铁站为点，线路为边 or 2.线路为点 

## 1.
在同一条线路x上，第i到第j的花费为t[x][i]+t[x][j]，这会建立O(k^2)条边 

然后每一次询问都需要查询一次最短路
时间复杂度O(q (k^2 log k^2+m)) 期望通过  1~8

16:05，写完暴力，T4 brute or T2 std? 

时间复杂度的瓶颈在于每次查询都需要跑最短路，以及建图
d很小，这说明了什么？ 能不能枚举从哪条线路出去，从哪条线路到达？
n也很小，这说明了什么？可以初始化每个线路到另外一个线路的距离

考虑枚举从哪进，从哪出
floyd初始化任意两条线路的距离 

17:29过大样例，这或许是我OI中第一次切出T2 
*/
