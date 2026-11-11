#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[1700000],sum[1700000];
int n,m;
bool chk(int l,int r,int v)
{
	if(v*(r-l+1)-(sum[r]-sum[l-1])<=m) return true;
	return false;
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
		sum[i]=sum[i-1]+a[i];
	}
	int an=1;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,ans=i;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			if(chk(mid,i,a[i]))
			{
				ans=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		an=max(an,i-ans+1);
	}
	printf("%lld",an);
}
