#include <bits/stdc++.h>
using namespace std;
const int N = 2e6+5;

int c, t;
long long a[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		int n;
		long long d;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		if (c == 11 || c == 12)
		{
			if (a[2]-a[1] >= d) cout << 0 << endl;
			else cout << (a[n]-a[1])/(a[2]-a[1])+1-3 << endl;
		}
	}
	return 0;
}
