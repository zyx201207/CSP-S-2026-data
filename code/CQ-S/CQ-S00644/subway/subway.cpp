#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 505,M = 5e5+5,inf = 2e18;
int n,m,d,q,a[M],dis[N][N],p[M];
vector<pair<int,int>> vec[M]; 
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int cid;
	cin>>cid>>n>>m>>d>>q;
	for(int i = 1;i<=m;i++) cin>>a[i];
	for(int i = 1,len,x,y;i<=n;i++)
	{
		cin>>len;
		while(len--)
		{
			cin>>x>>y;
			vec[x].push_back({i,y});
		}
	}
	for(int i = 1;i<=n;i++)
	{
		for(int j = 1;j<=n;j++)
			dis[i][j] = inf;
		dis[i][i] = 0;
	}
	for(int i = 1;i<=m;i++)
	{
		for(int x = 0;x<vec[i].size();x++) p[x] = vec[i][x].first;
		for(int x = 0;x<vec[i].size();x++)
		{
			int t = vec[i][x].second;
			for(int y = x+1;y<vec[i].size();y++)
				dis[p[x]][p[y]] = min(dis[p[x]][p[y]],t+vec[i][y].second);
		}
	}
	for(int i = 1;i<=n;i++)
		for(int j = 1;j<=n;j++)
			dis[i][j] = min(dis[i][j],dis[j][i]);
	for(int k = 1;k<=n;k++)
		for(int i = 1;i<=n;i++)
			for(int j = 1;j<=n;j++)
				dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y,ans = inf;
		cin>>x>>y;
		for(auto t1:vec[x]) for(auto t2:vec[y]) ans = min(ans,dis[t1.first][t2.first]+t1.second+t2.second);
		cout<<ans+a[x]+a[y]<<'\n';
	}
	return 0;
}

