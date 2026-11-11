#include <iostream>
#include <map>
#include <algorithm>
#include <climits>

#define int long long

int n, m;
int a[500005];
int ans;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	
	std::cin >> n >> m;
	int minn = LLONG_MAX, maxn = LLONG_MIN;
	for (int i = 1; i <= n; i++)
	{
		std::cin >> a[i];
		minn = std::min(minn, a[i]);
		maxn = std::max(maxn, a[i]);
	}
	std::sort(a + 1, a + n + 1, std::greater<int>());
	for (int i = minn; i <= maxn; i++)
	{
		int s = m;
		int cnt = 0;
		for (int j = 1; j <= n && s >= 0; j++)
		{
			if (a[j] > i)
			{
				continue;
			}
			else if (a[j] == i)
			{
				cnt++;
			}
			else if (s >= i - a[j])
			{
				s -= i - a[j];
				cnt++;
			}
			else
			{
				break;
			}
		}
		ans = std::max(ans, cnt);
	}
	std::cout << ans;
	
	return 0;
}
