#include <bits/stdc++.h>
using namespace std;
int main ()
{
	freopen ("card.in", "r", stdin);
	freopen ("card.out", "w", stdout);
	long n, m;
	cin >> n >> m;
	long a[n+5], b[n+5], sum[m+5], s = 0;
	for (int i=1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i=1;i<=m;i++)
	{
		sum[i] = 0;
	}
	for (int i=1;i<=n;i++)
	{
		for (int j=i;j<=n;j++)
		{
			for (int k=i;k<j;k++)
			{
				if (a[j] == b[k])
				{
					s = j-k;
					for (int r=k;r<j;r++)
					{
						b[r] = -1;
					}
					break;
				}
			}
			b[j-s] = a[j];
		}
		for (int j=i;j<=n-s;j++)
		{
			if (b[j] != -1)
			{
			    sum[b[j]]++;
			}
		}
		s = 0;
	}
	for (int i=1;i<=m;i++)
	{
		cout << sum[i] << " ";
	}
	return 0;
 } 
