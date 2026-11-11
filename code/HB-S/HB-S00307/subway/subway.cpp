#include<bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,dd,q,d[505][505],ans,a[500005];
vector<pair<int,int>>v[500005];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>dd>>q;
	//cout<<n<<' ';
	for(int i=1;i<=m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		for(int j=1;j<=p;j++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back({i,y});
			//cout<<x<<' '<<i<<' '<<y<<'\n';
			//k[x].push_back(i);
		}
	}
	//for(auto it:v[131])cout<<it.first<<'\n';
	memset(d,0x3f,sizeof d);
	for(int i=1;i<=n;i++)d[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<v[i].size();j++)
		{
			//cout<<i<<' '<<v[i][j].first<<'\n';
			for(int l=0;l<v[i].size();l++)
			{
				if(v[i][j].first==v[i][l].first)continue;
				d[v[i][j].first][v[i][l].first]=min(d[v[i][j].first][v[i][l].first],v[i][j].second+v[i][l].second);
				//cout<<v[i][j].first<<' '<<v[i][l].first<<'\n';
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			for(int k=i+1;k<j;k++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
			//cout<<d[i][j]<<' '<<i<<' '<<j<<'\n';
		}
	}
	//cout<<d[9][13]<<'\n';
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		ans=0x3f3f3f3f3f3f3f3f;
		for(int j=0;j<v[x].size();j++)
		{
			//cout<<v[x][j].first<<'\n';
			for(int l=0;l<v[y].size();l++)
			{
				ans=min(d[v[x][j].first][v[y][l].first]+v[x][j].second+v[y][l].second,ans);
				ans=min(d[v[y][l].first][v[x][j].first]+v[x][j].second+v[y][l].second,ans);
				//cout<<d[v[x][j].first][v[y][l].first]+v[x][j].second+v[y][l].second<<' '<<v[x][j].first<<' '<<v[y][l].first<<'\n';
				//cout<<'a';
			}
		}
		cout<<ans+a[x]+a[y]<<'\n';
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
