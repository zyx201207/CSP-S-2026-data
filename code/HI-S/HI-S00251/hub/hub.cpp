#include <iostream>
#include <cstdio>
#include <array>
#include <vector>

constexpr int MAXN = 1e4 + 10;

int n, K;
std::array<std::vector<int>, MAXN> graph;

void input() {
    std::cin >> n >> K;
    for (int i{1}; i <= n; i++) {
        int u, v;
        std::cin >> u >>  v;
        graph[u].emplace_back(v);
        graph[v].emplace_back(u);
    }
}

std::vector<int> chs;
std::array<bool, MAXN> chsck;
int ans;

std::array<bool, MAXN> vis;
std::array<std::array<int, MAXN>, MAXN> dis;

void search(int u, int fa, int rt, bool flag) {
    vis[u] |= flag;
    for (auto& v : graph[u]) {
        if (v == fa) continue;
        dis[rt][v] = dis[rt][u] + 1;
        search(v, u, rt, flag & chsck[v]);
    }
}

bool check() {
    for (int i{1}; i <= n; i++) {
        vis[i] = false;
    }
    int cnt{0};
    for (auto& p : chs) {
        if (!vis[p]) cnt++;
        search(p, p, p, 1);
    }
    if (cnt > 2) return false;
    return true;
}

void dfs(int now, int cnt) {
    if (cnt == K) {
        if (!check()) return ;
        int now{0};
        for (int i{1}; i <= n; i++) {
            int par = 1e9;
            for (auto& p : chs) {
                par = std::min(par, dis[p][i]);
            }
            now = std::max(now, par);
        }
        ans = std::min(ans, now);
        return ;
    }
    if (now == n+1) return ;
    chs.emplace_back(now);
    chsck[now] = true;
    dfs(now+1, cnt+1);  
    chs.pop_back();
    chsck[now] = false;
    dfs(now+1, cnt);
}

void work() {
    ans = 1e9;
    dfs(1, 0);
    std::cout << ans << "\n";
}

void clear() {
    for (int i{1}; i <= n; i++) {
        graph[i].clear();
        chsck[i] = false;
        for (int j{1}; j <= n; j++) dis[i][j] = 0;
    }
}

auto main() -> int {
    freopen("hub.in", "r", stdin);
    freopen("hub.out","w",stdout);
    int c, t;
    std::cin >> c >> t;
    while (t--) {
        input();
        work();
        clear();
    }
    return 0;
}