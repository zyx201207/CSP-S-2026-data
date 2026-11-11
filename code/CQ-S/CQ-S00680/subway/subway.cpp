#include<bits/stdc++.h>//地铁是环线，我忘记floyd怎么写了，不要超空间好吧（ 
using namespace std;
#define int long long
//bool st; 
const int N = 5e5+10,M = 510,D = 30,inf = 1e18;
int c,n,m,d,q,a[N],k[M],x,y,head[N],cnt,bj[M],ans,X,Y;
int v[N][D],v1[N][D],Cnt[N],f[M][M];
priority_queue<pair<int,int> >p;
//g_{i,j}i到j最短路 
struct w
{
	int to,nxt,z;
}b[M*M];
//bool ed;
inline void add(int x,int y,int z)
{
	b[++cnt].nxt = head[x];
	b[cnt].to = y;
	head[x] = cnt;	
} 
signed main()
{
//	cerr<<(&st-&ed)*1.0/1024/1024;
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> a[i];
	for(int i = 1;i <= n;i++) head[i] = i;
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++) 
		{
			cin >> x >> y;
			v[x][++Cnt[x]] = i,v1[x][Cnt[x]] = y;
		}
	} 
	for(int i = 1;i <= n;i++)
		for(int j = i+1;j <= n;j++)
			f[i][j] = f[j][i] = inf;
	for(int i = 1;i <= m;i++)//边只有5e5的，小问题 
	{
		for(int j = 1;j <= Cnt[i];j++)
			for(int z = j+1;z <= Cnt[i];z++)
			{
				x = v[i][j],y = v[i][z];
				f[x][y] = min(f[x][y],v1[i][j]+v1[i][z]);
				f[y][x] = min(f[y][x],v1[i][j]+v1[i][z]);
			}
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = 1;j <= n;j++) p.push(make_pair(-f[i][j],j));
		while(!p.empty())
		{
			x = p.top().second,p.pop(); bj[x] = 0;
			for(int j = 1;j <= n;j++)
				if(f[i][j]>f[i][x]+f[x][j]) 
				{
					f[i][j] = f[i][x]+f[x][j];
					if(!bj[j]) bj[j] = 1,p.push(make_pair(-f[i][j],j));
				}
		}
	}//我真的忘记floyd了，那就写个诡异的spfa吧！（ 
	//for(int i = 1;i <= n;i++)
	//	for(int j = i+1;j <= n;j++)
	//	cout<<i<<" %%% "<<j<<" "<<f[i][j]<<'\n'; 
	for(int i = 1;i <= q;i++)
	{
		cin >> x >> y; ans = inf;
		if(x == y) ans = -a[x]-a[y];
		else
		{
			for(int j = 1;j <= Cnt[x];j++)
				for(int z = 1;z <= Cnt[y];z++)
				{
					X = v[x][j],Y = v[y][z];
				//	cout<<X<<" "<<Y<<" ** "<<f[X][Y]<<'\n';
					ans = min(ans,v1[x][j]+v1[y][z]+f[X][Y]);
				}
		}
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}
/*
谁想的题/fn
理一下，地铁口i与站厅w_i 
站厅到地铁线路i有对应的时间t_{i,j}，前提是在a_{i,j} 
我们合理推测，这个站厅是有n个的，每个地铁口有一个	 
哦有四个东西
口，厅，站，线路
口厅互通，厅站互通，线路就是站站互通 
求步行时间
我猜测应该不是环线，好诡异啊，就这么出题，对了对了
预计已经有分了，已经达成目标了呃呃（ 
神了，是环线，感觉可以直接跑最短路？
理解为n+m个点，那m个点度数都是最多d
这个地铁口又是和一位，答案加一个w_x+w_y即可
地铁站也没用啊，只要站厅即可
能不能扫描线
有一个有趣的方式，n，m两种点，m中的点要穿梭，一定要经过那n个点
对n个点跑最短路，是不是，就可以了捏，qn+nmlog 
他说度数20，d^2建边，n^2log,之后在md^2恢复即可
空间花费是nm的耶，嗯嗯嗯直接离线就可以了
m+n^2的空间 
*/
