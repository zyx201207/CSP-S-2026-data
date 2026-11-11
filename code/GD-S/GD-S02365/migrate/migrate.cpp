#include<bits/stdc++.h>
using namespace std;
#define int long long 
int dis[5005][5005]={0};
int shortest[5005][5005]={0};
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	//算了，打暴力吧 
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		for(int i=1;i<=5005;i++)
		{
			for(int j=1;j<=5005;j++)
			{
				shortest[i][j]=0x3f3f3f3f;
			}
		}
		int n,d;
		cin>>n>>d;
		int a[n+5]={0};
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
	
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=dis[j][i]=a[j]-a[i];
				if(dis[i][j]>d || i==j)
				{
					dis[i][j]=dis[j][i]=0x3f3f3f3f;
				}
			}
		}
		//不会打TWT 
		int ans=0; 
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(i!=j && j!=k && k!=i) shortest[i][j]=min(shortest[i][j],dis[i][k]+dis[k][j]);
				}
			}
		}
		for(int k=1;k<=n;k++)
		{
			int num=0; 
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(shortest[i][j]==dis[i][k]+dis[k][j] && (i!=j && j!=k && k!=i))
					{
						num++;
					}
				}
			}
			if(num==2)
			{
				ans++;
			}
		}		
		cout<<ans<<'\n';
	}
	return 0;
}
