#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,ans=0;
	int a[100005];
	scanf("%d",&n);
	scanf("%d",&m);
	for (int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
	}
	sort(a+1,a+n+1);
	for (int i=2;i<=n;i++)
	{
		int x=a[i]-a[i-1];
		
		if (m>=x)
		{
			m-=x;
			ans+=x;
		}
	}
	printf("%lld",ans-1);
	return 0;
}
