#include<bits/stdc++.h>
using namespace std;
long long C,n,m,D,q,an,b[500005],f[505][505];
struct node{long long x,y;};
vector<node>a[500005];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	for(int i=1,xx,x,y;i<=n;i++)
	{
		cin>>xx;
		for(int j=1;j<=xx;j++)
		{
			cin>>x>>y;
			a[x].push_back({i,y});
		}
		for(int j=1;j<=n;j++)f[i][j]=LONG_LONG_MAX>>2;
		f[i][i]=0;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j<a[i].size();j++)
		{
			for(int k=j+1;k<a[i].size();k++)
			{
				node x=a[i][j],y=a[i][k];
				f[x.x][y.x]=f[y.x][x.x]=min(f[x.x][y.x],x.y+y.y);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(i==j||f[j][i]==(LONG_LONG_MAX>>2))continue;
			for(int k=j+1;k<=n;k++)
			{
				if(i==k||f[i][k]==(LONG_LONG_MAX>>2))continue;
				f[j][k]=f[k][j]=min(f[j][k],f[j][i]+f[i][k]);
			}
		}
	}
	for(int i=1,x,y;i<=q;i++)
	{
		cin>>x>>y;
		an=LONG_LONG_MAX>>2;
		for(int j=0;j<a[x].size();j++)
		{
			for(int k=0;k<a[y].size();k++)
			{
				an=min(an,a[x][j].y+a[y][k].y+f[a[x][j].x][a[y][k].x]);
			}
		}
		cout<<an+b[x]+b[y]<<'\n';
	}
	return 0;
}
