/*
 * 小 R 有 n 颗能量水晶,其中第 i (1 ≤ i ≤ n) 颗的能量值为整数 a i 。
小 R 想用其中若干颗能量水晶合成一颗大水晶,用于合成的水晶必须具有相同的
能量值。小 R 希望参与合成的水晶尽可能多。他可以进行 至
. 多
. m 次操作。每次操作可
以任选一颗水晶,将其能量值增加 1;同一颗水晶可以被重复选择。
你需要帮助小 R 求出,进行至多 m 次操作后,他最多能用多少颗能量水晶合成一
颗大水晶。
 */

#include "bits/stdc++.h"
#define int long long
using namespace std;
int n, m, a[500005], pre[500005];
bool check(int x)
{
	for(int i = x;i <= n;i++)
	{
		int ch = (a[i] * x) - (pre[i] - pre[i - x]);
		if(ch <= m)
		{
			return 1;
		}
	}
	return 0;
}
signed main()
{
	cin.tie(0);
	ios::sync_with_stdio(false);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	for(int i = 1;i <= n;i++)
	{
		pre[i] = pre[i - 1] + a[i];
	}
	int l = 1, r = n, mid, ans;
	while(l <= r)
	{
		mid = (l + r) / 2;
		if(check(mid))
		{
			ans = mid;
			l = mid + 1;
		}else
		{
			r = mid - 1;
		}
	}
	cout << ans;
	return 0;
}
