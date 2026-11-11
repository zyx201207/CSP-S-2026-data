#include <bits/stdc++.h>
#define ll long long

using namespace std;

int c, n, m, d, q;
ll mp[666][666];
ll vis[666];

void dfs(int st, int en, int w) {
    // cout << "Dfs uncompletely starts.\n";
    if (vis[st] && w >= vis[st]) {
        return ;
    }
    vis[st] = w;
    if (st == en) {
        return ;
    }
    // cout << "Dfs really starts.\n";
    if (1 <= st && st <= m) {  // if st is a gate
        dfs(m + st, en, w+mp[st][m+st]);
    } else if (m+1 <= st && st <= 2*m) {  // if st is a waiting room
        if (st % m == en) {
            dfs(en, en, w+mp[st][en]);
        } else {
            for (int i = 1; i <= n; i++) {
                if (mp[st][(i+1)*m+st%m] != -1) dfs((i+1)*m + st%m, en, w+mp[st][(i+1)*m+st%m]);
            }
        }
    } else {  // if st can take subway
        for (int i = 2*m+1; i <= (n+2)*m; i++) {
            if (mp[st][i] != -1) {
                dfs(i, en, w+mp[st][i]);
            }
        }
        dfs(m+st%m, en, w+mp[st][m+st%m]);
    }
    return ;
}

int main() {
    freopen("subway2.in", "r", stdin);
    //freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    memset(mp, -1, sizeof mp);
    for (int i = 1; i <= m; i++) {
        ll w;
        cin >> w;
        mp[i][m+i] = mp[m+i][i] = w;
    }
    for (int i = 1; i <= n; i++) {
        int k, tem;
        cin >> k;
        for (int j = 1; j <= k; j++) {
            int a; ll t;
            cin >> a >> t;
            if (j != 1) {
                mp[(i+1)*m+a][(i+1)*m+tem] = mp[(i+1)*m+tem][(i+1)*m+a] = 0;
            }
            tem = a;
            mp[(i+1)*m+a][m+a] = mp[m+a][(i+1)*m+a] = t;
        }
    }
    while (q--) {
        memset(vis, 0, sizeof vis);
        int x, y;
        cin >> x >> y;
        dfs(x, y, 0);
        cout << vis[y] << "\n";
    }
    return 0;
}
