#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, m;
int a[500005], s[500005];
bool ck(int i, int x)
{
	int d = s[i - 1] - s[x - 1];
	return a[i] * (i - x) - d <= m;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("crystal.in", "r", stdin);
	freopen("crystal.out", "w", stdout);
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		cin >> a[i];
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++)
		s[i] = s[i - 1] + a[i];
	int mx = 0;
	for (int i = 2; i <= n; i++)
	{
		int l = 1, r = i - 1;
		while (l < r)
		{
			int mid = (l + r) >> 1;
			if (ck(i, mid))
				r = mid;
			else
				l = mid + 1;
		}
//		cout << l << endl;
		int nw = i - l + 1;
		mx = max(mx, nw);
	}
	cout << mx << endl;
} 
