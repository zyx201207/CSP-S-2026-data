#include <bits/stdc++.h>
#define int long long
using namespace std;
typedef unsigned long long ull;
const int N=5e5+5;
const int M=505;
const int inf=1e18;
const int P=998244353;
vector <int> e[N];
bitset <N> to[505];
unordered_map <ull,int> d1;//中转点和站厅的距离 
int f[2005][2005];
int d2[M][M];
int getin[N];
int n,m,dmax,q;
inline int read()
{
	bool f=true;
	int g=0;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-') f=false;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		g=(g<<3)+(g<<1)+(c^48);
		c=getchar();
	}
	return f?g:(~g+1);
}
inline ull hs(ull i,ull j)
{
	return (i*P+j)^11451;
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int T;
	cin>>T>>m>>n>>dmax>>q;
	//中转点编号为 n+1 至 n+m 
	for(int i=1;i<=n;i++)
	{
		cin>>getin[i];
	}
	if(!(12<=T&&T<=19))
	{
		for(int i=1;i<n+m;i++)
		{
			for(int j=i+1;j<=n+m;j++) f[i][j]=f[j][i]=inf;
		}
	}
	for(int i=1;i<=m;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int x,w;
			cin>>x>>w;
			e[x].push_back(i);
			if(12<=T&&T<=19)
			{
				to[i].set(x);
				d1[hs(i,x)]=w;
			}
			else
			{
				f[x][i+n]=f[i+n][x]=w;
			}
		}
	}
	if(12<=T&&T<=19)
	{
		for(int i=1;i<m;i++)
		{
			for(int j=i+1;j<=m;j++)
			{
				d2[i][j]=d2[j][i]=inf;
				bitset <N> cur=to[i]|to[j];
				int x=cur._Find_first();
				while(x!=N)
				{
					d2[i][j]=d2[j][i]=min(d2[i][j],d1[hs(i,x)]+d1[hs(j,x)]);
					x=cur._Find_next(x);
				}
			}
		}
	}
	else
	{
		for(int k=1;k<=n+m;k++)
		{
			for(int i=1;i<=n+m;i++)
			{
				for(int j=1;j<=n+m;j++)
				{
					f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
				}
			}
		}
	}
	while(q--)
	{
		int u,v;
		cin>>u>>v;
		int ans=inf;
		for(auto &x:e[u])
		{
			for(auto &y:e[v])
			{
				if(12<=T&&T<=19) ans=min(ans,getin[u]+d1[hs(x,u)]+d2[x][y]+d1[hs(y,v)]+getin[v]);
				else ans=min(ans,getin[u]+f[u][x]+f[x][y]+f[y][v]+getin[v]);
			}
		}
		cout<<ans<<'\n';
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

0 3 7 20 2
8 3 6 1 7 2 9
3 1 4 2 5 5 100
3 2 6 3 1 7 2
4 3 2 5 100 4 6 6 7
1 6
2 3


把站厅和站台直接连边？
直接连，总共有 5e5 个站厅和 5e5 个站台 = 1e6 个结点，站台和站台间的连边共约 1e6 条边
单次 dijkstra 2e7，远无法满足 q 次询问

注意到坐地铁是免费的，即同线路的一个站台到另一个站台是免费的
去除地面和站厅之间的时间，那么总时间就是换乘的时间

不妨把 "一条线路" 看成一个换站厅的工具，那么可以把一条线路看作一个中转点
不把同线路的站台间连 0 权边了，因为换乘都要先去站厅
直接把一条线路上的站厅和代表这条线路的中转点，连一个边权为 t 的边
那么一条线路经过多少个站，就连多少条边; 有多少条线路，就有多少个中转点
于是点数降到 5e5+500，边数降到 5e5
单次 dijkstra 1e7，还是远无法满足 q 次询问 

注意到所有的边，都形如 "站厅 --- 线路中转点"，把站厅放上面，中转点放下面，变成了二分图
考虑运用 dmax
每个地铁站最多被 dmax 条线路经过，等价于从站厅出发最多有 dmax 个选择
发现知道 能到 u 的中转点和能到 v 的中转点，同时变的是 u,v，不变的是中转点 
那么就变成处理中转点之间的最短路了，最后加上去中转点的时间
dmax^2 枚举 u,v 能直接到的中转点，q*dmax^2，1e5*400=4e7

如何 O(1) 得到两个中转点间的最短路？ 
考虑预处理中转点之间的最短路
我们只关心 500 个点间的最短路 
每个地铁站最多被 dmax 条线路经过，也等价于这个站厅，只会影响 dmax 个中转点的最短路判断
也就是说，m^2 枚举中转点 x,y 时，不需要用所有的站厅去更新，
而只需要用 "x 的邻居" 和 "y 的邻居" 的交集，使用 bitset 感性估计不会超 

错了，可能通过更多站厅到达 
floyd 跑路了 
*/
