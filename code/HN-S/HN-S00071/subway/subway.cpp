#include<bits/stdc++.h>
#define int long long
#define endl '\n'
using namespace std;
const int N = 5e5 + 5;
int c, n, m, d, q, x, xh, w, y, yh;
int a[N], t[N], tt[N], tong[N];
signed main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> c >> n >> m >> d >> q;
	for (int i = 1; i <= m; i++)
	{
		cin >> a[i];
	}
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		for (int j = 1; j <= x; j++)
		{
			cin >> xh >> w;
			tong[xh]++;
			tt[xh] = w; 
			t[xh] += w;
		}
	}
	for (int i = 1; i <= q; i++)
	{
		cin >> x >> y;
		int ans = a[x] + a[y];
		for (int j = x; j <= y; j++)
		{
			ans += t[j];
		}
		if (tong[y] >= 2)ans -= tt[y]; 
		cout << ans <<endl;
	}
	return 0;
} 
