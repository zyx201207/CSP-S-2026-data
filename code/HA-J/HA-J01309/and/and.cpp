#include <bits/stdc++.h>
using namespace std;
long long dp[200010];
long long k[200010],n,m; 
long long f(long long x,long long y)
{
	int a[1010],k1=0,c[1010];
	int b[1010],k2=0;
	long long sum=0,ans=1,p=x,q=y;
	while(p)
	{
		a[++k1]=p%2;
		p/=2;
	}
	while(q)
	{
		b[++k2]=q%2;
		q/=2;
	}
	if(k1==0) return y;
	if(k2==0) return x;
	else
	{
		for(int i=1;i<=max(k1,k2);i++)
		{
			if(a[i]==1 && b[i]==1) c[i]=1;
			sum+=ans*c[i];
			ans*=2;
		}
	}
	return sum;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%d",&k[i]);
	dp[0]=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			dp[i]=max(dp[i-1],f(dp[i-1],k[j]));
		} 
	}
	printf("%d",dp[m]);
}
