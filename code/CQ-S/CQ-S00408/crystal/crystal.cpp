#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N = 5e5 + 10;
int a[N];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i ++ )
	{
		cin >> a[i];
	}
	int ans = -1e18;
	for (int i = 1;i <= n;i ++ )
	{
		for (int j = i + 1;j <= m;j ++ )
		{
			int mx = -1e18;
			for (int k = i;k <= j;k ++ )
			{
				mx = max(a[k],mx);
			}
			int sum = 0;
			for (int k = i;k <= j;k ++ )
			{
				sum += (mx - a[k]);
			}
//			cout << i << " " << j << " : " << endl;
//			cout << mx << endl << endl;
//			cout << sum << endl << endl;
			if (sum <= m) ans = max(j - i + 1,ans);
		}
	}
	cout << ans;
	return 0;
}
