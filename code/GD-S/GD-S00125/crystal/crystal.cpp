#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005];
ll s[500005];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	ll m;
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)
	{
		s[i]=s[i-1]-a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i;
		int pos=n+1;
		while(l<=r)
		{
			int mid=(l+r)>>1;
			ll nd=a[i]*(i-mid+1)+(s[i]-s[mid-1]);
			if(nd<=m)
			{
				pos=mid;
				r=mid-1;
			}
			else
			{
				l=mid+1;
			}
		}
		ans=max(ans,i-pos+1);
	}
	printf("%d",ans);
	return 0;
}
