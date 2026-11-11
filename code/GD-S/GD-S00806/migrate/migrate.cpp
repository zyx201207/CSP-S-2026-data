#include<bits/stdc++.h>
#define int long long
#define Furina using
#define de namespace
#define Fontaine std
Furina de Fontaine;
int c,t,n,m,a[2333333],dp[2333333],dis[2333333],ans;
int constexpr INF=0x3f3f3f3f3f3f3f3fll;
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		ans=0;
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",a+i);
		}
		for(int i=1;i<=n;i++)
		{
			dp[i]=1,dis[i]=0;
			for(int j=i+1;j<=n;j++)
			{
				dp[j]=0;
				dis[j]=INF;
			}
			for(int j=i+1;j<=n;j++)
			{
				for(int k=j-1;k>=i;k--)
				{
					if(a[j]-a[k]>m)
					{
						break;
					}
					dis[j]=min(dis[j],dis[k]+1);
				}
				cerr<<"dis:"<<i<<"~"<<j<<" "<<dis[j]<<"\n";
				for(int k=i;k<=j-1;k++)
				{
					if(a[j]-a[k]>m)
					{
						break;
					}
					if(dis[k]+1!=dis[j])
					{
						cerr<<" "<<i<<" "<<j<<" "<<k<<" "<<dis[k]<<" "<<dis[j]<<"\n";
						break;
					}
					cerr<<i<<" "<<j<<" "<<k<<"\n";
					dp[j]+=dp[k];
				}
				if(dp[j]==2)
				{
					ans++;
				}
				cerr<<i<<"~"<<j<<":"<<dp[j]<<"\n";
				dp[j]=min(dp[j],3ll);
			}
		}
		printf("%lld\n",ans);
	}
}
