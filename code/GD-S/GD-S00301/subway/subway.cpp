#include<bits/stdc++.h>
#define mem(a, v) memset(a, v, sizeof(a))

using namespace std;

const int maxn = 500 + 10, maxm = 5e5 + 10;

int n, m, q;
int a[maxm];
long long dis[maxn][maxn];
vector<pair<int, int> > ad[maxm], pnt[maxn];

inline int read(){
    int x = 0, f = 1;
    char ch = getchar();
    for (;ch < '0' || ch > '9'; ch == '-' && (f = -1), ch = getchar());
    for (;ch >= '0' && ch <= '9'; x = x * 10 + (ch ^ 48), ch = getchar());
    return x * f;
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(), n = read(), m = read(), read(), q = read(), mem(dis, 0x3f);
    for (int i = 1; i <= m; i++){
        a[i] = read();
    }
    for (int i = 1; i <= n; i++){
        int k = read();
        dis[i][i] = 0;
        for (int x, y; k--; x = read(), y = read(), ad[x].push_back(make_pair(i, y)), pnt[i].push_back(make_pair(x, y)));
    }
    for (int i = 1; i <= n; i++){
        for (auto x: pnt[i]){
            for (auto y: ad[x.first]){
                dis[i][y.first] = min(dis[i][y.first], (long long)x.second + y.second);
            }
        }
    }
    for (int k = 1; k <= n; k++){
        for (int i = 1; i <= n; i++){
            for (int j = 1; j <= n; j++){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    while (q--){
        int x, y;
        long long res = 1e18;
        x = read(), y = read();
        for (auto p: ad[x]){
            for (auto q: ad[y]){
                res = min(res, p.second + q.second + dis[p.first][q.first]);
            }
        }
        printf("%lld\n", res + a[x] + a[y]);
    }

return 0;
}