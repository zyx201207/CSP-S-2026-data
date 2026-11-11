#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int a[N];
signed main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,cnt = 1;
	cin >> c >> t;
	while (t -- )
	{
		int n,d;
		cin >> n >> d;
		for (int i = 1;i <= n;i ++ )
		{
			cin >> a[i];
		}
		cout << cnt;
		cnt ++;
	}
}
