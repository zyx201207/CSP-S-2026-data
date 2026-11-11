/*
But it's not the last OI contest of my life.
Maybe senior high school ?
I don't know.
But I'm sure that I'll come back.
Contest ends.
*/
#include <bits/stdc++.h>
using namespace std;

const long long MAXN=1e6+1;
long long n,d,minn,cnt;
long long a[MAXN];

void dfs(long long x,long long step,long long end)
{
	if(x==end)
	{
		if(step<minn)
		{
			minn=step;
			cnt=0;
		}
		if(step==minn)
			cnt++;
		return ;
	}
	for(long long i=x+1;i<=end;i++)
	{
		if(a[i]-a[x]>d)
			break;
		dfs(i,step+1,end);
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);

	long long c,T;
	scanf("%lld%lld",&c,&T);
	while(T--)
	{
		long long ans=0;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++)
			scanf("%lld",&a[i]);
		if(n>=30)
		{
			printf("0\n");
		}
		for(long long i=1;i<n;i++)
		{
			for(long long j=i+1;j<=n;j++)
			{
				minn=LONG_LONG_MAX;
				cnt=0;
				dfs(i,0,j);
				if(cnt==2)
					ans++;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}