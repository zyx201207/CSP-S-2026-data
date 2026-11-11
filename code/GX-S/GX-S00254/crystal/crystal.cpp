#include <bits/stdc++.h>
using namespace std;
long long n, m, a[5000005];
int num;
int main()
{
	freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	int d = a[n/2+1];
	for (int i = 1; i <= n; i++)
	{
		while(a[i] < d)
		{
			a[i]++;
		}
		if (a[i] == d)
		{
			num++;
		}
	}
	cout << num;
	return 0;
}
