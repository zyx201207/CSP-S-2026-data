#include <bits/stdc++.h>
using namespace std;

long long a[200005],b[200005],m1[200005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m,num = 1;
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = i; j <= n; j++)
		{
			for (int k = 1; k <= num - 1; k++)
			{
				if (b[k] == a[j])
				{
					for (int o = k; o <= num - 1; o++)
					{
						b[o] = 0;
					}
					num = k + 1;
					break;
				}
			}
			b[num++] = a[j];
		}
		for (int j = 1; j <= num; j++)
		{
			m1[b[j]]++;
		}
		for (int j = 1; j <= n; j++)
		{
			b[j] = 0;
		}
		num = 1;
	}
	for (int i = 1; i <= m; i++)
	{
		cout << m1[i] << " ";
	} 
	return 0;
}
