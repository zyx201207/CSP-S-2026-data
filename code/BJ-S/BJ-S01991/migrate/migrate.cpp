#include <bits/stdc++.h>
#define int long long
using namespace std;

int c, t, n, d, minn = 1e9, cnt;
int a[305], f[305], g[305][305];

void dfs1(int x, int r, int cost){
    if(cost > minn) return ;
    if(x == r){
        minn = min(minn, cost);
        return ;
    }
    for(int i = x + 1; i <= n; i++){
        if(a[i] - a[x] <= d) dfs1(i, r, cost + 1);
    }
}
int dfs2(int x, int r, int cost){
    if(cost > minn) return 0;
    if(f[x]) return f[x];
    if(x == r && cost == minn){
        return 1;
    }
    int cnt = 0;
    for(int i = x + 1; i <= n; i++){
        if(a[i] - a[x] <= d) cnt += dfs2(i, r, cost + 1);
    }
    return f[x] = cnt;
}

signed main(){
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> c >> t;
    while(t--){
        cin >> n >> d;
        for(int i = 1; i <= n; i++){
            cin >> a[i];
        }
        if(n <= 305){
            memset(g, 0x3f, sizeof(g));
            for(int i = 1; i < n; i++){
                g[i][i] = 0;
                for(int j = i + 1; j <= n; j++){
                    if(a[j] - a[i] <= d){
                        g[i][j] = 1;
                    }
                }
            }
            for(int k = 1; k <= n; k++){
                for(int l = 1; l < n; l++){
                    for(int r = l + 1; r <= n; r++){
                        g[l][r] = min(g[l][r], g[l][k] + g[k][r]);
                    }
                }
            }
            int res = 0;
            for(int l = 1; l < n; l++){
                for(int r = l + 1; r <= n; r++){
                    minn = g[l][r];
                    cnt = 0;
                    memset(f, 0, sizeof(f));
                    dfs2(l, r, 0);
                    if(f[l] == 2) res++;
                }
            }
            cout << res << '\n';
        }
        else{
            cout << 2 << '\n';
        }
    }
    return 0;
}
