//GZ-S00378 ³ÂË¼Ù¡ 
#include <bits/stdc++.h>

#define int long long
#define endl '\n'

using namespace std;

const int N = 5e5+11;
int n, m;
int a[N];
int sum[N];

inline bool check(int x, int y)
{
	int len = y - x + 1;
	int sum1 = len * a[y];
	int sum2 = sum[y] - sum[x - 1];
	
	return sum1 - sum2 <= m;
}

signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	cin >> n >> m;
	
	for (int i = 1; i <= n; i ++)
		cin >> a[i];
	
	sort(a + 1, a + n + 1);
	
	for (int i = 1; i <= n; i ++)
		sum[i] = sum[i - 1] + a[i];
	
	int ans = min(1LL, n);
	for (int i = 1; i <= n; i ++)
	{
		int l = 1, r = i, res = -1;
		
		while (l <= r)
		{
			int mid = (l + r) >> 1;
			
			if (check(mid, i))
			{
				res = mid;
				r = mid - 1;
			}
			else
				l = mid + 1;
		}
		
		if (res == -1)
			continue;
		
		int len = i - res + 1;
		ans = max(ans, len);
	}
	
	cout << ans << endl;
	
	return 0;
}
