#include <bits/stdc++.h>
using namespace std;
const int MAXN = 105, INF = 1e8;
vector<int> G[MAXN];
int f[MAXN][3][2][MAXN][MAXN], g[3][2][MAXN][MAXN], len[MAXN], d;
int pre1[MAXN][MAXN];
void checkMin(int &x, int y){
    x = min(x, y);
}
int n, k;
void dfs(int u, int fa){
    len[u] = 1;
    for (auto v: G[u]){
        if (v == fa) continue;
        dfs(v, u);
    }
    for (int i = 1; i <= n; i++) f[u][1][1][1][i] = 1, f[u][0][0][0][i] = 0;
    for (auto v: G[u]){
        if (v == fa) continue;
        memset(g, 0x3f, sizeof(g));
        for (int cu = 0; cu < 3; cu++){
            for (int tu = 0; tu < 2; tu++){
                for (int cv = 0; cv < 3; cv++){
                    for (int tv = 0; tv < 2; tv++){
                        int nc = cu + cv - (tu && tv);
                        int nt = tu;
                        if (nc < 0 || nc > 2) continue;
                        for (int dis1 = 0; dis1 <= len[u]; dis1++){
                            for (int disv = 0; disv <= len[v]; disv++){
                                for (int dis2 = 0; dis2 <= n; dis2++){
                                    int ndis;
                                    if (disv == 0) ndis = dis1;
                                    else if (dis1 == 0) ndis = disv + 1;
                                    else ndis = min(dis1, disv + 1);
                                    checkMin(g[nc][nt][ndis][dis2], f[u][cu][tu][dis1][dis2] + f[v][cv][tv][disv][max(0, dis2 - 1)]);
                                }
                            }
                        }
                    }
                }
            }
        }
        memcpy(f[u], g, sizeof(g));
        len[u] = max(len[u], len[v] + 1);
    }
    for (int cu = 0; cu < 3; cu++){
        for (int tu = 0; tu < 2; tu++){
            for (int dis1 = 1; dis1 <= len[u]; dis1++){
                for (int dis2 = 1; dis2 <= n; dis2++){
                    if (dis1 - 1 + dis2 - 1 <= d) checkMin(f[u][cu][tu][dis1][0], f[u][cu][tu][dis1][dis2]);
                }
            }
        }
    }
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    int c, T;
    cin >> c >> T;
    while (T--){
        cin >> n >> k;
        if (c <= 6) for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i < n; i++){
            int u, v;
            cin >> u >> v;
            if (c <= 6){
                G[u].push_back(v);
                G[v].push_back(u);
            }
        }
        if (k == n){
            cout << 0 << '\n';
            continue;
        }
        if (c == 13 || c == 14){
            int m = (n - 1) / 2;
            if (k == 1){
                cout << m / 2 + 1 << '\n';
                continue;
            }
            if (k >= m){
                cout << 1 << '\n';
                continue;
            }
            m -= k;
            cout << (m + 3) / 4 + 1 << '\n';
            continue;
        }
        int L = 1, R = n / 2;
        while (L < R){
            int mid = (L + R) >> 1;
            d = mid;
            memset(f, 0x3f, sizeof(f));
            dfs(1, 0);
            int res = INF;
            for (int cu = 0; cu < 3; cu++){
                for (int tu = 0; tu < 2; tu++){
                    for (int i = 1; i <= n; i++){
                        res = min(res, f[1][cu][tu][i][0]);
                    }
                }
            }
            if (res <= k) R = mid;
            else L = mid + 1;
        }
        cout << L << '\n';
    }
    return 0;
}