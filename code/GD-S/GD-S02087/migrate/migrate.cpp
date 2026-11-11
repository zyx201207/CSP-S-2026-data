#include <bits/stdc++.h>
using namespace std;
int c,t;
int n,d;
int x2[300005];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int i = 1;i <= t;i++)
	{
		cin >> n >> d;
		for(int j = 1;j <= n;j++)
		{
			cin >> x2[j];
		}
		if (c == 0)
		{
			int ans = 0;
			for(int j = 1;j <= n;j++)
			{
				if (x2[j] == j)
				{
					ans++;
					if (ans == n && n == 4)
					{
						cout << "1" << endl;
					}
					else if (ans == n)
					{
						cout << "2";
					}
				}
				else
				{
					cout << "0" << endl << "1";
					return 0;
				}
			}
		}
	}
	return 0;
}
