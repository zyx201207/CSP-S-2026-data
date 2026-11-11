#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 5e5 + 10;
int n, m;
int a[N], sum[N];
signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	scanf("%lld%lld", &n, &m);
	for(int i = 1; i <= n; i ++ )
		scanf("%lld", &a[i]);
	sort(a + 1, a + n + 1);
	int ans = 0;
	for(int i = 1; i <= n; i ++ )
	{
		sum[i] = sum[i - 1] + a[i]; 
		int l = 0, r = i;
		while(l + 1 < r)
		{
			int mid = (l + r) >> 1;
			if(a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m)
				r = mid;
			else
				l = mid;
		}
		ans = max(ans, i - r + 1);
	}
	cout << ans << endl;
	return 0;				
} 
