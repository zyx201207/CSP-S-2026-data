#include <bits/stdc++.h>
using namespace std;
int n, m, a[1000001], maxn = 0;
int main()
{
	freopen("and.in", "r", stdin);
	freopen("and.out", "w", stdout);
	cin >> n >> m;
	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	if(m == 2)
	{
		for(int i = 1; i <= n; i++)
		{
			for(int j = 1; j <= n; j++)
			{
				if(i != j)
				{
					int x = a[i] & a[j];
					if(x > maxn)
						maxn = x;
				}
			}
		}
		cout << maxn;
	}
	else if(m == 1)
	{
		for(int i = 1; i <= n; i++)
		{
			if(a[i] > maxn)
				maxn = a[i];
		}
		cout << maxn;
	}
	return 0;
} 
