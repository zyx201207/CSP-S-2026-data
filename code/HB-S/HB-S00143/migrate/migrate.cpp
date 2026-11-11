#include <bits/stdc++.h>
using namespace std;
int c;
long long t;
long long tot = 0;

int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	
	cin >> c >> t;
	while (t--)
	{
		long long n, d;
		cin >> n >> d;
		long long a[100005];
		for (int i = 1; i <= n; i++) cin >> a[i];
		for (int i = 1; i <= n; i++) 
		{
			for (int j = i + 2; j <= n; j++)
			{
				long long cnt = 0;
				for (int k = i + 1; k < j; k++)
				{
					if (abs(a[k] - a[i]) <= d && abs(a[j] - a[k]) <= d)
					{
						cnt++;
					}
				}
				if (cnt == 2) tot++;
			}
		}
		cout << tot << "\n";
		tot = 0;
	}
	return 0;
}
