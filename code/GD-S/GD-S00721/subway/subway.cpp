#include<bits/stdc++.h>
using namespace std;
const int M = 500010,N = 510;
struct node{
	long long v,w;
};
int c,n,m,d,q,st,en;
long long w[M];
int tim[M][N];//从地铁站i到j号线路的时间
vector<int> sta[M];//每个站台被哪条线路经过 
vector<node> lin[N];//每个线路之间的边 
long long dis[N][N];//i号线到j号线的最短路 
void solve()
{
	cin >> st >> en;//起点和终点
	long long ans = 1e18;
	for(auto u:sta[st])
	{
		for(auto v:sta[en])
		{
			if(ans > tim[st][u] + tim[en][v] + dis[u][v])
			{
				ans = tim[st][u] + tim[en][v] + dis[u][v];
				//cout << st << " " << u << " " << en << " " << v << "\n";
			}
		}
	}
	cout << (ans + w[st] + w[en]) << "\n";
}
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i=1;i<=m;i++) cin >> w[i];
	for(int i=1;i<=n;i++)
	{
		int k;
		cin >> k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin >> a >> t;
			tim[a][i] = t;
			sta[a].push_back(i);
		}
	}
	for(int i=1;i<=m;i++)
	{
		for(auto u:sta[i])
		{
			for(auto v:sta[i])
			{
				if(u == v) continue;
				lin[u].push_back({v,tim[i][u]+tim[i][v]});
			}
		}
	}
	//求最短路
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++) dis[i][j] = 1e9;
		dis[i][i] = 0;
	}
	for(int i=1;i<=n;i++)
	{
		for(auto e:lin[i])
		{
			long long v = e.v,w = e.w;
			dis[v][i] = dis[i][v] = min(dis[i][v],w);
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(dis[i][j] > dis[i][k] + dis[k][j])
				{
					dis[i][j] = dis[i][k] + dis[k][j];
				}
			}
		}
	} 
	while(q--) solve();
	return 0;
}

