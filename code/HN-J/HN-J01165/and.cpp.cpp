#include<bits/stdc++.h>
using namespace std;
long long n, m, a[10005], b[10005];
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 2;i <= n;i++)
	{
		for (int j = 1;j <= m;j++)
		{
			b[i] = a[1] | a[i];
		}
	}
	int max_b = -10005;
	for (int i = 1;i <= n;i++)
	{
		if (b[i] > max_b)
		{
			max_b = b[i];
		}
	}
	cout << max_b;
	return 0;
}
