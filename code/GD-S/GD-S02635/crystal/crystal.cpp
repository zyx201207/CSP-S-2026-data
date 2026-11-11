#include<bits/stdc++.h>
using namespace std; 
long long n,m,a[5*100000+5],ma;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
	{
		long long ans=0,mm=m;
		for(int j=i;j>=1;j--)
		{
			if(a[i]>=a[j]&&mm-a[i]+a[j]>=0)
			{
				ans++;
				mm=mm-a[i]+a[j];
			}
		}
		ma=max(ma,ans);
	}
	printf("%lld",ma);
	return 0;
}
