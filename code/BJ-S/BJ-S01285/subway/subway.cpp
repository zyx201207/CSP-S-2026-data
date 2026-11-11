#include <bits/stdc++.h>
using namespace std;

int read(){
    int f = 1, x = 0;
    char c = getchar();
    while(c < '0' || '9' < c){
        if(c == '-') f = -1;
        c = getchar();
    }
    while('0' <= c && c <= '9'){
        x = (x << 3) + (x << 1) + (c - '0');
        c = getchar();
    }
    return f * x;
}

const int N = 1005;
const long long INF = 1e18;
int c, n, m, d, Q;
int w[N];
vector <pair <int, int>> l[N];
long long f[N][N];

int main(){
    //把每一条线路看成点，通过Floyd求出每两条线路转换所需的最小时间
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c = read(), n = read(), m = read(), d = read(), Q = read();
    for(int i = 1; i <= m; i++){
        w[i] = read();
    }
    for(int i = 1; i <= n; i++){
        int num = read();
        for(int j = 1; j <= num; j++){
            int u = read(), t = read();
            l[u].push_back({i, t});
        }
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if(i != j) f[i][j] = INF;
    for(int i = 1; i <= m; i++){
        int to_g = l[i].size();
        for(int j = 0; j < to_g; j++){
            for(int k = j + 1; k < to_g; k++){
                int u = l[i][j].first, v = l[i][k].first;
                int ut = l[i][j].second, vt = l[i][k].second;
                f[u][v] = min(f[u][v], 1ll * ut + vt);
                f[v][u] = f[u][v];
            }
        }
    }
#ifdef Ken
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << "f[" << i << "][" << j << "] = " << f[i][j] << '\n';
        }
    }
#endif
    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
            }
        }
    }
#ifdef Ken
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << "f[" << i << "][" << j << "] = " << f[i][j] << '\n';
        }
    }
#endif
    while(Q--){
        int u = read(), v = read();
        long long ans = INF;
        for(int i = 0; i < l[u].size(); i++){
            for(int j = 0; j < l[v].size(); j++){
                ans = min(ans, f[l[u][i].first][l[v][j].first] + l[u][i].second + l[v][j].second);
                // cout << l[u][i].first << " -> " << l[v][j].first << ' ' << l[u][i].second << ' ' << l[v][j].second << '\n';
            }
        }
        // cout << ans << '\n';
        ans += w[u] + w[v];
        cout << ans << '\n';
    }
    return 0;
}