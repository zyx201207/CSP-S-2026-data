#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,ans=1,a[500005],d[500005];
bool check(int x)
{
	int need=2e18;
	for(int i=x;i<=n;i++)
		need=min(need,a[i]*x-(d[i]-d[i-x-1]));
	return need<=m;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)d[i]=d[i-1]+a[i];
	int l=0,r=n+1,ans=0;
	while(l+1<r)
	{
		//cout<<l<<" "<<r<<" "<<(l+r)/2<<endl;
		int mid=(l+r)/2;
		if(check(mid))ans=max(ans,mid),l=mid;
		else r=mid;
	}
	printf("%lld",ans);
} 
