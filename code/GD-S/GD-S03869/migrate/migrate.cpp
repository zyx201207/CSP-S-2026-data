#include<bits/stdc++.h>
using namespace std;
long long a[100005];
long long dis[1005][1005];
long long ans[1005][1005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout); 
	long long c,T;
	cin>>c>>T;
	if(c==11||c==12)
	{
		while(T--)
		{
			long long n,k;
			cin>>n>>k;
			long long x;
			for(long long i=1;i<=n;i++)
			{
				cin>>a[i];
				if(a[i]-a[1]<=k) x=i-1;
			}
			if(x==1)
			cout<<0;
			else 
			cout<<n-2*x+1<<"\n";
		}
		return 0;
	}
	while(T--)
	{
		memset(dis,0x7f,sizeof(dis));
		long long n,k;
		cin>>n>>k;
		for(long long i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				ans[i][j]=1;
		for(long long i=1;i<=n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				if(a[j]-a[i]<=k)
				{
					dis[i][j]=1;
				}
				else
				{
					break;
				}
			}
		}
		for(long long k=1;k<=n;k++)
		{
			for(long long i=1;i<=n;i++)
			{
				for(long long j=1;j<=n;j++)
				{
					if(dis[i][j]==dis[i][k]+dis[k][j]) 
					{
						ans[i][j]++;
					}
					if(dis[i][j]>dis[i][k]+dis[k][j]) 
					{
						dis[i][j]=dis[i][k]+dis[k][j];
						ans[i][j]=ans[i][k]*ans[k][j];
					}
				}	
			}
		}
		long long res=0;
		for(long long i=1;i<=n;i++)
			for(long long j=1;j<=n;j++)
				if(dis[i][j]!=1061109567&&ans[i][j]==2)
					res++;
		cout<<res<<"\n";
	}
	return 0;
} 
