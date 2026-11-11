#include <bits/stdc++.h>

using namespace std;

const int N=5005;
typedef long long ll;

int c,t,n,cnt[N][N];
ll d,a[N],dis[N][N];

void init()
{
	memset(cnt,0,sizeof cnt);
	memset(dis,0x3f,sizeof dis);
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	
	scanf("%d%d",&c,&t);
	while(t--)
	{
		init();
		scanf("%d%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			dis[i][i]=0;
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(i==j) continue;
				if(a[i]-a[j]<=d)
				{
					dis[i][j]=1;
					dis[j][i]=1;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=i;j++)
			{
				for(int k=1;k<=i;k++)
				{
					if(i==j||j==k||i==k) continue;
					if(a[i]-a[k]<=d&&a[k]-a[j]<=d)
					{
						if(dis[j][i]>dis[j][k]+dis[k][i])
						{
							dis[j][i]=dis[j][k]+dis[k][i];
							cnt[j][i]=1;
						}
						else if(dis[j][i]==dis[j][k]+dis[k][i])
						{
							cnt[j][i]++;
						}
					}
				}
			}
		}
		ll ans=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<i;j++)
			{
				if(cnt[j][i]==2)
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
