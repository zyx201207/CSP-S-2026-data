#include<bits/stdc++.h>
using namespace std;
long long N,M;
long long A[500005];
long long Ans=0;
long long l;
bool cmpAA(long long X,long long Y)
{
	return X<Y; 
}
long long sum[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&N,&M);
	for(int i=1;i<=N;i++)
	{
		scanf("%lld",&A[i]);
	}
	sort(A+1,A+N+1,cmpAA);
	for(int i=1;i<=N;i++)
	{
		sum[i]=sum[i-1]+A[i];
	}
	l=1;
	for(long long i=1;i<=N;i++)
	{
		while(l<=N&&(i-l+1ll)*A[i]-sum[i]+sum[l-1]>M)
		{
			l++;
		}
		Ans=max(Ans,i-l+1);
	}
	printf("%lld",Ans);
	return 0;
}
