#include <bits/stdc++.h>
using namespace std;
int n,m,p;
long long a[500005],b[500005],q[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> q[i];
	}
	for (int o = 1;o <= n;o++)
	{
		for (int i = o;i <= n;i++)
		{
			p = q[i];
			for (int j = 1;j <= n;j++)
			{
				if (p == a[j])
				{
					for (int k = i;k < j;k++)
					{
						a[k] = 0;
					}
			    }
			}
			a[i] = p;
			p = 0;
		}
		for (int i = 1;i <= n;i++)
		{
			if (a[i] != 0)
			{
				b[a[i]]++;
			}
		}
		for (int i = 1;i <= n;i++)
		{
			a[i] = 0;
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << b[i] << " ";
	}
	return 0;
}
