#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
constexpr int N(2e5 + 10);
int a[N];
bool cmp(const int &a, const int &b)
{
	return a > b;
}
char c[N][40];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin.tie(nullptr);
	cout.tie(nullptr);
	ios::sync_with_stdio(false);
	int n = 0, m = 0;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	stable_sort(a + 1, a + n + 1, cmp);
	int num = 0;
	for (int i = 1, t, len; i <= n; i++)
	{
		len = 0;
		t = a[i];
		while (t)
		{
			c[i][++len] = (t % 2 ? '1' : '0');
			t /= 2;
		}
		num = max(num, len);
	}
	int start = 1, end = n;
	for (int i = num; i; i--)
	{
		for (int j = start; j <= end; j++)
			if (c[j][i] == '1')
			{
				start = j;
				break;
			}
		for (int j = start; j <= end; j++)
		{
			if (c[j][i] != '1')
			{
				if (j - start >= m)
				{
					end = j - 1;
				}
				break;
			}
		}
	}
	int ans = a[start];
	for (int i = start; i <= end; i++)
		ans &= a[i];
	cout << ans;
	return 0;
}
