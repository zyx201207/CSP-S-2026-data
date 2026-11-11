#include<bits/stdc++.h>
using namespace std;
unsigned long long a[200200],ans;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m;
	scanf("%lld%lld",&n,&m);
	for (int i=1;i<=n;i++) scanf("%llu",&a[i]);
	if (m==1)
	{
		for (int i=1;i<=n;i++) ans=max(ans,a[i]);
		printf("%llu",ans);
		return 0;
	}
	for (int i=1;i<=n-m+1;i++)
	{
		int j=i+1;
		while (j<=n)
		{
			unsigned long long sum=a[i];
			int num=m-1;
			while (num--)
			{
				sum=sum&a[j];
				j++;
			}
			ans=max(ans,sum);
		}
	}
	printf("%llu",ans);
	return 0;
}
