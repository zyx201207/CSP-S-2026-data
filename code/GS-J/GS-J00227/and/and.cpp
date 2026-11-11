#include <bits/stdc++.h>
using namespace std;

int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n,m,a[100000000],b[10000000];
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		b[i] = 0;
	}
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long num = 0,max = 0,id;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			max = 0;
			for (int k = 0; k < n; k++)
			{
				if (b[k] == 1)
				{
					continue;
				}
				if (a[k] & num > max)
				{
					max = a[k];
					id = k;
				}
			}
		}
		num += max;
		b[id] = 1;
	}
	cout << num;
	return 0;
}
