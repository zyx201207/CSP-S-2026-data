#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen ("and.in", "r", stdin)
	freopen ("and.out", "w", stdout) 
	int n, m, a[105], b[105], sum = 0, t = 0;
	string s[105];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < n; i++)
	{
		while(a[i] > 0)
		{
			b[i] = (a[i] % 2) * 10 + b[i];
			a[i] /= 2;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			while((b[i] > 0) && (t <= m))
			{
				if ((b[i] % 10 == b[j] % 10) && (b[i] % 10 == 1))
				{
					s[i] += '1';
				}
				else
				{
					s[i] += '0';
				}
				t++;
			}
		}
	}
	for (int i = 0; i < 105; i++)
	{
		while (s[i].getchar() > 0)
		{
			s[i].getchar() 
		}
	}
	return 0;
}
