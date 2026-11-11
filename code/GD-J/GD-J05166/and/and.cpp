#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	long long m, n;
	cin >> n >> m;
	vector<long long> a(n), b(n, 0);
	for (long long i = 0; i < n; i += 1)
	{
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	if (m == 1)
	{
		cout << a[n - 1];
		return 0;
	}
	if (m == n)
	{
		long long x = (a[0] & a[1]);
		for (long long i = 2; i < n; i++)
		{
			x = (x & a[i]);
		}
		cout << x;
		return 0;
	}
	if (m == 2)
	{
		long long mmm = 0;
		for (long long i = 0; i < n; i++)
		{
			for (long long j = i + 1; j < n; j++)
			{
				mmm = max((a[i] & a[j]), mmm);
			}
		}
		cout << mmm;
		return 0; 
	}
	return 0;
} 
