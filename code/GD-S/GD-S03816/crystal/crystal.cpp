#include <bits/stdc++.h>
using namespace std;
long long n, m, a[500005], d, ene, ans;
vector<long long> kon;
bool flag = true;
int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	long long t = m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
		if (a[i] != i)
		{
			flag = false;
		}
	}
	sort(a + 1, a + n + 1);
	if (flag)
	{
		for (long long i = 1; i <= 5 * 1e5; i++)
		{
			ene += i;
			if (ene > m)
			{
				cout << i;
				return 0;
			}
			else if (ene == m)
			{
				cout << i + 1;
				return 0;
			}
		}
	}
	flag = true;
	for (long long i = 2; i <= n; i++)
	{
		kon.push_back(a[i] - a[i - 1]);
		if (i == 2)
		{
			continue;
		}
		if (kon[i] != kon[i - 1])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		d = a[n] - a[n - 1];
		for (long long i = n - 1; i >= 1; i--)
		{
			if (t >= (n - i) * d)
			{
				t -= (n - i) * d;
				ene++;
			}
		}
		cout << ene + 1;
		return 0;
	}
	for (long long i = 2; i <= n; i++)
	{
		for (long long j = i - 1; j >= 1; j--)
		{
			if (a[i] - a[j] <= t)
			{
				ene++, t -= (a[i] - a[j]);
			}
			else
			{
				break;
			}
		}
		ans = max(ans, ene), t = m;
		ene = 0;
	}
	cout << ans + 1;
	return 0;
}
