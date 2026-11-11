#include<bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, w[1000006], k, a[1000006], t[1000006];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(nullptr);
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1;i <= m;i++)
	{
		cin >> w[i];
	}
	for(int i = 1;i <= n;i++)
	{
		cin >> k;
		for(int j = 1;j <= k;j++)
		{
			cin >> a[i] >> t[i];
			
		}
	}
	while(q--)
	{
		int x, y, ans = 0;
		cin >> x >> y;
		ans += w[x] + w[y] + 2 * t[1];
		cout << ans << endl;
	}
	
	return 0;
}
