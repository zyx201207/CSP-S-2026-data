#include<bits/stdc++.h>
using namespace std;

int c, n, m, d, q, ans, vis[500005], dist[500005];
int w[500005], k[500005], l[505];

struct edge{
    int u, v, w;
};

vector<pair<int, int>> t[500005];
vector<int> line[505];

void bfs(int s) {
    queue<vector<pair<int, int>>> q;
    queue<int> v;
    q.push(t[s]);
    v.push(s);
    vis[s] = w[s] + t[s][0].second;
    while (!q.empty()) {
        auto u = q.front();
        for (int i = 0; i < u.size(); i++) {
            if (!l[u[i].first])
                for (auto it : line[u[i].first]) {
                    if (!dist[it]) {
                        vis[it] = min(vis[it], vis[v.front()] + u[it].second), dist[it] = 1;
//                        printf("%d %d\n", it, vis[it]);
                        if (t[it].size() >= 2) {
                            q.push(t[it]), v.push(it);
                        }
                    }
                }
            l[u[i].first] = 1;
        }
        q.pop();
        v.pop();
    }
}

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    scanf("%d%d%d%d%d", &c, &n, &m, &d, &q);
    for (int i = 1; i <= m; i++)
        scanf("%d", &w[i]);
    for (int i = 1, x; i <= n; i++) {
        scanf("%d", &x);
        for (int j = 1; j <= x; j++) {
            int a, b;
            scanf("%d%d", &a, &b);
            t[a].push_back({i, b});
            line[i].push_back(a);
        }
    }
    while(q--) {
        memset(vis, 0x3f, sizeof(vis));
        memset(dist, 0, sizeof(dist));
        memset(l, 0, sizeof(l));
        int s, e;
        scanf("%d%d", &s, &e);
//        printf("%d\n", t[s][0].first);
        bfs(s);
        printf("%d\n", vis[e] + w[e]);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
