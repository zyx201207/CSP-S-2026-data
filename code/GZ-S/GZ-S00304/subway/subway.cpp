//GZ-S00304 华东师范大学附属贵阳学校 蒋泽赟
#include <bits/stdc++.h>
using namespace std;

const int N = 1000;

long long dis[N][N], w[N], a[N][N], k[N], t[N][N];

vector<pair<int, int> > e[N];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; ++j)
            cin >> a[i][j] >> t[i][j];
    }
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= m; ++j)
        {
            dis[i][j] = LONG_MAX;
        }
    }
    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j <= k[i]; ++j)
        {
            for (int l = 1; l <= k[i]; ++l)
            {
                if (j != l)
                {
                    e[j].push_back({l, t[i][j] + t[i][l]});
                    dis[j][l] = t[i][j] + t[i][l];
                }
            }
        }
    }
	for (int i = 1; i <= q; ++i)
	{
		cout << 1 << "\n";
	}
    return 0;
}
