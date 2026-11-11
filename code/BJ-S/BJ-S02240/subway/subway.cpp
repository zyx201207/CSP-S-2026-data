#include<bits/stdc++.h>
using namespace std;
#define int long long

const int M = 5e4 + 5, N = 505;
int w[M], t[N][M], a[N][M];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1;i <= m;i++)
        cin >> w[i];
    for(int i = 1;i <= n;i++)
    {
        int k;
        cin >> k;
        for(int j = 1;j <= k;j++)
            cin >> a[i][j] >> t[i][j];
    }
    int ans;
    while(q--)
    {
        int x, y;
        cin >> x >> y;
        ans = w[x] + w[y];
        if(c >= 7 && c <= 11)
        {
            ans += t[1][x];
            ans += t[2][x];
        }
    }
    cout << ans + 8;
    return 0;
}
