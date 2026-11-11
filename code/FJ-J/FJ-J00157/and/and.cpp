#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005];
int and_(int x, int y, int z)
{
	if (z > m)
	{
		return x;
	}
	int s = 0;
	for (int i = y + 1; i <= n - m + z + 1; i++)
	{
		s = max(s, and_(x & a[i], i, z + 1));
	}
	return s;
}
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	cout << and_(0x3FFFFFFF, 0, 1);
	return 0;
}
