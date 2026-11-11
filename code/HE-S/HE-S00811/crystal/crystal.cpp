#include <bits/stdc++.h>
#define int long long

using namespace std;
const int N = 5e5 + 30;

int n, m;
int a[N];
int f[N];
int sum;
int ans;
bool vis, io;
int wb;

signed main()
{
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i ++)
	{
		cin >> a[i];
		if (a[i] != i) vis = 1;
		if (i == 2) wb = a[i] - a[i - 1];
		if (i > 2 && a[i] - a[i - 1] != wb) io = 1; 
	}
	sort (a + 1, a + 1 + n);
	if (!vis)
	{
		for (int i = n; i >= 1; i --)
		{
			int op = (i - 1) * i / 2;
			if (op <= m)
			{
				cout << i;
				return 0;
			}
		}
	}
	if (!io)
	{
		for (int i = n; i >= 1; i --)
		{
			int op = (wb + wb * (i - 1)) * (i - 1) / wb;
			if (op <= m)
			{
				cout << i;
				return 0;
			}
		}
	}
	for (int i = 1; i < n; i ++)
	{
		f[i] = a[i + 1] - a[i];
		sum += a[n] - a[i];
	}
	if (sum <= m)
	{
		cout << sum;
		return 0;
	}
	for (int i = n - 1; i >= 1; i --)
	{
		sum -= f[i] * i;
		if (sum <= m)
		{
			cout << i;
			return 0;
		}
	}
	return 0;
}
/*
	我好区。T1都切不了。。 
	算了。一切都要结束了。
	再见OI 
*/
