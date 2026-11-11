#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100,M=505;
long long C,T,n,m,w[N],z=0,d[M][M],s=0,D,q;
struct jg
{
	int x;
	long long y;
};
vector<jg>a[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	std::ios::sync_with_stdio(0);
	std::cin.tie(0);
	cin>>C>>n>>m>>D>>q;
	for(int i=1;i<=m;i++)
	{
		cin>>w[i];
	}
	memset(d,0x3f,sizeof(d));
	for(int i=1,k;i<=n;i++)
	{
		cin>>k;
		d[i][i]=0;
		for(int j=1,x,y;j<=k;j++)
		{
			cin>>x>>y;
			a[x].push_back({i,y});
		}
	}

	for(int i=1;i<=m;i++)
	{
		for(int v=0;v<a[i].size();v++)
		{
			for(int u=v+1;u<a[i].size();u++)
			{
				jg x=a[i][v],y=a[i][u];
				d[x.x][y.x]=d[y.x][x.x]=min(x.y+y.y,d[y.x][x.x]);
			}
		}
	}
	
	for(int x=1;x<=n;x++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				d[i][j]=d[j][i]=min(d[i][j],d[i][x]+d[x][j]);
			}
		}
	}

	for(int x,y;q--;)
	{
		cin>>x>>y;
		s=1e18;
		for(jg i:a[x])
		{
			for(jg j:a[y])
			{
				//cout<<i.x<<' '<<i.y<<' '<<j.x<<' '<<j.y<<' '<<d[i.x][j.x]<<"\n";
				s=min(s,i.y+j.y+d[i.x][j.x]);
			}
		}
		cout<<w[x]+w[y]+s<<"\n";
	}
}
