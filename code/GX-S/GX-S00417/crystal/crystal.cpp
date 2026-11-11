#include <bits/stdc++.h>
using namespace std;
long long n, m, a[100010], t;
int main ()
{
	freopen ("crystal.in", "r", stdin);
	freopen ("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort (a+1, a+1+n);
	for (int i = 2; i <= n; i++)
	{
		long long f = m, c = 1;
		for (int j = i-1; j >= 1; j--)
		{
			f -= a[i] - a[j];
			if (f < 0)
				break;
			c++;
		}
		t = max (t, c);
	}
	cout << t;
	return 0;
}
