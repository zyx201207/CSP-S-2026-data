#include <bits/stdc++.h>
using namespace std;
long long a[10000005],h;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	h=a[n];
	for(int i=n-1;i>=n-m;i--)
	{
		h=min(a[i],h);
	}
	printf("%lld",h);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
