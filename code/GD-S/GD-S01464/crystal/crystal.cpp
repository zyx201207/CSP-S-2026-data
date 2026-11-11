#include <bits/stdc++.h>
#define int long long
using namespace std;

int a[500005];

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,sum = 0,tmp = 0,h = 1,ans = 0;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + n + 1);
	for (int i = 2;i <= n;i++)
	{
		tmp = sum + (i - h) * (a[i] - a[i - 1]);
		while (tmp > m) tmp = tmp - (a[i] - a[h]),h++;
		ans = max(ans,i - h + 1),sum = tmp;
	}
	cout << ans;
	return 0;
}
