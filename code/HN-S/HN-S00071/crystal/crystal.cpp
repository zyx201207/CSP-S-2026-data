#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
int n, m, t;
int a[500005];
signed main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
	}
	sort(a + 1, a + 1 + n);
	for (int i = 1; i <= n; i++)
	{
		int ans = 0;
		for (int j = 1;j < i; j++)
		{
			ans += a[i] - a[j];
		}
		if (ans > m)
		{
			cout << t;
			break;
		}
		t = i;
	}
	return 0;
}

