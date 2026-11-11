#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 5, INF = 0x3f3f3f3f;
int c, t, n, d, f[N], sum, x[N];
signed main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin >> c >> t;
	while(t --)
	{
		sum = 0;
		cin >> n >> d;
		for(int i = 1;i <= n;i ++)
		{
			cin >> x[i];
		}
		for(int i = 2;i <= n;i ++)
		{
			if(i > d)
			{
				break;
			}
			f[i] = n - i - 1;
			sum += f[i];
		}
		cout << sum << '\n';
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

*/

