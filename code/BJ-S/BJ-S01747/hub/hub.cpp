

#include <iostream>
#include <vector>

using namespace std;

int c, t;
const int MAXI = 1009;
int n, k;
vector<int> G[MAXI];

int dis[MAXI][MAXI];

void DfsDis (int rt, int u, int fa) {
    if (rt == u) dis[rt][u] = 0;
    else dis[rt][u] = dis[rt][fa] + 1;

    for (int v : G[u])
        if (v != fa) DfsDis(rt, v, u);
}

bool flag[MAXI];
bool vis[MAXI];

void DfsFlag (int u, int fa) {
    vis[u] = 1;
    for (int v : G[u])
        if (v != fa && flag[v]) DfsFlag(v, u);
}

void Init () {
    for (int i = 1; i <= n; i++) G[i].clear();
}

int main () {

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> c >> t;
    while (t--) {
        cin >> n >> k;
        for (int i = 1; i <= n - 1; i++) {
            int x, y;
            cin >> x >> y;
            G[x].push_back(y);
            G[y].push_back(x);
        }

        for (int i = 1; i <= n; i++) DfsDis(i, i, 0);

        int ans = 1e9;
        for (int s = 0; s < (1 << n); s++) {
            int cntFlag = 0;
            for (int i = 1; i <= n; i++)
                if (s & (1 << (i - 1))) flag[i] = 1, cntFlag++;
                else flag[i] = 0;
            if (cntFlag != k) continue;

            for (int i = 1; i <= n; i++) vis[i] = 0;
            int block = 0;
            for (int i = 1; i <= n; i++)
                if (flag[i] && !vis[i]) DfsFlag(i, 0), block++;
            if (block > 2) continue;

            int maxi = 0;
            for (int i = 1; i <= n; i++) {
                int mini = 1e9;
                for (int j = 1; j <= n; j++) {
                    if (!flag[j]) continue;
                    mini = min(mini, dis[i][j]);
                }
                maxi = max(maxi, mini);
            }
            ans = min(ans, maxi);
        }
        cout << ans << '\n';

        Init();
    }

    return 0;
}
