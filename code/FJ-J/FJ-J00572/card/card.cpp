#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long b[500005];
long long c[500005];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin >> n >> m;
	for(int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	for(int i = 1;i <= n;i++)
	{
		for(int j = i;j <= n;j++)
		{
			for(int z = i;z <= j;z++)
			{
				if(a[j] == b[z])
				{
					for(int k = z;k <= j;k++)
					{
						b[k] = 0;
					}
				}
			}
			b[j] = a[j];
		}
		for(int j = 1;j <= n;j++)
		{
			c[b[j]]++;
			b[j] = 0;
		}
	}
	for(int i = 1;i <= m;i++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
