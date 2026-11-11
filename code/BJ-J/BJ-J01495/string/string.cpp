#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[200005],ans;
char c[200005];
signed main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin >> n;
	for (int i = 1;i <= n;i++)
		cin >> a[i] >> c[i];
	int be = 1,ed = n;
	int pr = a[1],su = a[n];
	int lst = 0;
	while (be < ed)
	{
		if (pr > su)
		{
			if (c[be] != c[ed])
				ans += su - lst;
			lst = su;
			su += a[--ed];
		}
		else
		{
			if (c[be] != c[ed])
				ans += pr - lst;
			lst = pr;
			pr += a[++be];
		}
	}
	cout << ans;
	return 0;
}
