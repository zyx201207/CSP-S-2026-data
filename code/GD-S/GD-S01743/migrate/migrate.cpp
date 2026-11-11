#include <bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 2e6 + 5;
int c,t,n,d,a[maxn];
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0); 
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	while (t--)
	{
		int n,d;
		cin >> n >> d;
		for (int i = 1;i <= n;i++)
		{
			cin >> a[i];
		}
		cout << n - 3 << endl;
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
