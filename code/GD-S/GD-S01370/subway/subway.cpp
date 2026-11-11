#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,w[505],tt[50005],a,x,y,k,ans=LONG_LONG_MAX;
long long t[505][50005];
int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
	for(long long i=1;i<=m;i++)
	{
		scanf("%lld",&w[i]);
	}
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		for(long long j=1;j<=k;j++)
		{
			scanf("%lld",&a);
			scanf("%lld",&t[i][a]);
			tt[a]++;
		}
	}
	while(q--)
	{
		ans=LONG_LONG_MAX;
		scanf("%lld%lld",&x,&y);
		bool flag=false;
		for(long long i=1;i<=n;i++)
		{
			if(t[i][x]&&t[i][y])
			{
				ans=min(ans,w[x]+w[y]+t[i][x]+t[i][y]);
				flag=true;
				break;
			}
		}
		if(flag)
		{
			printf("%lld\n",ans);
			continue;
		}
		long long sum=0,sl=0;
		for(long long i=1;i<=n;i++)
		{
			if(t[i][x])
			{
				sl=i;
				break;
			}
		}
		sum+=w[x]+t[sl][x];
		for(long long i=x;;i++)
		{
			if(i>m)
			{
				i=1;
			}
			if(tt[i]>1)
			{
				for(long long j=1;j<=n;j++)
				{
					if(j==sl)
					{
						continue;
					}
					if(t[j][i])
					{
						sum+=t[sl][i]+t[j][i];
						sl=j;
						x=i;
						break;
					}
				}
			}
			if(t[sl][i]>0&&i==y)
			{
				sum+=t[sl][y];
				break;
			}
		}
		sum+=w[y];
		ans=min(ans,sum);
		printf("%lld\n",ans);
	}

	return 0;
}

