#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
#include <vector>
#define int long long
#define endl "\n"
#define fi first
#define se second
using namespace std;
const int MAXN = 5e5 + 10;
int n, m, ans, d = -1, max_ai = -1e18, min_ai = 1e18;
int a[MAXN];
bool flag = true;
signed solve1()
{
	int l = 1, r = 1e9, ans = 0;
	while (l <= r)
	{
		int mid = (l + r) >> 1;
		if (d * mid * (mid - 1) <= m)    ans = mid, l = mid + 1;
		else    r = mid - 1;
	}
	cout << min(ans + 1, n);
	return 0;
}
signed main()
{
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		max_ai = max(max_ai, a[i]);
		min_ai = min(min_ai, a[i]);
		if (i == 1)    continue;
		if (d == -1)    d = a[i] - a[i - 1];
		else if (a[i] - a[i - 1] != d)    flag = false;
	}
	if (flag)    return solve1();
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)// 枚举加到哪一个高度
	{
		int to = a[i], tot = 0, cnt = 0;
		for (int j = i; j >= 1; j--)
		{
			if (tot + (to - a[j]) > m)    break;
			tot += (to - a[j]), cnt++;
		}
//		cout << i << " " << a[i] << " " << cnt << endl;
		ans = max(ans, cnt);
	} 
	cout << ans;
	return 0;
}

