#include<bits/stdc++.h>
using namespace std;
const long long N = 5e3 + 10;
long long c, t, n, d, a[N], cnt, D;
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	cin >> c >> t;
	for(int op = 1;op <= t;op++)
	{
		cin >> n >> d;
		for(long long i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		D = a[2] - a[1];
		if(2 * D - 1 >= d)
		{
			cout << 0;
		}else if(3 * D <= d)
		{
			cout << 0;
		}else
		{
			cout << n - 3;
		}
		cout << "\n";
	}
	return 0;
}
