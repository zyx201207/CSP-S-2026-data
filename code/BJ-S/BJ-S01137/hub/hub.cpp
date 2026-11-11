#include <bits/stdc++.h>

using i64 = int;
using VL = std::vector<i64>;
auto& IG = std::ignore;
const i64 MAXN = 1e6 + 10, INF = 0x3f3f3f3f;
i64 c, n, siz[MAXN], dept[MAXN], maxd[MAXN], ans, k;
std::vector<i64> gr[MAXN];
VL fr[MAXN];

void dfs1(i64 u, i64 fa) {
    dept[u] = dept[fa] + 1;
    maxd[u] = dept[u];
    siz[u] = 1;
    for (i64 v : gr[u]) if (v != fa) {
        dfs1(v, u);
        siz[u] += siz[v];
        maxd[u] = std::max(maxd[u], maxd[v]);
    }
}

void dfs2(i64 u, i64 fa) {
    fr[u].clear();
    fr[u].shrink_to_fit();
    fr[u].resize(siz[u] + 5, INF);
    VL hr(siz[u] + 5);
    i64 cs = 1;
    fr[u][1] = 0;
    for (i64 v : gr[u]) if (v != fa) {
        dfs2(v, u);
        for (i64 j = 0; j <= cs + siz[v]; ++j) {
            hr[j] = INF;
        }
        for (i64 i = 1; i <= cs; ++i) {
            for (i64 j = 1; j <= siz[v]; ++j) {
                hr[i + j] = std::min(hr[i + j], std::max(fr[u][i], fr[v][j]));
            }
        }
        for (i64 i = 1; i <= cs; ++i) {
            hr[i] = std::min(hr[i], std::max(fr[u][i], maxd[v] - dept[u]));
        }
        cs += siz[v];
        for (i64 i = 1; i <= cs; ++i) {
            fr[u][i] = hr[i];
        }
    }
}

void dfs4(VL& hr, i64 u, i64 fa, i64 mx) {
    for (i64 i = 1; i <= siz[u]; ++i) {
        hr[i] = std::min(hr[i], std::max(mx, fr[u][i]));
    }
    for (i64 i = 0; i < (i64) gr[u].size(); ++i) if (gr[u][i] != fa) {
        i64 cur = 0;
        for (i64 j = 0; j < (i64) gr[u].size(); ++j) if (gr[u][j] != fa && i != j) {
            cur = std::max(cur, maxd[gr[u][j]] - dept[u]);
        }
        dfs4(hr, gr[u][i], u, std::max(mx, cur));
    }
}

void dfs5(i64& mxd, i64 u, i64 fa, i64 d) {
    mxd = std::max(mxd, d);
    for (i64 v : gr[u]) if (v != fa) {
        dfs5(mxd, v, u, d + 1);
    }
}

void dfs3(i64 u, i64 fa) {
    for (i64 v : gr[u]) if (v != fa) {
        dfs3(v, u);
    }
    std::priority_queue<i64> que;
    for (i64 v : gr[u]) {
        i64 mxd = 0;
        dfs5(mxd, v, u, 1);
        que.emplace(mxd);
        while (que.size() > 3) que.pop();
    }
    i64 mx = 0;
    if (que.size() == 3) {
        que.pop();
        que.pop();
        mx = que.top();
    }
    VL hr, last(siz[u] + 5, INF);
    last[0] = 0;
    for (i64 v : gr[u]) if (v != fa) {
        hr.assign(siz[v] + 5, INF);
        dfs4(hr, v, u, 0);
        for (i64 i = std::max(0, k - (i64) hr.size()); i <= std::min(k, (i64) last.size() - 1); ++i) {
            ans = std::min(ans, std::max(mx, std::max(last[i], hr[k - i])));
        }
        for (i64 i = 0; i < (i64) hr.size(); ++i) {
            last[i] = std::min(last[i], hr[i]);
        }
    }
}

void solve(void) {
    std::cin >> n >> k;
    for (i64 i = 1; i <= n; ++i) {
        gr[i].clear();
    }
    for (i64 i = 1; i < n; ++i) {
        i64 x = 0, y = 0;
        std::cin >> x >> y;
        gr[x].emplace_back(y);
        gr[y].emplace_back(x);
    }
    dfs1(1, 0);
    dfs2(1, 0);
    ans = INF;
    dfs3(1, 0);
    std::cout << ans << '\n';
}

int main() {
    IG = freopen("hub.in", "r", stdin);
    IG = freopen("hub.out", "w", stdout);

    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);

    i64 t = 0;
    std::cin >> c >> t;
    while (t--) solve();

    return 0;
}
