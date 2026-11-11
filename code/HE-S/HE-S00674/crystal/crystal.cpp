#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N=5e5+50;
ll n,i;
ll m,a[N],ans;
bool check(ll t)
{
	ll cnt=0,sum=0;
	for(i=t-1;i>=1;i--)
	{
		cnt+=(a[t]-a[i]);
		if(cnt>m) return 0;
		sum++;
		ans=max(ans,sum);
	}
	return 1;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cin>>n>>m;
	ll l=1,r=n;
	for(i=1;i<=n;++i) cin>>a[i];
	sort(a+1,a+n+1);
	while(l<=r)
	{
		ll mid=(l+r)/2;
		if(check(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<<ans+1;
	return 0;
}
