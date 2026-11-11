#include <bits/stdc++.h>
using namespace std;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	int b[500009];
	cin >> n >> m;
	if (n > 5000)
	{
		long long bbb = 0;
		for (int i = 1;i <= n;i++)
		{
			bbb += i;
			if (bbb > m)
			{
				cout << i;
				return 0;
			}
		}
	}
	else
	{
		long long sum = 0;
		for (int i = 1;i <= n;i++)
		{
			cin >> b[i];
		}
		sort (b + 1,b + n + 1);
		for (int qwq = 1;qwq <= n;qwq++)
		{
			int k = qwq;
			long long aaa = 0;
			for (int i = 1;i <= k;i++)
			{
				for (int j = i;j <= n - k + 1;j++)
				{
					aaa += b[n - k + 1] - b[j];
				} 
				if (aaa <= m)
				{
					cout << n - k + 1;
					return 0;
				}
			}
		}
	}
	return 0;
}
