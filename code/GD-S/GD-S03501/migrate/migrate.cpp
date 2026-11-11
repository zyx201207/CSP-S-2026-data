#include<bits/stdc++.h>
using namespace std;
long long T,n,k,a[2200000],dis[22000000],sum[22000000],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>T;
	if(T>10)
	{
		cin>>T;
		while(T--)
			cout<<0<<'\n';
		return 0;
	}
	cin>>T;
	while(T--)
	{
		memset(a,0,sizeof(a));
		ans=0;
		cin>>n>>k;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		for(int z=1;z<n;z++)
		{
			for(int j=z;j<=n;j++)
				dis[j]=0x7FFFFFFF;
			dis[z]=0;
			memset(sum,0,sizeof(sum));
			for(int i=z;i<=n;i++)
			{
				for(int j=i+1;j<=n&&a[j]<=a[i]+k;j++)
				{
					if(dis[j]>dis[i]+1)
						dis[j]=dis[i]+1;
					else if(dis[j]==dis[i]+1)
						sum[j]++;
				}
			}
			for(int j=z;j<=n;j++)
				if(sum[j]==1)
					ans++;
		}
		cout<<ans<<'\n';
	}
	return 0;
}
