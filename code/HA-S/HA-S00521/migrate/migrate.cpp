#include<bits/stdc++.h>
#define int long long 
const int inf=20120712;
using namespace std;
int c,t,n,d;
int a[1005];
int dis[1005][1005];
int num[1005][1005];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				dis[i][j]=inf;
				num[i][j]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			for(int j=i-1;j>=1;j--)
			{
				if(a[i]-a[j]>d)	break;
				dis[j][i]=1;
				num[j][i]=1;
			}
		}
		for(int k=1;k<=n;k++)
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					if(dis[i][j]==dis[i][k]+dis[k][j])
					{
						num[i][j]+=num[i][k]*num[k][j];
					}	
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
						num[i][j]=num[i][k]*num[k][j];
					}
				}
			}
		}
		int cnt=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(j<=i)	continue;
				if(num[i][j]==2)	cnt++;
			}
		}
		cout<<cnt<<endl;
	}
	return 0;
}
