#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll N=500000;
ll n,m,l,r,sum,ans;
ll a[N+10],sub[N+10];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(ll i=1;i<=n;++i)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i)sub[i]=a[i]-a[i-1];
	l=r=1;
	while(r<n)
	{
		++r,sum+=(r-l)*sub[r];
		while(sum>m)sum-=a[r]-a[l++];
		if(r-l+1>ans)ans=r-l+1;
	}
	printf("%lld",ans);
	return 0;
}
