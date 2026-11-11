#include <bits/stdc++.h>
using namespace std;
const int N = 500005;
long long c, n, m, d, q, x, y, ans;
long long w[N], k[N], a[500005][500005], t[500005][500005], f[500005];
int main()
{
	freopen("subway.in", "r", stdin);
	freopen("subway.out", "w", stdout);
	cin >> c >> n >> m >> d >> q;
	for(int i = 1; i <= m; i ++) cin >> w[i];
	for(int i = 1; i <= n; i ++)
	{
		cin >> k[i];
		for(int j = 1; j <= k[i]; j ++) cin >> a[i][j] >> t[i][j];
	}
	while(q --)
	{
		cin >> x >> y;
		ans += w[x] + w[y];
		cout << ans + a[1][1] + a[1][2];
		cout << ans << endl;
	}
	return 0;
}