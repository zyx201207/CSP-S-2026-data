#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 5;
int n,m,a[N],l,r,nowsum,ans;
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for (int i = 1; i <= n; i++) scanf("%lld",&a[i]);
	sort(a + 1,a + 1 + n);
	l = r = 1;
	while (l <= n)
	{
		while (r <= n)
		{
			r++;
			int nowadd = (a[r] - a[r - 1]) * (r - l);
			if (nowsum + nowadd > m) 
			{
				r--;
				break;
			}
			nowsum += nowadd;
		}
		ans = max(ans,r - l + 1);
		nowsum -= a[r] - a[l];
		l++;
	}
	printf("%lld",ans);
	return 0;
}
