#include<bits/stdc++.h>
using namespace std;

long long c,t;
long long n,d;
long long a[2000005],can[2000005];
long long cnt = 1;

void dfs(long long nw,long long zh,long long cnt1)
{
	if(nw == zh)
	{
		can[cnt] = cnt1;
		cnt++;
		return;
	}
	for(long long i = nw+1; i<=zh; i++)
	{
		if(a[i] - a[nw] <= d)dfs(i,zh,cnt1+1);
	}
}

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld %lld",&c,&t);
	while(t--)
	{
		long long ans =  0;
		scanf("%lld %lld",&n,&d);
		memset(a,0,sizeof(a));
		for(int i = 1; i<=n; i++)
		{
			scanf("%lld",&a[i]);
		}
		for(int i = 1; i<n; i++)
		{
			for(int j = i+2; j<=n; j++)
			{
				cnt = 1;
				memset(can,0,sizeof(can));
				dfs(i,j,0);
				sort(can+1,can+cnt);
				if(can[1] == can[2] && can[2] != can[3])
				{
					ans++;
				}
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}
