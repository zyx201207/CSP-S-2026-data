// 15 pts

#include <bits/stdc++.h>

using namespace std;
using i64 = long long;

constexpr int INF = 0x3f3f3f3f;

struct DSU {
    vector<int> fa, siz;

    DSU(int n) 
        : fa(n)
        , siz(n, 1)
    {
        iota(fa.begin(), fa.end(), 0);
    }

    int leader(int u) { return fa[u] == u ? u : fa[u] = leader(fa[u]); }

    void merge(int u, int v)
    {
        u = leader(u);
        v = leader(v);
        if (u == v)
            return;
        if (siz[u] < siz[v])
            swap(u, v);

        siz[u] += siz[v];
        fa[v] = u;
    }
};

struct Solution {
    int n;
    vector<vector<int>> tree;

    int radius(int mask)
    {
        queue<int> nodes;
        vector<int> dist(n + 1, INF);
        for (int i = 0; i < n; ++i) {
            if (~mask & (1 << i))
                continue;
            nodes.push(i + 1);
            dist[i + 1] = 0;
        }

        while (!nodes.empty()) {
            int u = nodes.front();
            nodes.pop();

            for (int v : tree[u]) {
                if (dist[v] > dist[u] + 1) {
                    dist[v] = dist[u] + 1;
                    nodes.push(v);
                }
            }
        }

        return *max_element(dist.begin() + 1, dist.end());
    }

    void main()
    {
        int k;
        cin >> n >> k;

        tree.resize(n + 1);
        for (int i = 1; i < n; ++i) {
            int u, v;
            cin >> u >> v;
            tree[u].push_back(v);
            tree[v].push_back(u);
        }

        int ans = INF;
        for (int i = 0; i < 1 << n; ++i) {
            if (__builtin_popcount(i) != k)
                continue;

            DSU uf(n + 1);
            for (int u = 0; u < n; ++u) {
                if (~i & (1 << u))
                    continue;
                for (int v : tree[u + 1]) {
                    if (i & (1 << (v - 1)))
                        uf.merge(u + 1, v);
                }
            }

            unordered_set<int> roots;
            for (int u = 0; u < n; ++u) {
                if (i & (1 << u))
                    roots.insert(uf.leader(u + 1));
            }

            if (roots.size() <= 2)
                ans = min(ans, radius(i));
        }

        cout << ans << '\n';
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);

    int c, t;
    cin >> c >> t;

    while (t-- > 0)
        Solution().main();
    
    cout << flush;
    return 0;
}