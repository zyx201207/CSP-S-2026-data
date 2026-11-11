#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
using LL = long long;

constexpr int MAX_N = 1e6+5;

int n, m;
vector<int> e[MAX_N];

namespace try_10 {
    constexpr int MAX_N = 12;

    bool flag[MAX_N];
    int ans;

    bool ck[MAX_N];
    int dist[MAX_N];

    void ckl(int u) {
        ck[u] = 1;
        for(auto v : e[u]) {
            if(flag[v] && !ck[v]) ckl(v);
        }
    }

    void make_dist(int u, int fa) {
        if(flag[u]) dist[u] = 0;
        if(fa > 0) dist[u] = min(dist[u], dist[fa]+1);
        for(auto v : e[u]) {
            if(v == fa) continue;
            make_dist(v, u);
            dist[u] = min(dist[u], dist[v] + 1);
        }
    }

    void check() {
        int lian = 0;
        for(int i = 1; i <= n; i ++) ck[i] = 0, dist[i] = n;
        for(int i = 1; i <= n; i ++) {
            if(!ck[i] && flag[i]) {
                ++ lian;
                if(lian > 2) return;
                ckl(i);
            }
        }
        make_dist(1, 0);
        int as = 0;
        for(int i = 1; i <= n; i ++) {
            as = max(as, dist[i]);
        }
        ans = min(ans, as);
    }

    void dfs(int u, int cho) {
        if(cho > m || cho + n - u + 1 < m) return;
        if(u == n+1) {
            check();
            return;
        }
        flag[u] = 1;
        dfs(u+1, cho+1);
        flag[u] = 0;
        dfs(u+1, cho);
    }

    void run() {
        ans = n;
        dfs(1, 0);
        cout << ans << "\n";
    }
}

void solve(int Cases) {
    cin >> n >> m;
    for(int i = 1; i <= n; i ++) {
        e[i].clear();
    }
    for(int i = 1, u, v; i <= n-1; i ++) {
        cin >> u >> v;
        e[u].emplace_back(v);
        e[v].emplace_back(u);
    }
    if(n <= 10) { // ok
        try_10::run();
        return;
    }
}

int main() {
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false), cin.tie(nullptr);
    int c,t;
    cin >> c >> t;
    while(t --) solve(c);
    return 0;
}
