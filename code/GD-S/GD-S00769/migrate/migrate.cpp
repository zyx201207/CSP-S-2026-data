#include<bits/stdc++.h>
using namespace std;
long long a[2000050];
long long dis[5500][5500];
long long zd[5500][5500];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		long long n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++) cin>>a[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(abs(a[i]-a[j])<=d) dis[i][j]=1;
				else if(i!=j) dis[i][j]=1e18;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dis[i][j]==dis[i][k]+dis[k][j]) zd[i][j]++;
					else if(dis[i][j]>dis[i][k]+dis[k][j]) dis[i][j]=dis[i][k]+dis[k][j],zd[i][j]=1;
				}
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(zd[i][j]==2&&i!=j) ans++;
			}
		}
		cout<<ans/2;
	}
	return 0;
}
