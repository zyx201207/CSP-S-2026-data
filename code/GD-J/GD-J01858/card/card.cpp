#include <bits/stdc++.h>
using namespace std;
int n,m,a[500005],b[300005],maxx[300005],maxx_l[300005];
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> a[i];
	}
	if (m <= 2)
	{
		for (int i = 1;i <= n;i++)
		{
			if (a[i] == 1)
			{
				maxx_l[0] = maxx[0];
				maxx[0] = i;
			}
			else
			{
				maxx_l[1] = maxx[1];
				maxx[1] = i;
			}
		}
		if (maxx[0] < maxx_l[1])
		{
			cout << maxx[0] << " ";
		}
		else if (maxx[0] > maxx_l[1] && maxx[0] < maxx[1])
		{
			cout << maxx[0] - maxx_l[1] << " ";
		}
		else
		{
			cout << maxx[0] << " ";
		}
		if (maxx[1] < maxx_l[0])
		{
			cout << maxx[1];
		}
		else if (maxx[1] > maxx_l[0] && maxx[1] < maxx[0])
		{
			cout << maxx[1] - maxx_l[0];
		}
		else
		{
			cout << maxx[1];
		}
		return 0;
	}
	for (int i = 1;i <= n;i++)
	{
		maxx[a[i]] = i;
	}
	for (int i = 1;i <= m;i++)
	{
		cout << maxx[i];
	}
	return 0;
}
