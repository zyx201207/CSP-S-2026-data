#include<bits/stdc++.h>
using namespace std;
long long N,M;
long long A[200005];
long long cnt[35];
long long now;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&A[i]);
	}
	now=0;
	for(int j=32;j>=0;j--)
	{
		cnt[j]=0;
		for(int i=1;i<=N;i++)
		{
			if(((A[i]>>(j+1))&now)==now)
			{
				if(((A[i]>>j)&1)==1)
				{
					cnt[j]++;
				}
			}
		}
		if(cnt[j]>=M)
		{
			now=now*2ll+1;
		}
		else
		{
			now=now*2ll;
		}
	}
	printf("%lld",now);
	return 0;
}
