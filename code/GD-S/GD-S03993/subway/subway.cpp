#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N = 500055,MAXX = 10000000000000005;

struct Edge
{
	int v,w;
	bool operator < (const Edge &a) const
	{
		return a.w > w;
	}
};

int c,n,m,d,q,w[N],t[25][N],s[N],dis[25][25],k[25],a[25][N],C[N],ans = MAXX;
bool vis[25],Vis[25][N];
vector <Edge> e[N];

void dijsktra(int s,int w)
{
	priority_queue <Edge> q;
	q.push((Edge){s,w});
	for(int i = 0;i <= 24;i++) dis[s][i] = MAXX;
	dis[s][s] = 0;
	memset(vis,0,sizeof(vis));
	
	while(!q.empty())
	{
		Edge now = q.top();
		q.pop();
		
		if(vis[now.v]) continue;
		vis[now.v] = 1;
		int siz = e[now.v].size();
		for(int i = 0;i < siz;i++)
		{
			int v = e[now.v][i].v;
			if(dis[s][now.v] + e[now.v][i].w < dis[s][v])
			{
				dis[s][v] = dis[s][now.v] + e[now.v][i].w;
				q.push((Edge){v,dis[s][v]});
			}
		}
	}
}

signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> w[i];
	for(int i = 1;i <= n;i++)
	{
		cin >> k[i];
		for(int j = 1;j <= k[i];j++)
		{
			cin >> a[i][j];
			cin >> t[i][a[i][j]];
			Vis[i][a[i][j]] = 1;
		}
	}
	
	for(int l = 1;l <= n;l++)
	{
		for(int j = 1;j <= k[l];j++)
		{
			for(int r = l + 1;r <= n;r++)
			{
				if(Vis[r][a[l][j]])
				{
					e[l].push_back((Edge){r,t[l][a[l][j]] + t[r][a[l][j]]});
					e[r].push_back((Edge){l,t[l][a[l][j]] + t[r][a[l][j]]});
				}
			}
		}
	}
	
	for(int i = 1;i <= n;i++) dijsktra(i,0);

	int x,y;
	while(q--)
	{
		cin >> x >> y;
		int cnty = 0;
		for(int i = 1;i <= n;i++)
		{
			if(!Vis[i][y]) continue;
			C[++cnty] = i;
		}
		
		for(int i = 1;i <= n;i++)
		{
			if(!Vis[i][x]) continue;
			for(int j = 1;j <= cnty;j++)
			{
				ans = min(ans,w[x] + w[y] + t[i][x] + dis[i][C[j]] + t[C[j]][y]);
			}
		}
		
		cout << ans << endl;
		ans = MAXX;
	}
	return 0;
}
