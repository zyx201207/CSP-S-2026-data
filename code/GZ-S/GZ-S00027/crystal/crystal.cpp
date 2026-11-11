//GZ-S00027 ½ªÔ£Î° 
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int n,m;
int a[500005];
int b[500005];
bool aaa(int x)
{
	for(int i=x;i<=n;i++)
	{
		if(a[i]*x-(b[i]-b[i-x])<=m) return 1;
	}
	return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		b[i]=b[i-1]+a[i];
	}
	int l=1,r=n;
	int ans=1;
	while(l<=r)
	{
		int mm=(l+r)/2;
		if(aaa(mm))
		{
			l=mm+1;
			ans=mm;
		}
		else
		{
			r=mm-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
