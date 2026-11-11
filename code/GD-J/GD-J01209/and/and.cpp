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
const int MAXN = 2e5 + 10;
int a[MAXN], dp[MAXN];
int n, m, sum, max_one, ans;
signed calc1()
{
	int ALL = (1 << n) - 1, ans = -1e18;
	for (int S = 0; S <= ALL; S++)
	{
		if (__builtin_popcount(S) != m)    continue;
		int res = sum;
		for (int i = 1; i <= n; i++)    if ((S >> (i - 1)) & 1)    res &= a[i];
		ans = max(ans, res);
	}
	cout << ans << endl;
	return 0;
}
signed calc2()
{
	int maxn = -1e18;
	for (int i = 1; i <= n; i++)    maxn = max(maxn, a[i]);
	cout << maxn << endl;
	return 0;
}
signed calc3()
{
	int ret = sum;
	for (int i = 1; i <= n; i++)    ret &= a[i];
	cout << ret << endl;
	return 0;
}
signed calc4()
{
	int ret = 0;
	for (int i = 1; i <= n; i++)    for (int j = 1; j <= n; j++)    ret = max(ret, a[i] & a[j]);
	cout << ret << endl;
	return 0;
}
signed main()
{
	ios :: sync_with_stdio(false);
	cin.tie(nullptr), cout.tie(nullptr);
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)    cin >> a[i];
	for (int i = 1; i <= n; i++)    sum |= a[i];
	
	// 数据点1~5 
	if (n <= 20)    return calc1();
	
	// 数据点6
	if (m == 1)    return calc2(); 
	
	// 数据点7
	if (m == n)    return calc3(); 
	
	// 数据点8~10
	if (n <= 3e3 && m == 2)    return calc4();
	
	dp[0] = sum;
	for (int i = 1; i <= n; i++)    for (int j = m; j >= 0; j--)    if (j >= 1)
		dp[j] = max(dp[j], dp[j - 1] & a[i]);
	cout << dp[m];
	return 0;
}

