#include<bits/stdc++.h>
using namespace std;
#define int long long
int c,n,m,d,q,a[500005],dis[505][505];
vector<int> line[500005];
map<pair<int,int>,int> mp;
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++) cin >> a[i];
	for(int i = 1,k;i <= n;i++)
	{
		cin >> k;
		for(int j = 1,x,t;j <= k;j++)
		{
			cin >> x >> t;
			line[x].push_back(i);
			mp[{x,i}] = t;
		}
	}
	memset(dis,0x3f,sizeof(dis));
	for(int i = 1;i <= n;i++) dis[i][i] = 0;
	for(int i = 1;i <= m;i++)
	{
		for(int j = 0;j < line[i].size();j++)
		{
			for(int k = j+1;k < line[i].size();k++)
			{
				int u = line[i][j],v = line[i][k],w = mp[{i,u}]+mp[{i,v}];
				dis[u][v] = min(dis[u][v],w);
				dis[v][u] = min(dis[v][u],w);
			}
		}
	}
	for(int k = 1;k <= n;k++)
	{
		for(int i = 1;i <= n;i++)
		{
			for(int j = 1;j <= n;j++) dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
		}
	}
	while(q--)
	{
		int u,v;
		cin >> u >> v;
		int ans = 1e18;
		for(auto i:line[u])
		{
			for(auto j:line[v]) ans = min(ans,dis[i][j]+mp[{u,i}]+mp[{v,j}]);
		}
		cout << a[u]+a[v]+ans << "\n";
	}
	return 0;
}
