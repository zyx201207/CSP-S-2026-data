#include <bits/stdc++.h>
using namespace std;
constexpr int N = 5e5 + 7;
constexpr int M = 505;
int c, n, m, d, q, w[N];
long long ans[N];
struct node {int to; long long dist;};
vector<node> g[N];
queue<int> s;
long long solve(int x, int y) {
    memset(ans, LLONG_MAX, sizeof(ans));
    s.push(x);
    ans[x] = 0;
    while(!s.empty()) {
        int u = s.front();s.pop();
        for(auto v : g[u]) {
            if(ans[v.to] > ans[u] + v.dist) {
                ans[v.to] = ans[u] + v.dist;
                s.push(v.to);
            }
        }
    }
    return ans[y] + 1LL * (w[x] + w[y]);
}
int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; i++) cin >> w[i];
    for(int i = 1; i <= n; i++) {
        int k;cin >> k;int u, c;
        for(int j = 1; j <= k; j++) {
            int v;long long w;cin >> v >> w;
            if(j == 1) {u = v;c = w;continue;}
            g[u].push_back({v, w + c});
            g[v].push_back({u, w + c});
            u = v;c = w;
        }
    }
    while(q--) {
        int x, y;
        cin >> x >> y;
        cout << solve(x, y) << "\n";
    }
    return 0;
}
