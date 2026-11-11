#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	int n, m;
	long long a[200005];
	cin >> n >> m;
	for (int i = 1; i <= n; i++) 
	{
		cin >> a[i];
	}
	sort(a, a + n);
	long long x = a[n];
	for (int i = n; i > n - m; i--)
	{
		x &= a[i];
	}
	cout << x;
	return 0;
}
