#include <bits/stdc++.h>

#define FI
#define FO

int main() {
#define int long long
    constexpr int inf = 0x3f3f3f3f3f3f3f3f;
#ifdef FI
    std::ifstream fin("subway.in");
#else
#define fin std::cin
#endif
#ifdef FO
    std::ofstream fout("subway.out");
#else
#define fout std::cout
#endif
    int c, n, m, d, q;
    fin >> c >> m >> n >> d >> q;
    struct Edge {
        int to, next, len;
    };
    std::vector<Edge> edge;
    std::vector<int> h;
    auto addEdge = [&](int x, int y, int len) {
        if (h.size() <= x) {
            h.resize(x + 1, -1);
        }
        //std::cout << x << " " << y << " " << len << "\n";
        edge.push_back({y, h.at(x), len});
        h.at(x) = static_cast<int>(edge.size()) - 1;
    };
    for (int i = 1; i <= n; ++i) {
        int w;
        fin >> w;
        addEdge(i, i + n, w);
        addEdge(i + n, i, w);
    }
    int tot = n * 2 + 1;
    for (int i = 1; i <= m; ++i) {
        int k;
        fin >> k;
        while (k--) {
            int u, t;
            fin >> u >> t;
            addEdge(u + n, tot, t);
            addEdge(tot, u + n, t);
        }
        ++tot;
    }
    auto dij = [&](int s) {
        std::vector<int> dis(tot + 1, -1);
        std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<>> que;
        que.emplace(0, s);
        dis.at(s) = 0;
        while (!que.empty()) {
            int d = que.top().first;
            int u = que.top().second;
            que.pop();
            if (d > dis.at(u)) {
                continue;
            }
            for (int i = h.at(u); i != -1; i = edge.at(i).next) {
                int to = edge.at(i).to;
                int len = edge.at(i).len;
                if (dis.at(to) == -1 || d + len < dis.at(to)) {
                    dis.at(to) = d + len;
                    que.emplace(d + len, to);
                }
            }
        }
        return dis;
    };
    auto bfs = [&](int s) {
        std::vector<int> dis(tot + 1, -1);
        std::deque<int> que;
        que.push_back(s);
        dis.at(s) = 0;
        while (!que.empty()) {
            int u = que.front();
            que.pop_front();
            for (int i = h.at(u); i != -1; i = edge.at(i).next) {
                int to = edge.at(i).to;
                if (dis.at(to) != -1) {
                    continue;
                }
                int len = edge.at(i).len;
                if (len == 0) {
                    que.push_front(to);
                } else {
                    que.push_back(to);
                }
                dis.at(to) = dis.at(u) + len;
            }
        }
        return dis;
    };
    // std::vector<std::vector<int>> ans(n + 1, std::vector<int>(n + 1));
    // for (int i = 1; i <= n; ++i) {
    //     std::vector<int> d;
    //     if (12 <= c && c <= 19) {
    //         std::cout << 114514 << "\n";
    //         d = bfs(i);
    //     } else {
    //         d = dij(i);
    //     }
    //     for (int j = 1; j <= n; ++j) {
    //         ans.at(i).at(j) = d.at(j);
    //     }
    // }
    while (q--) {
        int x, y;
        fin >> x >> y;
        if (12 <= c && c <= 19) {
            // std::cout << 1 << "\n";
            fout << bfs(x).at(y) << "\n";
        } else {
            fout << dij(x).at(y) << "\n";
        }
        // fout << ans.at(x).at(y) << "\n";
    }
    return 0;
}