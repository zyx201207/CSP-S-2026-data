#include <bits/stdc++.h>

using namespace std;

int ar[10005],sta[10005],sum[10005];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++)
	{
		cin >> ar[i];
	}
	int tn = n,k = 0;
	while (tn--)
	{
		k++;
		int len = 1;
		for (int i = 1;i <= m;i++)
		{
			sta[len] = i;
			len++;
		}
		for (int i = k;i <= n;i++)
		{
			int t = ar[i];
			bool flag = 1;
			for (int j = 1;j <= len;j++)
			{
				if (sta[j] == t)
				{
					len = j;
					flag = 0;
					break;
				}
			}
			if (flag)
			{
				len++;
				sta[len] = t;
			}
		}
		bool pd[10005] = {};
		for (int j = 1;j <= len;j++)
		{
			if (!pd[sta[j]])
			{
				pd[sta[j]] = 1;
				sum[sta[j]] += 1;
			}
		}
	}
	for (int i = 1;i <= m;i++)
	{
		cout << sum[i] << ' ';
	}
	return 0;
}
