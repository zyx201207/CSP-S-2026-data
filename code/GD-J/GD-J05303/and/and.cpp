#include <bits/stdc++.h>
using namespace std;
long long a , c[10000005];
int main()
{
	long long n , m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) cin >> c[i];
	freopen("and.in" , "r" , stdin);
	freopen("and.out" , "w" , stdout);
	if (m == 2)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				long long b = c[i] & c[j];
				a = max(a , b);
			}
		}
	}
	else if(m == 1)
	{
		for (int i = 1; i <= n; i++) a = max(a , c[i]);
	}
	else if(m == n)
	{
		a = c[1];
		for (int i = 2; i <= n; i++) a = c[i] & a;
	}
	else if(m == 3)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				
				for(int h = j + 1; h <= n; h++)
				{
					long long b = c[i] & c[j] & c[h];
					a = max(a , b);
				}
			}
		}
	}
	else if(m == 4)
	{
		for (int i = 1; i <= n; i++)
		{
			for (int j = i + 1; j <= n; j++)
			{
				
				for(int h = j + 1; h <= n; h++)
				{
					
					for (int k = h + 1; k <= n; k++)
					{
						long long b = c[i] & c[j] & c[h] & c[k];
						a = max(a , b);
					}
				}
			}
		}
	}
	cout << a;
	return 0;
}
