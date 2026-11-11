#include <bits/stdc++.h>
#define line 500006
using namespace std;
typedef long long ll;

struct edge {
    ll other;
    ll weigh;
};

struct node {
    ll cur;
    ll step;
};

int c, n, m, d, q;
int w[500005];
int k[500];
int a[500][500005];
int t[500][500005];
int x;
int y;
bool vis[500005];
vector<edge> g[500005];

int main() {
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin >> c >> n >> m >> d >> q;
    for (int i = 1; i <= m; i++) {
        cin >> w[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> k[i];
        for (int j = 1; j <= k[i]; j++) {
            cin >> a[i][j] >> t[i][j];
            g[a[i][j]].push_back((edge){line + i, t[i][j]});
            g[line + i].push_back((edge){a[i][j], t[i][j]});
        }
    }
    while (q--) {
        ll sum = 0;
        cin >> x >> y;
        sum += w[x] + w[y];
        ll ans = 1e18;
        queue<node> q;
        q.push((node){x, 0});
        vis[x] = true;
        while (q.size()) {
            auto now = q.front(); q.pop();
            if (now.cur == y) {
                ans = min(ans, now.step);
                vis[y] = false;
                break;
            }
            for (edge nb : g[now.cur]) {
                q.push((node){nb.other, now.step + nb.weigh});
                vis[nb.other] = true;
            }
        }
        cout << sum + ans << '\n';
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}