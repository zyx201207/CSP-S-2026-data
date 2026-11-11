#include <iostream>
#include <cstring>
using namespace std;
int w[400003];
int g[1003][1003];
bool p[1003][1003];
int c, n, m, d, q, k, u, t, x, y;
long long cnt = 999999999;
void dfs(int line, int step, long long mon){
    if(step == y){
        cnt = min(cnt, mon);
        return ;
    }
    if(line != 0) p[line][step] = 1;
    for(int i = 1; i <= n; i++){
        if(g[i][step] && !p[i][step]){
            p[i][step] = 1;
            for(int j = 1; j <= m; j++){
                if(g[i][j] && !p[i][j]){
                    dfs(i, j, mon+g[i][step]+g[i][j]);
                }
            }
            p[i][step] = 0;
        }
    }
    return ;
}
int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++){
        cin >> w[i];
    }
    for(int i = 1; i <= n; i++){
        cin >> k;
        for(int j = 1; j <= k; j++){
            cin >> u >> t;
            g[i][u] = t;
        }
    }
    while(q--){
        memset(p, 0, sizeof(p));
        cnt = 99999999;
        cin >> x >> y;
        long long ans = (w[x]+w[y]);
        dfs(0, x, 0);
        cout << ans+cnt << endl;
    }
    return 0;
}

