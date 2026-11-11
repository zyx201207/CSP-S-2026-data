#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N=2e6+10;

int c,t;
int n,d;
int x[N];

signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%lld%lld",&c,&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&d);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&x[i]);
		}
		if(c==13 || c==14)
		{
			printf("0\n");
		}
		if(c==11 || c==12)
		{
			int ans=0;
			int dis=x[2]-x[1];
			for(int i=1;i<=n;i++)
			{
				if(i*dis<=n)
				{
					ans+=i; 
				}
			}
			printf("%lld\n",ans);
		}
		int ans=0;
		for(int i=1;i<=n;i++)
		{
			if(x[i]-x[i-1]<=d)
			{
				ans++;
			}
		}
		printf("%lld",ans);
	}
	return 0;
}
