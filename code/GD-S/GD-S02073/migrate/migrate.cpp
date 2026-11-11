#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5;
int n , m , d , cc , a[N] , nxt[N] , pre[N];
int f[N][3] , cnt[N];
signed main ()
{
	freopen ("migrate.in" , "r" , stdin);
	freopen ("migrate.out" , "w" , stdout);
	ios::sync_with_stdio (0);
	cin.tie (0) , cout.tie (0);
	int T;
	cin >> T >> T;
	while (T --)
	{
		cin >> n >> d;
		for (int i = 1;i <= n;i ++) cin >> a[i] , cnt[i] = 0;
		for (int i = 1;i <= n;i ++)
		{
			f[i][0] = f[i][1] = f[i][2] = 0;
			nxt[i] = upper_bound (a + 1 , a + n + 1 , a[i] + d) - a - 1;
			pre[i] = lower_bound (a + 1 , a + n + 1 , a[i] - d) - a;
		}
		int ans = 0;
		for (int i = 1;i <= n;i ++)
		{
			int j = pre[i];
			if (i == j)
			{
				cnt[nxt[i]] ++;
				continue;
			}
			int p = j;
			while (p < i) p = nxt[p];
			if (p == i) f[i][0] = f[j][0];
			else if (p == i + 1) f[i][1] = f[j][0];
			ans += f[j][2] + (j + 1 != i) * f[j][1];
			if (p == i) f[i][2] = f[j][2];
			p = j + 1;
			while (p < i) p = nxt[p];
			if (p == i && j + 1 != i) f[i][2] += f[j][1];
			cnt[nxt[i]] ++;
			f[i][0] += cnt[i];
			f[i][1] += cnt[i + 1];
		}
		cout << ans << '\n';
	}
	return 0;
}
