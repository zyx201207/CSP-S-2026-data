#include <bits/stdc++.h>

typedef long long ll;

const int N = 1e6 + 10;

std::vector<int> g[N];
int n, k, f[N], sz[N];
bool vis[N];

void init() {
    for (int i = 1; i <= n; i++) {
        f[i] = i;
        sz[i] = 1;
    }
}

int getf(int x) {
    if (f[x] != x) {
        f[x] = getf(f[x]);
    }

    return f[x];
}

void change(int a, int b) {
    a = getf(a);
    b = getf(b);

    if (a != b) {
        if (sz[a] > sz[b]) {
            std::swap(a, b);
        }

        f[a] = b;
        sz[b] += sz[a];
    }
}

void solve() {
    std::cin >> n >> k;

    for (int i = 1; i <= n; i++) {
        g[i].clear();
    }

    for (int i = 1; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        g[a].emplace_back(b);
        g[b].emplace_back(a);
    }

    std::queue<std::pair<int, int>> q;
    int ans = INT_MAX;

    for (int mask = 0; mask < (1 << n); mask++) {
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                ++cnt;
            }
        }

        if (cnt != k) {
            continue;
        }

        init();

        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                for (int j : g[i + 1]) {
                    if ((mask >> (j - 1)) & 1) {
                        change(i + 1, j);
                    }
                }
            }
        }

        cnt = 0;

        for (int i = 1; i <= n; i++) {
            if (((mask >> (i - 1)) & 1) && getf(i) == i) {
                ++cnt;
            }
        }

        if (cnt > 2) {
            continue;
        }

        for (int i = 0; i < n; i++) {
            if ((mask >> i) & 1) {
                q.emplace(i + 1, 0);
                vis[i + 1] = 1;
            }
            else {
                vis[i + 1] = 0;
            }
        }

        int cur = 0;

        while (q.size()) {
            int x = q.front().first, dis = q.front().second;
            q.pop();
            cur = std::max(cur, dis);

            for (int to : g[x]) {
                if (!vis[to]) {
                    q.emplace(to, dis + 1);
                    vis[to] = 1;
                }
            }
        }
        
        ans = std::min(ans, cur);
    }

    std::cout << ans << '\n';
}

FILE *IG;

int main() {
    IG = freopen("hub.in", "r", stdin);
    IG = freopen("hub.out", "w", stdout);
    
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int c, t;
    std::cin >> c >> t;

    while (t--) {
        solve();
    }

    return 0;
}