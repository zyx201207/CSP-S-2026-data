#include <bits/stdc++.h>
#define lll long long
using namespace std;
lll n,a[200010];
char c[200010];
int main ()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long sum=0;
	scanf("%lld",&n);
	for(int i=1; i<=n; i++)
	{
		scanf("%lld %c",&a[i],&c[i]);
	}
	for(int i=1,j=n; i<j;)
	{
		lll x=a[i]>=a[j]?a[j]:a[i];
		if(c[i]!=c[j])
		{
			sum+=x;
		}
		if(a[i]>a[j])
		{
			a[i]-=x;
			j--;
		}
		else if(a[i]<a[j])
		{
			a[j]-=x;
			i++;
		}
		else
		{
			i++; j--;
		}
	}
	printf("%lld\n",sum);
	return 0;
}
