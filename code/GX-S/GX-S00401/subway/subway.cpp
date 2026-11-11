#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int N = 510 + 10, M = 5e5  + 10;

int c, n, m, d, q;
ll w[M];
ll cost[N][N];
int a[N][N];
vector<int> g[M];
int pos[N][M];
bool st[N];
ll ans = 1e18;
int tot[N];

void dfs(int nw, int u, int ed, ll cnt){
    if (u == ed){
        ans = min(ans, cnt + cost[nw][pos[nw][u]]);
        return;
    }
    if (g[u].size() == 1 && pos[nw][u] == tot[nw] && nw) return;
//    cout << nw << ' ' << u <<' ' << ed << ' ' << cnt << '\n';
    for (int j : g[u]){
        if (!nw) dfs(j, u, ed, cnt + cost[j][pos[j][u]]);
        else{
            if (pos[nw][u] + 1 <= tot[nw]) dfs(nw, a[nw][pos[nw][u] + 1], ed, cnt);
            if (!st[j]){
//                cout << t[nw][s[nw][u]]  << ' ' <<  t[j][s[j][u]] << '\n';
                st[j] = 1;
                dfs(j, u, ed, cnt  + cost[nw][pos[nw][u]] + cost[j][pos[j][u]]);
                st[j] = 0;
            }
        }
    }
}

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> c >> n >> m >> d >>q;
    for (int i = 1; i <= m; i ++ ) cin >> w[i];
    for (int i = 1; i <= n; i ++ ){
        int cnt;
        cin >>tot[i];
        for (int j = 1; j <= tot[i]; j ++ )
        {
            cin >> a[i][j] >> cost[i][j];
            g[a[i][j]].push_back(i);
            pos[i][a[i][j]] = j;
        }
    }
//    for (int i = 1; i <= 2; i ++ ) {
//        for (int j = 1; j <= 3; j ++ )
//            cout << t[i][j] << ' ';
//            cout << '\n';
//        }
//    cout << s[1][4] << ' ' << tot[1] << ' ' << g[4].size() << '\n';
    while (q -- ){
        int s, t;
        cin >> s >> t;
        ans = 1e18;
        for (int j = 1; j <= n; j ++ )
            st[j] = 0;
        dfs(0, s, t, 0);
        if (ans == 1e18) cout << w[s] + w[t] + cost[*g[s].begin()][pos[*g[s].begin()][s]] + cost[*g[t].begin()][pos[*g[t].begin()][t]] << '\n';
        else   cout << ans + w[s] + w[t] << '\n';
    }
    return 0;
}
