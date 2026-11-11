#include <bits/stdc++.h>
using namespace std;
int n,m;
long long a[200005],maxn,and1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		maxn=max(maxn,a[i]);
	}
	sort(a+1,a+n+1);
	if(m==1)
	{
		printf("%lld",maxn);
		return 0;
	}
	else if(m==n)
	{
		and1=a[1];
		for(int i=2;i<=n;i++)
		{
			and1=and1&a[i+1];
		}
		printf("%lld",and1);
	}
	else
	{
		and1=a[n];
		for(int i=n-1;i>=n-m;i++)
		{
			and1=and1&a[i];
		}
		printf("%lld",and1);
	}
	return 0;
}
