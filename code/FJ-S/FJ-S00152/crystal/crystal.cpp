#include <bits/stdc++.h>
using namespace std;
#define int long long

int a[500010],b[500010];

bool cmp(int x,int y)
{
	return x < y;
}

signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,m;
	cin >> n >> m;
	for (int i = 1;i <= n;i++) cin >> a[i];
	sort(a + 1,a + 1 + n,cmp);
	int ans = 1;
	int l = 1;
	for (int i = 2;i <= n;i++)
	{
		b[i] = b[i - 1] + (a[i] - a[i - 1]) * (i - l);
		while (b[i] > m)
		{
				b[i] -= a[i] - a[l];
				l++;
		}
		ans = max(ans,i - l + 1);
	}
	cout << ans;
	return 0;
}
