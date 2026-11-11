#include<bits/stdc++.h>
using namespace std;
int n,m;
long long memory[200010];
long long ans,a[200010];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=0;i<n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	ans=a[n-1];
	for(int i=n-2;i>=n-m;i--)
	{
		ans = ans & a[i];
	}
	printf("%d",ans);
	return 0;
}
