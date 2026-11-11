#include<bits/stdc++.h>
using namespace std;
int tid,n,m,maxD,q;
long long wi[500005];
vector<pair<int,long long> > sg[500005];
long long g[505][505];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>tid>>n>>m>>maxD>>q;
	for(int i=1;i<=m;i++)
		cin>>wi[i];
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		while(x--)
		{
			int y;
			long long w;
			cin>>y>>w;
			sg[y].push_back(make_pair(i,w));
		}
	}
	memset(g,0x3f,sizeof(g));
	for(int i=1;i<=n;i++)
		g[i][i]=0;
	for(int i=1;i<=m;i++)
	{
		for(int i1=0;i1<sg[i].size();i1++)
		{
			for(int i2=i1+1;i2<sg[i].size();i2++)
			{
				int x=sg[i][i1].first,y=sg[i][i2].first;
				long long w=sg[i][i1].second+sg[i][i2].second;
				g[x][y]=min(g[x][y],w);
				g[y][x]=min(g[y][x],w);
				//cout<<x<<' '<<y<<' '<<w<<endl;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=1;k<=n;k++)
			{
				g[j][k]=min(g[j][k],g[j][i]+g[i][k]);
			}
		}
	}
	while(q--)
	{
		int x,y;
		cin>>x>>y;
		long long minn=1e18;
		for(int i=0;i<sg[x].size();i++)
		{
			for(int j=0;j<sg[y].size();j++)
			{
				minn=min(minn,sg[x][i].second+sg[y][j].second+g[sg[x][i].first][sg[y][j].first]);
				//cout<<sg[x][i].first<<" "<<sg[y][j].first<<endl;
				//cout<<sg[x][i].second<<" "<<sg[y][j].second<<" "<<g[sg[x][i].first][sg[y][j].first]<<endl;
			}
		}
		cout<<minn+wi[x]+wi[y]<<"\n";
	}
	return 0;
}
