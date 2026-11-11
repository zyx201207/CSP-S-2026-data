#include <bits/stdc++.h>
#define int long long
using namespace std;
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n, m, ans = -1e18;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0, a1 = -1e18;
		for (int j = i; j <= n; j++)
		{
			cnt += a[j];
			a1 = max(a1, a[j]);
			int l = j - i + 1;
			if (cnt >= (a1 * l) - m) ans = max(ans,l);
			
		}
		
	}
	cout << ans;
	return 0;
 } 
