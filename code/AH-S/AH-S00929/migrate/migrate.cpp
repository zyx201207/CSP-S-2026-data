#include <bits/stdc++.h>
using namespace std;

long long c,t,n,d,x[2000006],ans[100005];

int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	for (int q = 1;q<=t;q++)
	{
		cin >> n >> d;
		
		for (int i = 1;i<=n;i++)
		{
			cin >> x[i];
		}
		sort(x + 1,x + n + 1);
		if (n <= 3)
		{
			cout << "0" << endl;
		}
		else
		{
			if (d < (x[2] - x[1]))
			{
				cout << "0" << endl;
			}
			else if (n == 4 && d < (x[3] - x[1]))
			{
				cout << "0" << endl;
			}
			else if (d >= (x[3] - x[1]))
			{
				int ans = 0;
				ans = (n - 3) * (1 + (n - 3)) / 2;
				cout << ans << endl;
			}
		}
	}
	return 0;
}
