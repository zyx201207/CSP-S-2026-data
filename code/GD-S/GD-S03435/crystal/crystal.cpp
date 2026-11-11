#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1e18;
int n;
ll m,a[500005],sum[500005];
bool check(int len)
{
	ll cost=inf;
	for(int i=len;i<=n;i++) cost=min(cost,a[i]*len-(sum[i]-sum[i-len]));
	return cost<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i];
	int l=1,r=n,ans=1;
	while(l<=r)
	{
		int mid=(l+r)>>1;
		if(check(mid)) l=mid+1,ans=mid;
		else r=mid-1;
	}
	cout<<ans;
	return 0;
}
