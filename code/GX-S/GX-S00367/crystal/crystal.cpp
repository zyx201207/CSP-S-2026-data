#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int n,a[100000001],ans=0,sum=0;
long long m,maxx=-114514,minn=1145141919810;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d %lld\n",&n,&m);
	for(int i=1;i<=n;i++)
	{
		long long x=0;
		scanf("%lld ",&x);
		a[x+50000000]++;
		maxx=max(maxx,x+50000000);
		minn=min(minn,x+50000000);
	}
	long long spend=0;
	for(long long last=minn;last<=maxx;last++)
	{
		if(a[last]==0) continue;
		//printf("\n%d\n",a[last]);
		for(long long i=last;i>=minn;i--)
		{
			if(a[i]==0) continue;
			//printf("%lld=%d ",i,a[i]);
			//printf("%lld ",spend+(last-i)*a[i]);
			if(spend+(last-i)*a[i]<=m) {sum+=a[i]; /*printf("%d ",sum);*/spend+=(last-i)*a[i];}
			else
			{
				while(spend+last-i<=m)
				{
					spend+=last-i;
					sum++;
				}
				ans=max(ans,sum);
				//printf("%d ",sum);
				sum=0,spend=0;
				break;
			}
			ans=max(ans,sum);
		}
		spend=0,sum=0;
	}
	printf("%d",ans);
	return 0;
}
