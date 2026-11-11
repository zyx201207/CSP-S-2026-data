#include<bits/stdc++.h>
using namespace std;

#define int long long
#define vec basic_string
#define pir array<int, 2>
const int N = 5e2 + 5, M = 5e5 + 5, INF = 1e17;
int typ, n, m, d, T, w[M], f[N][N], kn, x, y;
pir stk[N];
int st;
vec<pir> to[M];

inline void MIN(int &a, int b) {a = (a < b ? a : b);}
signed main(){
    // system("fc subway7.ans subway.out /w"); return 0;
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> typ >> n >> m >> d >> T;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i){
        cin >> kn;
        while(kn--) cin >> x >> y, to[x] += {i, y};
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j) f[i][j] = INF;
        f[i][i] = 0;
    }
    for(int i = 1; i <= m; ++i){
        st = 0;
        for(auto j : to[i]) stk[++st] = j;
        for(int p = 1; p < st; ++p)
            for(int q = p + 1; q <= st; ++q){
                int val = stk[p][1] + stk[q][1];
                int _p = stk[p][0], _q = stk[q][0];
                MIN(f[_p][_q], val), MIN(f[_q][_p], val);
            }  
    }
    for(int k = 1; k <= n; ++k)
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                if(f[i][k] < INF && f[k][j] < INF)
                    MIN(f[i][j], f[i][k] + f[k][j]);
    while(T--){
        cin >> x >> y;
        int ans = INF;
        for(auto j : to[x])
            for(auto k : to[y]){
                int _j = j[0], _k = k[0];
                if(f[_j][_k] < INF) MIN(ans, f[_j][_k] + j[1] + k[1]);
            }
        cout << ans + w[x] + w[y] << '\n';
    }
    return 0;
}