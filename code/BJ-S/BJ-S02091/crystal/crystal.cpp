#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int w[N], a[N];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m, i, ans = 0;
	scanf("%lld%lld", &n, &m);
	for(i=1;i<=n;i++) scanf("%lld", &a[i]);
	sort(&a[1],&a[n]+1);
	for(i=1;i<=n;i++) w[i] = w[i-1] + a[i];
	for(i=1;i<=n;i++)
	{
		int l = 1, r = i, mid;
		while(l<r)
		{
			mid = (l + r) >> 1;
			if(a[i]*(i-mid+1)-(w[i]-w[mid-1])<=m) r = mid;
			else l = mid + 1;
		}
		ans = max(ans,i-l+1);
	}
	printf("%lld\n", ans);
	return 0;
}