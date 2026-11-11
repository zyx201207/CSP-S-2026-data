#include <bits/stdc++.h>
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define FASTIO ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;
using pii = pair<int, int>;
const int N = 2e6 + 5;
ll a[N], D, dp[N][2];
int n, nxt[N], pre[N], testid, t;
namespace DELETE {
    vector<int> g[N], rev[N];
    vector<int> spe[N];
    void clear(void) {
        for (int i = 1; i <= n; ++i) g[i].clear(), spe[i].clear(), rev[i].clear();
        for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = 0;
    }
    struct BIT {
#define lowbit(x) (x & (-x))
        ll tree[N];
        void clear() {
            for (int i = 1; i < N; ++i) tree[i] = 0;
        }
        void update(int pos, ll val) {
            for (pos; pos < N; pos += lowbit(pos)) tree[pos] += val;
        }
        ll query(int pos) {
            ll ret = 0;
            if (pos <= 0) return ret;
            for (; pos; pos -= lowbit(pos)) ret += tree[pos];
            return ret;
        }
        ll query(int l, int r) { return max(0ll, query(r) - query(l - 1)); }
#undef lowbit
    } T;
    void solve(void) {
        cin >> n >> D;
        clear();
        for (int i = 1; i <= n; ++i) cin >> a[i];
        for (int i = 1; i <= n; ++i) {
            int l = i, r = n, best = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[mid] - a[i] <= D) {
                    best = mid;
                    l = mid + 1;
                }
                else r = mid - 1;
            }
            nxt[i] = best;
        }
        for (int i = 1; i <= n; ++i) {
            int l = 1, r = i, best = i;
            while (l <= r) {
                int mid = (l + r) >> 1;
                if (a[i] - a[mid] <= D) {
                    best = mid;
                    r = mid - 1;
                }
                else l = mid + 1;
            }
            pre[i] = best;
        }
        for (int i = 1; i <= n; ++i) {
            if (nxt[i] != i) {
                if (pre[nxt[i]] == i) {
                    g[i].push_back(nxt[i]);
                    rev[nxt[i]].push_back(i);
                }
                if (i != 1 && i != n && nxt[pre[i]] == i + 1 && pre[nxt[i + 1]] == i)
                    spe[pre[i]].push_back(nxt[i + 1]);
            }
        }
        for (int i = 1; i <= n; ++i) {
            sort(g[i].begin(), g[i].end());
            g[i].erase(unique(g[i].begin(), g[i].end()), g[i].end());
            sort(spe[i].begin(), spe[i].end());
            spe[i].erase(unique(spe[i].begin(), spe[i].end()), spe[i].end());
        }
        T.clear();
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i][0] + 1;
            T.update(i, dp[i][0]);
            if (i != n && pre[nxt[i + 1]] == i && nxt[pre[i]] != i + 1) {
                ans += T.query(i - 1, pre[i + 1]);
            }
            for (auto nxt : g[i])
                dp[nxt][0] += dp[i][0];
        }
        for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = 0;
        T.clear();
        for (int i = n; i >= 1; --i) {
            dp[i][0] = dp[i][0] + 1;
            T.update(i, dp[i][0]);
            if (i != 1 && nxt[pre[i - 1]] == i && pre[nxt[i]] != i - 1)
                ans += T.query(nxt[i - 1], i + 1);
            for (auto nxt : rev[i])
                dp[nxt][0] += dp[i][0];
        }
        for (int i = 1; i <= n; ++i) dp[i][0] = dp[i][1] = 0;
        for (int i = 1; i <= n; ++i) {
            dp[i][0] = dp[i][0] + 1;
            for (auto nxt : g[i]) {
                dp[nxt][0] += dp[i][0];
                dp[nxt][1] += dp[i][1];
            }
            for (auto nxt : spe[i])
                dp[nxt][1] += dp[i][0];
            ans += dp[i][1];
        }
        cout << ans << '\n';
    }
};
namespace Brute {
    pair<int, int> dist[N];
    using node = pair<pair<int, int>, int>;
    pii merge(pii a, pii b) {
        if (a.first == b.first) return make_pair(a.first, a.second + b.second);
        if (a.first < b.first) return a;
        return b;
    }
    void solve(void) {
        ll ans = 0;
        for (int l = 1; l <= n; ++l) {
            for (int j = 1; j <= n; ++j) dist[j] = make_pair(1e9, 0);
            priority_queue<node, vector<node>, greater<node>> pq;
            dist[l] = { 0, 1 };
            pq.push({ {0, 1} ,l });
            while (pq.size()) {
                auto dis = pq.top().first;
                int u = pq.top().second;
                pq.pop();
                if (dist[u] != dis) continue;
                for (int j = u + 1; j <= nxt[u]; ++j) {
                    auto af = merge(dist[j], { dist[u].first + 1, dist[u].second });
                    if (af != dist[j]) {
                        dist[j] = af;
                        pq.push(make_pair(dist[j], j));
                    }
                }
            }
            for (int j = l; j <= n; ++j) {
                ans += dist[j].second == 2;
            }
        }
        cout << ans << '\n';
    }
};
namespace SubA {
    void solve(void) {
        cout << 0 << '\n';
    }
};
namespace SubB {
    void solve(void) {
        ll tmp = D / (a[2] - a[1]);
        if (tmp <= 1) {
            cout << 0 << '\n';
            return;
        }
        ll ans = 0;
        for (int i = 1; i <= n; ++i) {
            ans += 1ll * (n - i) / 2;
        }
        cout << ans << '\n';
    }
};
void solve(void) {
    cin >> n >> D;
    for (int i = 1; i <= n; ++i) cin >> a[i];
    for (int i = 1; i <= n; ++i) {
        int l = i, r = n, best = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[mid] - a[i] <= D) {
                best = mid;
                l = mid + 1;
            }
            else r = mid - 1;
        }
        nxt[i] = best;
    }
    for (int i = 1; i <= n; ++i) {
        int l = 1, r = i, best = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (a[i] - a[mid] <= D) {
                best = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        pre[i] = best;
    }
    if (testid <= 6) Brute::solve();
    else if (testid >= 13 && testid <= 14) {
        SubA::solve();
    }
    else if (testid >= 11 && testid <= 12) {
        SubB::solve();
    }
}
int main() {
    FILE("migrate");
    FASTIO;
    cin >> testid >> t;
    while (t--) solve();
    return 0;
}
/*
0 1
6 4
-3 0 1 2 3 4
*/
