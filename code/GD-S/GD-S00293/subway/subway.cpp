#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn = 500005;
const int sq = 23;
const int inf = 1e18;
struct S{
    int x, t;
}b[maxn][sq];
int a[maxn], st[maxn], d[505][505];
signed main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    int c, n, m, dd, q;
    cin >> c >> n >> m >> dd >> q;
    for(int i = 1;i <= m;i++) cin >> a[i];
    for(int i = 1;i <= n;i++){
        int len, x, t;
        cin >> len;
        for(int j = 1;j <= len;j++){
            cin >> x >> t;
            b[x][++st[x]].x = i;
            b[x][st[x]].t = t;
        }
    }
    for(int i = 1;i <= n;i++){
        for(int j = 1;j <= n;j++) d[i][j] = inf;
        d[i][i] = 0;
    }
    for(int i = 1;i <= m;i++){
        for(int j = 1;j < st[i];j++){
            int x = b[i][j].x, w = b[i][j].t;
            for(int k = j + 1;k <= st[i];k++){
                int y = b[i][k].x, ww = b[i][k].t;
                d[x][y] = min(d[x][y], w + ww);
                d[y][x] = min(d[y][x], w + ww);
            }
        }
    } 
    for(int k = 1;k <= n;k++){
        for(int i = 1;i <= n;i++){
            for(int j = 1;j <= n;j++) d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
        }
    }
    for(int i = 1;i <= q;i++){
        int x, y, ans = inf;
        cin >> x >> y;
        for(int j = 1;j <= st[x];j++){
            int xx = b[x][j].x, w = b[x][j].t;
            for(int k = 1;k <= st[y];k++){
                int yy = b[y][k].x, ww = b[y][k].t;
                ans = min(ans, d[xx][yy] + w + ww);
                // cout << xx << ' ' << yy << ' ' << w << ' ' << ww << ' ' << d[xx][yy] << "----" << endl;
            }
        }
        // cout << x << ' ' << y << ' ' << a[x] + a[y] << ' ' << ans << endl;
        cout << ans + a[x] + a[y] << "\n";
    }
    return 0;
}