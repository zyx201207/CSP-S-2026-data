#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#define int long long
using namespace std;

int a[200010];
char c[200010];

signed main ()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w" ,stdout);
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i] >> c[i];
	}
	int ans = 0;
	int i = 1, j = n;
	while (i < j)
	{
		int min_ij;
		if (a[i] < a[j])
			min_ij = 1;
		else if (a[i] > a[j])
			min_ij = 2;
		else
			min_ij = 3;
		if (c[i] == c[j])
		{
			if (min_ij == 1)
			{
				a[j] -= a[i];
				i++;
			}
			else if (min_ij == 2)
			{
				a[i] -= a[j];
				j--;
			}
			else
			{
				i++;
				j--;
			}
		}
		else
		{
			if (min_ij == 1)
			{
				ans += a[i];
				a[j] -= a[i];
				i++;
			}
			else if (min_ij == 2)
			{
				ans += a[j];
				a[i] -= a[j];
				j--;
			}
			else
			{
				ans += a[i];
				i++;
				j--;
			}
		}
	}
	cout << ans;
	return 0;
}
