#include <bits/stdc++.h>
using namespace std;
int n,m,a[600000],b[600000];
int main()
{
	cin >> n >> m;
	for (int i = 1;i<=n;i++)
	{
		cin >> a[i];
	}
	for (int i = 1;i<=n;i++)
	{
		int e = 1;
		while(b[e]!=0)
		{
			b[e] = 0;
			e++;
		}
		for (int j = i;j <= n;j++)
		{
			b[j] = a[j];
			int q = j;
			while(b[q]!=0)
			{
				if (b[q] == b[j])
				{
					int w = q+1;
					while (b[w]!=0)
					{
						b[w] = 0;
						w++;
					}
				}
				q++;
			}
		}
	}
}
