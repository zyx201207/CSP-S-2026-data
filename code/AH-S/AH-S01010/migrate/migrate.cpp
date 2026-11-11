#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,l[2000005],r[2000005],dis[5005][5005],cnt[5005][5005];
ll d,a[2000005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;
	scanf("%d %d",&c,&T);
	if(c==11||c==12)
	{
		while(T--)
		{
			scanf("%d %lld",&n,&d);
			ll k=d/(a[2]-a[1]);
			if(k==0||k==1) printf("0\n");
			else printf("%lld\n",max(0ll,n-k*2+1));
		}
		return 0;
	}
	while(T--)
	{
		scanf("%d %lld",&n,&d);
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=n;++j)
			{
				dis[i][j]=n*n;
				cnt[i][j]=0;
			}
		}
		for(int i=1;i<=n;++i)
		{
			scanf("%lld",&a[i]);
		}
		for(int i=1;i<=n;++i)
		{
			l[i]=lower_bound(a+1,a+i,a[i]-d)-a;
			r[i]=upper_bound(a+i,a+1+n,a[i]+d)-a-1;
			for(int j=l[i];j<i;++j)
			{
				dis[j][i]=cnt[j][i]=1;
			}
			for(int j=i+1;j<=r[i];++j)
			{
				dis[i][j]=cnt[i][j]=1;
			}
			dis[i][i]=0;
		}
		for(int k=2;k<=n-1;++k)
		{
			for(int i=1;i<=k-1;++i)
			{
				for(int j=k+1;j<=n;++j)
				{
					if(dis[i][j]>dis[i][k]+dis[k][j])
					{
						dis[i][j]=dis[i][k]+dis[k][j];
						cnt[i][j]=min(3,cnt[i][k]*cnt[k][j]);
					}
					else if(dis[i][j]==dis[i][k]+dis[k][j]) cnt[i][j]=min(3,cnt[i][j]+cnt[i][k]*cnt[k][j]);
				}
			}
		}
		int ans=0;
		for(int i=1;i<=n;++i)
		{
			for(int j=i+1;j<=n;++j)
			{
				if(cnt[i][j]==2) ++ans;
			}
		}
		printf("%d\n",ans);
	}
	return 0;
}
