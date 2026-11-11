#include <bits/stdc++.h>
using namespace std;
int de(int a,int b)
{
	if (a - b <= 0)
	{
		return -1*(a - b);
	}
	else
	{
		return (a - b);
	} 
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int c,t;
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		int n,d;
		cin >> n >> d;
		vector<int> a;
		for (int j = 0;j < n;j++)
		{
			int p;
			cin >> p;
			a.push_back(p);
		}
		int sum = 0;
		for (int j = 1;j < n;j++)
		{
			for (int k = j;k < n;k++)
			{
				if (de(a[k],a[j]) % d != 0 && de(a[k],a[j]) <= d)
				{
					if ((de(a[k],a[j]) / d) + 1 == 2)
					{
						sum++;
					}
				}
				else if (de(a[k],a[j]) % d == 0 && de(a[k],a[j]) <= d)
				{
					if (((double)de(a[k],a[j]) / 2.0) == 1.0)
					{
						sum++;
					}
				}
			}
		}
		cout << sum << '\n';
	}
	return 0;
}
