#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int ans,a[N],pre[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout); 
	int n,m;scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i];
	for(int i=1;i<=n;i++)
	{
		int l=0,r=i;
		while(l+1<r)
		{
			int mid=(l+r)>>1;
			if((i-mid+1)*a[i]-pre[i]+pre[mid-1]<=m)r=mid;
			else l=mid;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld\n",ans);
	return 0;
}
