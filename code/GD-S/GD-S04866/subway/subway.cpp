#include<bits/stdc++.h>
#define int long long
using namespace std;
const int M=5e5+5,N=1e6+100;
int c,n,m,d,q,k,x,y,w[M],ans;
vector<pair<int,int> > g[N];
int dis[N],subway[505][505];
vector<pair<int,int> > gog[M];
void solve(int st)
{
	memset(dis,0x3f3f3f3f,sizeof(dis));
	priority_queue<pair<int,int> > q;
	q.push({0,st});
	dis[st]=0;
	while (!q.empty())
	{
		int u=q.top().second;
		q.pop();
		for (auto edge:g[u])
		{
			int v=edge.first;
			int w=edge.second;
			if (dis[v]>dis[u]+w)
			{
				dis[v]=dis[u]+w;
				q.push({-dis[v],v});
			}
		}
	}
}
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	cin>>c>>n>>m>>d>>q;
	for (int i=1; i<=m; i++) cin>>w[i];
	for (int i=1; i<=n; i++)
	{
		cin>>k;
		for (int j=1; j<=k; j++)
		{
			cin>>x>>y;
			gog[x].push_back({i,y});
			g[x].push_back({i+M,y});
			g[i+M].push_back({x,y});
		}
	}
	for (int i=1; i<n; i++)
	{
		solve(i+M);
		for (int j=i+1; j<=n; j++)
		{
			subway[i][j]=
			subway[j][i]=dis[j+M];
			//cout<<subway[i][j]<<' ';
		}
		//cout<<'\n';
	}
	while (q--)
	{
		cin>>x>>y;
		ans=1e18;
		for (int i=0; i<gog[x].size(); i++)
		{
			for (int j=0; j<gog[y].size(); j++)
			{
				//cout<<gog[x][i].second<<' '<<subway[gog[x][i].first][gog[y][j].first]<<' '<<gog[y][j].second<<'\n';
				ans=min(ans,gog[x][i].second+subway[gog[x][i].first][gog[y][j].first]+gog[y][j].second);
			}
		}
		cout<<ans+w[x]+w[y]<<'\n';
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
*/
