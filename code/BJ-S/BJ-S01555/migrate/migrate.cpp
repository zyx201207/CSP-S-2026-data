#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2000005;
ll x[MAXN];
int nxt[MAXN];
int dist[MAXN], ways[MAXN];
int n;
ll d;
void solve() {
    cin >> n >> d;
    for (int i = 1; i <= n; i++) cin >> x[i];
    int r = 1;
    for (int i = 1; i <= n; i++) {
        if (r < i) r = i;
        while (r + 1 <= n && x[r + 1] - x[i] <= d) r++;
        nxt[i] = r;
    }
    ll ans = 0;
    for (int s = 1; s <= n; s++) {
        set<int> st;
        for (int i = s; i <= n; i++) st.insert(i);
        dist[s] = 0; ways[s] = 1;
        st.erase(s);
        queue<int> q;
        q.push(s);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (nxt[u] <= u) continue;
            auto it = st.lower_bound(u + 1);
            while (it != st.end() && *it <= nxt[u]) {
                int v = *it;
                if (dist[v] == -1) {
                    dist[v] = dist[u] + 1;
                    ways[v] = ways[u];
                    q.push(v);
                    ++it;
                } else if (dist[v] == dist[u] + 1) {
                    ways[v] = min(3, ways[v] + ways[u]);
                    if (ways[v] >= 3) {
                        it = st.erase(it);
                    } else {
                        ++it;
                    }
                } else {
                    ++it;
                }
            }
        }
        for (int v = s + 1; v <= n; v++) {
            if (ways[v] == 2) ans++;
        }
        for (int v = s; v <= n; v++) {
            dist[v] = -1;
            ways[v] = 0;
        }
    }
    cout << ans << "\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while (t--) {
        solve();
    }
    return 0;
}
