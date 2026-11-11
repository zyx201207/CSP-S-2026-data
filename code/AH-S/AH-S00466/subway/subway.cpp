//subway.cpp,1s,1024MiB
#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005],dis[505][505];
pair<int,int>to[500005][25];
//at least 92p,run!
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,m,n,d,q;
	cin>>c>>n>>m>>d>>q;
	for(int i=1;i<=m;i++)
		cin>>w[i];
	memset(dis,0x3f,sizeof dis);
	for(int i=1;i<=n;i++)
	{
		dis[i][i]=0;
		int l;
		cin>>l;
		while(l--)
		{
			int x,y;
			cin>>x>>y;
			to[x][++to[x][0].first]={i,y};
		}
	}
	for(int i=1;i<=m;i++)
	{
		int l=to[i][0].first;
		for(int j=1;j<=l;j++)
			for(int k=j+1;k<=l;k++)
				dis[to[i][j].first][to[i][k].first]=
				dis[to[i][k].first][to[i][j].first]=
				min(dis[to[i][k].first][to[i][j].first],
				to[i][j].second+to[i][k].second);
	}
	for(int k=1;k<=n;k++)
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		int ans=LLONG_MAX;
		for(int i=1;i<=to[x][0].first;i++)
			for(int j=1;j<=to[y][0].first;j++)
			{
				ans=min(ans,to[x][i].second+dis[to[x][i].first][to[y][j].first]+to[y][j].second);
			}
		cout<<w[x]+ans+w[y]<<'\n';
	}
}
