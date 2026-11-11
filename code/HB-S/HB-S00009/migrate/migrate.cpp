#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6 + 10, INF = 4e18, M = 5100;
int n, d, a[N], f[N], g[N], dis[M][M], deg[N];

signed main()
{
        freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    // freopen("1.txt", "r", stdin);
    // freopen("1.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int C, T;
    cin >> C >> T;
    while (T -- )
    {
        int ans = 0;
        cin >> n >> d;
        if (n == 1) {cout << 0 << '\n'; continue;}
        for (int i = 1; i <= n; i ++ ) cin >> a[i];
        if (C >= 11 && C <= 12)
        {
            int res = abs(a[2] - a[1]);
            int dis = d / res;
            if (dis >= 2 && n >= 2 * dis) ans += n - 2 * dis + 1;
            cout << ans << '\n';            
        }
        else 
        {
            for (int i = 1; i <= n; i ++ )
                for (int j = 1; j <= n; j ++ )
                    dis[i][j] = 0;
            for (int i = 1; i <= n; i ++ )
                for (int j = 1; j <= n; j ++ )
                    if (abs(a[i] - a[j]) <= d)
                        dis[i][j] = 1;
            for (int i = 1; i <= n; i ++ )
            {
                for (int j = i; j <= n; j ++ )
                    for (int k = j + 1; k <= n; k ++ )
                        if (dis[j][k])
                            deg[k] ++ ;
                for (int i = 1; i <= n; i ++ ) f[i] = INF, g[i] = 0;
                queue<int> q;
                q.push(i);
                f[i] = 0, g[i] = 1;
                while (q.size())
                {
                    int t = q.front();
                    q.pop();
                    for (int j = 1; j <= n; j ++ ) 
                    {
                        if (!dis[i][j]) continue;
                        if (f[j] > f[t] + 1) 
                        {
                            g[j] = g[t];
                            f[j] = f[t] + 1;
                        }
                        else if (f[j] == f[t] + 1) g[j] += g[t];
                        if ( -- deg[j] == 0)
                        {
                            if (g[j] == 2) ans ++ ;
                            q.push(j);
                        }
                    }
                }
            }
            cout << ans << '\n';
        }
        // else if (C >= 13 && C <= 14)
        // {
        //     int p = 0;
        //     for (int i = 1; i <= n; i ++ ) if (a[i] + d >= a[n] && a[i] - d <= a[1]) p = i;
        //     for (int i = p + 1; i <= n; i ++ ) 
        //     {
        //         int lst = lower_bound(a + 1, a + 1 + n, a[i] - d) - a;
        //         if (lst < p - (i == p + 1)) continue;

        //     }
        // }
        // if (C == 11 || C == 12)
        // {
            
      //  }   
        // int ans = 0;
        // cin >> n >> d;
        // for (int i = 1; i <= n; i ++ ) cin >> a[i];
        // for (int i = 1; i <= n; i ++ )
        //     for (int j = 1; j <= n; j ++ )
        //         dis[i][j] = INF;
        // for (int i = 1; i <= n; i ++ )
        //     for (int j = 1; j <= n; j ++ )
        //         if (abs(a[i] - a[j]) <= d)
        //             dis[i][j] = 1;
        // for (int k = 1; k <= n; k ++ )
        //     for (int i = 1; i <= n; i ++ )
        //         for (int j = 1; j <= n; j ++ )
        //             dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
        // for (int i = 1; i <= n; i ++ )
        //     for (int j = i + 1; j <= n; j ++ )
        //     {
        //         int cnt = 0;
        //         for (int k = 1; k <= n; k ++ ) if (dis[i][k] + dis[k][j] == dis[i][j]) cnt ++ ;
        //        // if (cnt == 2) cout << i << ' ' << j << endl;
        //         if (cnt == 2) ans ++ ;
        //     }        
        // cout << ans << '\n';
    }

    return 0;
}
