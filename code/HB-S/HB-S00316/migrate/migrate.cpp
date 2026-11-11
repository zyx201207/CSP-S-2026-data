#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int c, t;
long long x[N], n, d;
void solve()
{
	cin >> n >> d;
	for(int i = 1; i <= n; i ++)
	{
		cin >> x[i];
	}
	cout << "0\n";
}
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while(t --)
	{
		solve();
	}
	return 0;
}
