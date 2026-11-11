#include <iostream>
#include <algorithm>
using namespace std;
long long n, m, ans, cnt, maxx;
struct Number
{
	long long x, siz;
}a[200005];
bool cmp(Number y, Number z)
{
	if (y.siz == z.siz)
	{
		return y.x > z.x;
	}
	return y.siz > z.siz;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i].x;
		if (i == 1)
		{
			cnt = a[i].x;
		}
		else
		{
			cnt &= a[i].x;
		}
		maxx = max(maxx, a[i].x);
		long long y = a[i].x;
		while (y)
		{
			if (y & 1)
			{
				a[i].siz++;
			}
			y >>= 1;
		}
	}
	if (m == 1)
	{
		cout << maxx;
		return 0;
	}
	if (m == n)
	{
		cout << cnt;
		return 0;
	}
	sort(a + 1, a + n + 1, cmp);
	ans = a[1].x;
	for (int i = 2; i <= m; i++)
	{
		ans &= a[i].x;
	}
	cout << ans;
	return 0;
} 
