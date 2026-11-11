#include <bits/stdc++.h>
using namespace std;
const int Maxn = 5e5 + 5;

long long a[Maxn];

int main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	long long n, m;
	cin >> n >> m;
	for (long long i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + n + 1);
	long long maxn = -1e9;
	for (long long i = 1; i <= n; i++)
	{
		long long sum = 0, cnt = 0;
		for (long long j = i; j >= 1; j--)
		{
			sum = sum + (a[i] - a[j]);
			if (sum <= m)
			{
				cnt++;
				maxn = max(maxn, cnt);
			}
			else
			{
				break;
			}
		}
	}
	cout << maxn << endl;
	return 0;
}
