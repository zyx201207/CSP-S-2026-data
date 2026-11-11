#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n];
	for (int i = 0;i <= n - 1;i++)
	{
		cin >> a[i];
	}
	int max = -1;
	for (int i = 0;i < n;i++)
	{
		for (int j = i + 1;j < n;j++)
		{
			int de = (a[i] & a[j]);
			
			if (max <= de)
			{
				max = de;
			}
		}
	}
	cout << max;
	int sum = 0;
	for (int i = 0;i < n;i++)
	{
		for (int j = i;j < n;j++)
		{
			if (max == (a[i] & a[j]))
			{
				sum++;
			}
		}
	}
	return 0;
}
