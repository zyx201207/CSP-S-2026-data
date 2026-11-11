#include<bits/stdc++.h>
using namespace std;
long long T,n,type,d,a[1000005],f[5005][5005],cnt[5005][5005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&type,&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			for(int t=i+1;t<=n;t++)
			{
				f[i][t]=1e18;
				cnt[i][t]=0;
			}
		}
		for(int i=1;i<=n;i++)
		{
			cnt[i][i]=1;
			cnt[i][i+1]=-1;
			f[i][i]=0;
			long long h=i,maxn=i;
			for(int t=i;t<=n;t++)
			{
				if(f[i][t]>f[i][t-1])
				{
					h=maxn;
					maxn=t;
				}
				cnt[i][t]=cnt[i][t-1]+cnt[i][t];
				long long fi=n;
				for(int j=h+1;j<=n;j++)
					if(a[j]-a[t]>d)
					{
						fi=j-1;
						break;
					}
					else
						f[i][j]=f[i][t]+1;
				cnt[i][h+1]+=cnt[i][t];
				cnt[i][fi+1]-=cnt[i][t];
				maxn=max(maxn,fi);
			}
		}
		long long ans=0;
		for(int i=1;i<=n;i++)
			for(int t=i;t<=n;t++)
				if(cnt[i][t]==2)
					ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
