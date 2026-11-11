#include <bits/stdc++.h>
#include <cstdio>
using namespace std;
#define ll long long
ll n,m,a[500010],s[500010],bns = 0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1; i<=n; i++) scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1; i<=n; i++) s[i] = s[i-1] + a[i];
	for(int i=1; i<=n; i++)
	{
		ll l = 1, r = i, ans;
		while(l <= r)
		{
			ll mid = (l+r)/2;
			if((i-mid+1)*a[i]-(s[i]-s[mid-1])<=m)
			{
				r = mid-1;
				ans = mid;
			}
			else l = mid+1;
		}
		bns = max(bns,i-ans+1);
	}
	cout << bns;
	return 0;
}