#include<bits/stdc++.h>
using namespace std;
long long c,T,n,d,a[2000005],dis[2000005],check[2000005],sum[2000005],ans;
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	//cout<<c<<endl;
	while(T--)
	{
		ans=0;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		if(c==11||c==12)
		{
			cout<<max((d>=(a[2]-a[1])*2?n-(d/(a[2]-a[1])*2-1):0),0ll)<<endl;
		}
		else
		{
			for(int i=1;i<=n;i++)
			{
				for(int j=1;j<=n;j++)
				{
					check[j]=sum[j]=0;
				}
				dis[i]=0;
				check[i]=1;
				long long now=i,l;
				for(int j=i+1;j<=n;j++)
				{
					if(a[j]-a[now]<=d)
					{
						dis[j]=dis[now]+1;
					}
					else
					{
						dis[j]=dis[j-1]+1;
						now=j-1;
						if(a[j]-a[now]>d)
						{
							dis[j]=0;
							break;
						}
					}
					//cout<<dis[j]<<" ";
				}
				//cout<<endl;
				sum[i]=1;
				now=i;
				for(int j=i+1;j<=n;j++)
				{
					if(dis[j]==0)
					{
						break;
					}
					if(dis[j]==1)
					{
						check[j]=1;
					}
					else if(dis[j]>dis[now+1])
					{
						l=now+1;
						now=j-1;
						while(a[j]-a[l]>d)
						{
							l++;
						}
						check[j]=sum[now]-sum[l-1];
					}
					else
					{
						while(a[j]-a[l]>d)
						{
							l++;
						}
						check[j]=sum[now]-sum[l-1];
					}
					sum[j]=sum[j-1]+check[j];
				}
				//cout<<endl;
				for(int j=i+1;j<=n;j++)
				{
					if(check[j]==2)
					{
						ans++;
					}
					//cout<<check[j]<<" ";
				}
				//cout<<endl;
			}
			cout<<ans<<endl;
		}
	}
}
