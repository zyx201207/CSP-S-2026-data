#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 10, M = 3e5 + 10;
#define lowbit(x) ((x) & -(x))

int n, m, a[N], lst[M], ans[M], fl[N];

signed main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin.tie(0) -> sync_with_stdio(0);
	cin >> n >> m;
	for (int i = 1; i <= n; ++i) cin >> a[i];
	for (int i = 1; i <= n; ++i)
	{
		memset(fl, 0, sizeof fl);
		for (int j = i; j <= n; ++j)
		{
			map<int, bool> mp; int flag = 1;
			for (int k = j - 1; k >= i; --k) mp[a[k]] = 1;
			for (int k = j + 1; k <= n; ++k)
			{
				if (mp[a[k]])
				{
					flag = 0;
					break;
				}
			}
			fl[a[j]] |= flag;
		}
		for (int j = 1; j <= m; ++j) ans[j] += fl[j]; 
	}
	for (int i = 1; i <= m; ++i) cout << ans[i] << ' ';
	return 0; 
} 

/*
10 3
3 1 2 1 3 2 3 1 2 1
*/
