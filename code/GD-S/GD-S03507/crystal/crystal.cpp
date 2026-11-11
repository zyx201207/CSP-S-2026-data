#include <bits/stdc++.h>
#define int long long
using namespace std;
int n, m;
int a[500005], sum[500005];
int ans = 0;
bool check(int st, int x)
{
	if(a[st] * (st-x+1) - (sum[st] - sum[x-1]) <= m) return true;
	return false;
}
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	for(int i = 1; i <= n; i++) sum[i] = sum[i-1] + a[i];
	for(int i = 1; i <= n; i++)
	{
		int l = 1, r = i;
		while(l < r)
		{
			int mid = (l+r) >> 1;
			if(check(i,mid)) r = mid;
			else l = mid+1;
		}
		ans = max(ans,i-r+1); 
	}
	printf("%lld\n",ans); 
	return 0;
}

