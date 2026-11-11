#include <bits/stdc++.h>
using namespace std;
const int N = 2000005;
long long c, t, n, d, ans, r = 1;
long long a[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		cin >> n >> d;
		for(int i = 1; i <= n; i ++) cin >> a[i];	
		long long c = a[1] - a[0];
		for(int i = 1; i < n; i ++)
		{
			if(a[i] - a[i - 1] != c)
			{
				r = 0;
				break;
			}
		}
		if(d < c) cout << 0 << endl;
		else cout << (n - 2) * (n - 3) / 2 << endl;
	}
	return 0;
}