#include <bits/stdc++.h>
using namespace std;
long long n,m;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	long long a[n],e[m];
	for (int i = 1;i <= m;i++)
	{
		e[i] = 0;
	}
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i <= n;i++)
	{
		for (int j = n;j >= i;j--)
		{
			if (a[i] == a[j])
			{
				for (int f = j;f <= n;f++)
				{
					e[a[f]]++;
				}
				break;
			}
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << e[i] << " "; 
	}
	return 0;
}
