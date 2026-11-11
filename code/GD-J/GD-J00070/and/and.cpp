#include <bits/stdc++.h>
using namespace std;
long long n,m,a[200010];
int main ()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	long long sum=549755813887;
	for(int i=n; i>n-m; i--)
	{
		sum=min(sum,a[i]);
	}
	printf("%lld",sum);
	return 0;
}
