#include <bits/stdc++.h>
using namespace std;
#define int long long

const int NR = 5e2 + 5, MR = 5e5 + 5, inf = 0x3f3f3f3f3f3f3f3f;
int c, n, m, d, q;
int w[MR];
//vector<int> a[NR], t[NR]; //
vector<pair<int, int> > g[MR];

int f[NR][NR];

signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i ++){
        cin >> w[i];
    }
    for(int i = 1, x, y, k; i <= n; i ++){
        cin >> k;
        for(int j = 1; j <= k; j ++){
            cin >> x >> y;
            g[x].push_back(make_pair(i, y));
            //a[i].push_back(x);
            //t[i].push_back(y);
        }
    }
    memset(f, 0x3f, sizeof(f));
    for(int x = 1; x <= m; x ++){
        for(auto now1 : g[x]){
            for(auto now2 : g[x]){
                int i = now1.first, j = now2.first;
                int w0 = now1.second + now2.second;
                if(i == j) {
                    f[i][j] = f[j][i] = 0;
                    continue;
                }
                f[i][j] = min(f[i][j], w0);
                f[j][i] = min(f[j][i], w0);
            }
        }
    }
    for(int k = 1; k <= n; k ++){
        for(int i = 1; i <= n; i ++){
            for(int j = 1; j <= n; j ++){
                if(f[i][k] >= inf || f[k][j] >= inf) continue;
                f[i][j] = min(f[i][k]+f[k][j], f[i][j]);
            }
        }
    }

    int u, v;
    while(q --){
        cin >> u >> v;
        int ans = 9e18;
        for(auto now1 : g[u]){
            for(auto now2 : g[v]){
                int i = now1.first, j = now2.first;
                int w0 = now1.second + now2.second;
                ans = min(ans, f[i][j] + w0);
            }
        }
        //cout << ans << '\n';
        cout << ans + w[u] + w[v] << '\n';
    }
    /**
    for(int i = 1; i <= n; i ++){
        for(int j = 1; j <= n; j ++){
            cout << f[i][j] << ' ';
        }
        cout << endl;
    }
    **/
    return 0;
}
/**

0 2 5 20 2
4 1 9 2 5
3 1 5 2 7 4 6
3 2 3 3 4 5 7
1 3
1 2

**/
