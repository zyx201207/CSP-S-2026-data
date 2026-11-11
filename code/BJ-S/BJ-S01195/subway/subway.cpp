#include <bits/stdc++.h>
using namespace std;
int c, n, m, d, q, w[50005], a[505][50005], t[505][50005], e[505][50005];
//e[i][j]: subway-line i on station j's time
long long diss[50005];
struct node{
    int v, w;
};
vector<node> mp[50005];
long long ans;
void dfs(int u, int zz){
    if (u == zz){
        ans = min(ans, diss[zz]);
        return;
    }
    for (auto x : mp[u]){
        int v = x.v, w = x.w;
        if (diss[v] <= diss[u] + w) continue;
        diss[v] = diss[u] + w;
        dfs(v, zz);
    }
    return;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++){
        cin >> w[i];
    }
    memset(e, -1, sizeof e);
    for (int i = 1; i <= n; i++){
        int k;
        cin >> k;
        for (int j = 1; j <= k; j++){
            cin >> a[i][j] >> t[i][j];
            e[i][a[i][j]] = t[i][j];
            for (int kk = 1; kk < j; kk++){
                mp[a[i][j]].push_back({a[i][kk], t[i][j] + t[i][kk]});
                mp[a[i][kk]].push_back({a[i][j], t[i][j] + t[i][kk]});
            }
        }
    }
    while(q--){
        ans = 4e18;
        memset(diss, 0x3f, sizeof diss);
        int x, y;
        cin >> x >> y;
        diss[x] = 0;
        dfs(x, y);
        cout << ans + w[x] + w[y] << "\n";
    }
    return 0;
}
