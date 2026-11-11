#include <bits/stdc++.h>
#define int long long
using namespace std;

int n, m, w[500010], t[510][50000], k[510], a[50000][510], ans = 1000010;
bool b[510][500010] = {false}, dis[510] = {false};

void dps(int now, int aim, int walk, int line)
{
    if (now == aim)
    {
        dis[now] = false;
        ans = min(ans, walk + t[line][aim]);
        return ;
    }
    if (dis[now])
    {
        return ;
    }
    dis[now] = true;
    for (int i = 1; i <= n; i++)
    {
        if (b[i][now] && line == i)
        {
            for (int j = 1; j <= k[i]; j++)
            {
                if (a[i][j] == now || dis[a[i][j]]) continue;
                //cout << now << " to " << a[i][j] << " " << walk << " " << i << endl;
                dps(a[i][j], aim, walk, line);
            }
        }
        if (b[i][now] && line != i)
        {
            for (int j = 1; j <= k[i]; j++)
            {
                if(a[i][j] == now) continue;
                //cout << now << " to " << a[i][j] << " " << t[line][now] << " " << t[i][now] << " " << i << endl;
                dps(a[i][j], aim, walk + t[line][now] + t[i][now], i);
            }
        }
    }
    dis[now] = false;
}


signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, d, q;
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++)
    {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++)
        {
            cin >> a[i][j];
            cin >> t[i][a[i][j]];
            b[i][a[i][j]] = true;
            //cout << a[i] << " " << t[i][a[i]] << endl;
        }
    }
    for (int i = 1; i <= q; i++)
    {
        int st, en;
        cin >> st >> en;
        memset(dis, false, sizeof(dis));
        ans = 21474836;
        for (int j = 1; j <= n; j++)
        {
            if (b[j][st])
            {
                //cout << j << " " << st << endl;
                dps(st, en, w[st] + w[en] + t[j][st], j);

            }
        }
        cout << ans << endl;
    }
    return 0;
}
