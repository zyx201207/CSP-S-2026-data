#include<bits/stdc++.h>
using namespace std;
const int M=5e3+5;
int n,m,c,z,q,w[M],d[M][M],t[505];
vector<pair<int,int>> e[505],s[M][M];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>n>>m>>z>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(d,sizeof(d),0x3f);
	for(int i=1;i<=n;i++)
	{
		int k;
		cin>>k;
		for(int j=1;j<=k;j++)
		{
			int a,t;
			cin>>a>>t;
			e[a].push_back({k,t});
		}
			
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<sizeof(e[i]);j++)
		{
			for(int k=0;k<j;k++)
			{
				d[e[i][j].first][e[i][k].first]=e[i][j].second+e[i][k].second;
			}
		}
	}
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
			}
		}
	}
	for(int i=1;i<=q;i++)
	{
		int x,y;
		cin>>x>>y;
		int ans=0x3f3f3f;
		for(int j=0;j<sizeof(e[x]);j++)
		{
			for(int k=0;k<sizeof(e[y]);k++)
			{
				ans=min(w[x]+w[y]+d[e[x][j].first][e[y][k].first],ans);
			}
		}
		cout<<ans<<"\n";
	}
}
