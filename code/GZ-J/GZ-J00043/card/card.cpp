//贵阳市第十九中学 刘承福 GZ-J00043
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[500005], b[500005], c[500005];

int main()
{
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		int cnt = 0;
		bool flag = true;
		for (int j = i; j <= n; j++)
		{
			for (int k = 1; k <= cnt; k++)
			{
				if (a[j] == b[k])
				{
					for (int z = k; z <= cnt; z++)
					{
						b[z] = 0;
					}
					cnt = k - 1;
					b[++cnt] = a[j];
					flag = false;
					break;
				}
			}
			if (flag == true)
			{
				b[++cnt] = a[j];
			}
		}
		for (int j = 1; j <= m; j++)
		{
			for (int k = 1; k <= cnt; k++)
			{
				if (b[k] == j)
				{
					c[j]++;
				}
			}
		
		}
	}
	for (int i = 1; i <= m; i++)
	{
		cout << c[i] << " ";
	}
	cout << endl;
	return 0;
}

