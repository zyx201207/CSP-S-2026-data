#include <bits/stdc++.h>
using namespace std;
int n, m, a[500005], b[300005];
int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		b[a[i]]++;
	}
	b[a[n-1]] = n;
	for (int i = 1; i <= m; i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
