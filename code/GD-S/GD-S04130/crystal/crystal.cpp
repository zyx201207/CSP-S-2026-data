#include<bits/stdc++.h>
using namespace std;
int n,ans;
long long a[500005],m,h[500005];
bool ck(int x)
{
	for(int i=x;i<=n;i++)
	{
		long long cnt=a[i]*x-(h[i]-h[i-x]);
		if(cnt<=m) return 1;
	}
	return 0;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) h[i]=h[i-1]+a[i];
	int l=1,r=n;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(ck(mid))
		{
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	printf("%d",ans);
	return 0;
}
