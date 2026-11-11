#include <bits/stdc++.h>
using namespace std;

int T, n, m, dis[4001][4001];
vector<int> e[1000001];
bool b[4001];

int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    scanf("%*d%d", &T);
    while (T--) {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++)
            e[i].clear();
        for (int i = 1; i < n; i++) {
            int u, v;
            scanf("%d%d", &u, &v);
            e[u].push_back(v);
            e[v].push_back(u);
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                dis[i][j] = -1;
            dis[i][i] = 0;
            queue<int> q;
            q.push(i);
            while (!q.empty()) {
                int x = q.front();
                q.pop();
                for (auto y : e[x]) {
                    if (dis[i][y] == -1) {
                        dis[i][y] = dis[i][x] + 1;
                        q.push(y);
                    }
                }
            }
        }
        int ans = 1e9;
        for (int i = 1; i < (1 << n); i++) {
            if (__builtin_popcount(i) != m)
                continue;
            int mx = 0;
            for (int j = 1; j <= n; j++) {
                int mi = 1e9;
                for (int k = 1; k <= n; k++)
                    if ((i >> (k - 1)) & 1)
                        mi = min(mi, dis[j][k]);
                mx = max(mx, mi);
            }
            for (int j = 1; j <= n; j++)
                b[j] = false;
            int t = 0;
            for (int j = 1; j <= n; j++) {
                if (b[j] || !(((i >> (j - 1))) & 1))
                    continue;
                t++;
                if (t > 2)
                    break;
                queue<int> q;
                q.push(j);
                while (!q.empty()) {
                    int x = q.front();
                    q.pop();
                    for (auto y : e[x]) {
                        if (b[y] || !(((i >> (y - 1))) & 1))
                            continue;
                        b[y] = true;
                        q.push(y);
                    }
                }
            }
            if (t <= 2)
                ans = min(ans, mx);
        }
        printf("%d\n", ans);
    }
}