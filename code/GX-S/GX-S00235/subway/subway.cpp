#include<bits/stdc++.h>
using namespace std;
constexpr int N = 5e5+ 10;
long long  c, n, m, d, q, w[N];
int vis[N], mn = INT_MAX, cnt = 0;
int g[N][30];
void dfs(int x, int y){
    cout << x <<" " ;
    if(x == y && mn >= cnt){
        cnt += w[y];
        mn = cnt;
        return ;
    }
    if(cnt > mn) return ;
    for(int i = 1; i <= 20; i++){
        if(g[x][i] != 0 && i != x){
            cnt += g[x][i] + g[x][x];
            vis[i] = 1;
            dfs(i, y);
            vis[i] = 0;
            cnt -= g[x][i] + g[x][x];
        }
    }

}
int main(){
      freopen("subway.in", "r", stdin);
      freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(g, 0, sizeof(0));
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++){
        int k, aa, t;
        cin >> k;
        for(int i = 1; i <= k; i++){
            cin >> aa >> t;
            g[i][aa] = t;
        }
    }
    while(q--){
        int x, y;
        cin >> x >> y;
        mn = INT_MAX, cnt = w[x];
        dfs(x,y);
        cout << mn << "\n";
    }
    return 0;
}
