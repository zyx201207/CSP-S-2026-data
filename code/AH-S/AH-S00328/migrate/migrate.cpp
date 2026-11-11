#include<bits/stdc++.h>
using namespace std;
const int N=5005,inf=5006;
long long c,T,n,m,ans;
long long a[N],dis[N][N],way[N][N];
bool to[N][N];
void build()
{
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(a[j]-a[i]<=m)
			{
				to[i][j]=1;
				dis[i][j]=1;
			}
		}
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	while(T--)
	{
		memset(dis,inf,sizeof dis);
		memset(to,0,sizeof to);
		memset(way,0,sizeof way);
		ans=0;
		cin>>n>>m;
		for(int i=1;i<=n;i++)	cin>>a[i];
		build();
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(to[i][j]==1)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(to[j][k]==1)		
						{
							dis[i][k]=min(dis[i][k],dis[i][j]+dis[j][k]);
							to[i][k]=1;
						}
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(to[i][j]==1)
				{
					for(int k=j+1;k<=n;k++)
					{
						if(to[j][k]==1 && dis[i][j]+dis[j][k]==dis[i][k])	way[i][k]++;
					}
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=i+1;j<=n;j++)
			{
				if(way[i][j]==2) ans++;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
