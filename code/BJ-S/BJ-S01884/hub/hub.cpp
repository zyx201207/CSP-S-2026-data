#include <bits/stdc++.h>

#define FI
#define FO

int main() {
#define int long long
    constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#ifdef FI
    std::ifstream fin("hub.in");
#else
#define fin std::cin
#endif
#ifdef FO
    std::ofstream fout("hub.out");
#else
#define fout std::cout
#endif
    int c, t;
    fin >> c >> t;
    while (t--) {
        int n, k;
        fin >> n >> k;
        struct Edge {
            int to, next;
        };
        std::vector<Edge> edge;
        std::vector<int> h(n + 1, -1);
        auto addEdge = [&](int x, int y) {
            edge.push_back({y, h.at(x)});
            h.at(x) = static_cast<int>(edge.size()) - 1;
        };
        for (int i = 1; i < n; ++i) {
            int u, v;
            fin >> u >> v;
            addEdge(u, v);
            addEdge(v, u);
        }
        int ans = inf;
        for (int S = 0; S < (1 << n); ++S) {
            if (__builtin_popcount(S) != k) {
                continue;
            }
            std::vector<int> fa(n + 1);
            for (int i = 1; i <= n; ++i) {
                fa.at(i) = i;
            }
            std::function<int(int)> find = [&](int x) {
                int res = fa.at(x);
                if (x != res) {
                    res = find(res);
                    fa.at(x) = res;
                }
                return res;
            };
            std::function<void(int, int)> dfs = [&](int u, int f) {
                for (int i = h.at(u); i != -1; i = edge.at(i).next) {
                    int to = edge.at(i).to;
                    if (to == f) {
                        continue;
                    }
                    if ((S & (1 << (u - 1))) && (S & (1 << (to - 1)))) {
                        fa.at(find(u)) = find(to);
                    }
                }
            };
            dfs(1, 1);
            int cnt = 0;
            std::vector<int> vis(n + 1);
            std::queue<int> que;
            std::vector<int> dis(n + 1, -1);
            for (int i = 1; i <= n; ++i) {
                if (S & (1 << (i - 1))) {
                    ++vis.at(find(i));
                    que.push(i);
                    dis.at(i) = 0;
                }
            }
            for (int i = 1; i <= n; ++i) {
                if (vis.at(i) > 0) {
                    ++cnt;
                }
            }
            if (cnt > 2) {
                continue;
            }
            while (!que.empty()) {
                int u = que.front();
                que.pop();
                for (int i = h.at(u); i != -1; i = edge.at(i).next) {
                    int to = edge.at(i).to;
                    if (dis.at(to) != -1) {
                        continue;
                    }
                    dis.at(to) = dis.at(u) + 1;
                    que.push(to);
                }
            }
            int now = 0;
            for (int i = 1; i <= n; ++i) {
                now = std::max(now, dis.at(i));
            }
            ans = std::min(ans, now);
        }
        fout << ans << "\n";
    }
    return 0;
}
