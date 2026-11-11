#include <iostream>
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
const int N = 2e5 + 5;
int n, m, ans, x[N], f[N], b[N];
int g[2005][2005];
inline void dfs(int i, int sum, int num)
{
	if (i > n)
	{
		if (num == m)
		{
			ans = max(ans, sum);
		}
		return;
	}
	if (num < m)
	{
		if (num == 0) dfs(i+1, x[i], num+1);
		else dfs(i+1, sum&x[i], num+1);
	}
	dfs(i+1, sum, num);
}
inline bool lowerbit(int x)
{
	return ((x & (-x)) == x);
}
bool cmp(const int &x, const int &y)
{
	return x > y;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	cin >> n >> m;
	int Max = -1, s;
	bool A = true;
	for (int i = 1; i <= n; i++)
	{
		cin >> x[i];
		if (i == 1) s = x[i];
		else s &= x[i];
		Max = max(Max, x[i]);
		if (!lowerbit(x[i]+1)) A = false;
	}
	if (m == 1)
	{
		cout << Max;
		return 0;
	}
	if (m == n)
	{
		cout << s;
		return 0;
	}
	if (m == 2)
	{
		Max = -1;
		for (int i = 1; i <= n; i++)
		{
			for (int j = i+1; j <= n; j++)
			{
				Max = max(Max, x[i]&x[j]);
			}
		}
		cout << Max;
		return 0;
	}
	if (m == n-1)
	{
		Max = -1;
		for (int i = 1; i <= n; i++)
			f[i] = (i == 1 ? x[i] : f[i-1]&x[i]);
		for (int i = n; i >= 1; i--)
			b[i] = (i == n ? x[i] : b[i+1]&x[i]);
		for (int i = 1; i <= n; i++)
			Max = max(Max, f[i-1]&b[i+1]);
		cout << Max;
		return 0;
	}
	if (A)
	{
		sort(x+1, x+n+1, cmp);
		Max = x[1];
		for (int i = 2; i <= m; i++)
			Max &= x[i];
		cout << Max;
		return 0;
	}
	dfs(1, 0, 0);
	cout << ans;
	return 0;
}
