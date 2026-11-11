#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e6 + 10;
LL c, t, n, d, dis[N];
int main()
{
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	cin >> c >> t;
	while (t--)
	{
		cin >> n >> d;
		for (int i = 1; i <= n; i++)
		{
			cin >> dis[i];
			
		}
		int itv = dis[2] - dis[1];
		int _itv = d / itv;
		cout << n - (itv*2-1) << endl;
	}
	return 0;
}
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6
*/
