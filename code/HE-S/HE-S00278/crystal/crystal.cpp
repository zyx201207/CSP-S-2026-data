#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int p[N],a[N],sum[N];
int n,m,ans;
bool check(int l,int r)
{
	if(sum[r]-sum[l]-(a[r]-a[l])*(l-1)<=m)return 1;
	else return 0;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
	{
		p[i]=a[i]-a[i-1];
		sum[i]=sum[i-1]+p[i]*(i-1);
	}
	for(int i=1;i<=n;i++)
	{
		int l=1,r=i,oka=i;
		while(l<=r)
		{
			int mid=(l+r)/2;
			if(check(mid,i))
			{
				r=mid-1;
				oka=mid;
			}
			else l=mid+1;
		}
		ans=max(ans,i-oka+1);
	}
	printf("%lld",ans);
	return 0;
}
