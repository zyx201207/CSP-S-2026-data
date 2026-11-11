#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5 +5;
bool vis[N];
ll ste[N], cc[N];
ll n, ans, a[N], c, t, d;
vector <ll> g[N];
void bfs(ll x) {
    queue <ll> que;
    vis[x] = 1;
    que.push(x);
    while(!que.empty()) {
        ll u = que.front();
        que.pop();
        for(auto v:g[u]) {
            if(!vis[v]) {
                vis[v] = 1;
                ll tmp = ste[u] + 1;
                ste[v] = ste[u] + 1;
                que.push(v);
                cc[v] = 1;
            }
            else {
                if(ste[u] + 1 == ste[v]) {
                    cc[v]++;
                }
            }
        }
    }
    for(int i = x + 1; i <= n; i++) {
        if(cc[i] == 2) {
            ans++;
        }
    }
    memset(cc, 0, sizeof(cc));
    memset(ste, 0, sizeof(ste));
    memset(vis, 0, sizeof(vis));
}
int main() {
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--) {
        for(int i = 1; i <= n; i++) {
            g[i].clear();
        }
        cin >> n >> d;
        for(int i = 1; i <= n; i++) {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++) {
            for(int j = i + 1; j <= n; j++) {
                if(abs(a[i] - a[j]) <= d) {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        for(int i = 1; i <= n; i++) {
            bfs(i);
        }
        cout << ans << endl;
        ans = 0;
    }

    return 0;
}
