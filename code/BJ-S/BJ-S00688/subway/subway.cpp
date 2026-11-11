#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 505;
int c, n, m, p, q, a[N], w[N], f[N][N], d[N];
struct node {
    int v, w;
    bool operator>(const node o) {
        return w > o.w;
    }
};
vector<pair<int, ll>> e[N];

int dijsktra() {
    memset(d, 0x3f, sizeof(d));
    priority_queue<pair<ll, ll>,
                   vector<pair<ll, ll>>,
                   greater<pair<ll, ll>>> q;
    q.push({ 1, 0 });
    while(!q.empty()) {
        int u = q.top().first, dist = q.top().second;q.pop();
        if(d[u] != dist) continue;

        for(auto [v, w] : e[u]) {
            d[v] = d[u] + w;
            q.push({v, w});
        }
    }
}

int main() {
    memset(f, 0x3f3f3f3f, sizeof(f));
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    cin >> c >> n >> m >> p >> q;
    for(int i = 1; i <= m; i++) {
        cin >> w[i];
    }

    for(int i = 1; i <= n; i++) {
        int k;
        cin >> k;
        int u = i;
        for(int i = 1; i <= k; i++) {
            int v, w;
            cin >> v >> w;
            //cout << u << " " << v << " " << w << endl;
            f[u][v] = f[v][u] = min(w, f[u][v]);
            //e[u].push_back({v, w});
            //e[v].push_back({u, w});
        }
    }

    for(int k = 1; k <= n; k++) {
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= n; j++) {
                //cout <<>f[i][j]
                //if(i == j) f[i][j] += min(f[i][j], f[i][k] + f[k][j]);
                f[i][j] = min(f[i][j], f[i][k] + f[k][j]);
                //cout << i << " " << j << " " << f[i][j] << endl;
            }
            //cout << endl;
        }
    }

    for(int i = 1; i <= q; i++) {
        int ans = 0;
        int u, v;
        cin >> u >> v;
        //dijsktra();
        //for(int i = 1; i <= p; i++) {
        //    ans = min(ans, w[u] + f[u][v] + w[v]);
        //}
        cout << w[u] + f[u][u] + f[u][v] + w[v] << endl;
    }

    return 0;
}
