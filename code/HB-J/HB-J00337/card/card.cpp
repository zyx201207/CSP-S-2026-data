#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	int a[n],c[n] = {0};
	bool b[n];
	for (int i = 0;i < n;i ++)
	{
		cin >> a[i];
	}
	for (int i = 1;i < n;i ++)
	{
		for (int j = 0;j < i;j ++)
		{
			if (a[j] == a[i])
			{
				for (int k = j;k < i;k ++)
				{
					b[k] = false;
				}
			}
		}
		for (int j = 0;j < i;j ++)
		{
			if (b[i] != false && a[i] == i)
			{
				c[i] ++;
				break;
			}
		}
	}
	for (int i = 0;i < n;i ++)
	{
		cout << c[i] << " ";
	}
	return 0;
}
