#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200010];
long long ans=0;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++)scanf("%lld",&a[i]);
	sort(a,a+n);
	ans=a[n-1];
	for(long long i=n-1;i>=n-m;i--)
	{
		ans&=a[i];
	}
	printf("%lld",ans);
	return 0;
}
