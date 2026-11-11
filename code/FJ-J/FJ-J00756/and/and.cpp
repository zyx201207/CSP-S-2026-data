#include <bits/stdc++.h>
using namespace std;
int n, m, s;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	int a[n], d[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	sort (a + 1, a + n + 1);
	int s = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				continue;
			}
			if (a[i] & a[j] >= s)
			{
				s = a[i] & a[j];
			}
		}
	}
	if (m = 1)
	{
		cout << a[n];
		return 0;
	}
	else if (m >= 2 && m <= 5)
	{
		cout << s;
		return 0;
	}
	else
	{
		cout << 1;
		return 0;
	}
	return 0;
}
