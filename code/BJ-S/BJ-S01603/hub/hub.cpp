#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const ll MAXN = 5e5 + 5;
ll n, k;
vector <ll> adj[MAXN];
ll f[MAXN][20];
ll dep[MAXN];
void dfs(ll u, ll fa) {
    dep[u] = dep[fa] + 1;
    f[u][0] = fa;
    for(ll it:adj[u]) {
        if(it == fa)
            continue;
        dfs(it, u);
    }
    return ;
}
ll lca(ll u, ll v) {
    if(dep[u] < dep[v])
        swap(u, v);
    ll x = dep[u] - dep[v], now = 0;
    while(x) {
        if(x & 1)
            u = f[u][now];
        now++;
        x >>= 1;
    }
    if(u == v)
        return u;
    for(int i = 20; i >= 0; i--)
        if(f[u][i] == f[v][i]) {
            u = f[u][i];
            v = f[v][i];
        }
    return f[u][0];
}
ll dis(ll u, ll v) {
    return dep[u] + dep[v] - 2 * dep[lca(u, v)];
}
ll r1s[MAXN];
bool chk(ll cn) {
    for(int i = 1; i <= n; i++) {
        // cout << i << " : \n";
        bitset <100> x;
        for(int j = 1; j <= n; j++) {
            if(dis(i, j) <= cn)
                x[j] = 1;
                // , cout << j << " ";
        }
        // cout << "\n";
        r1s[i] = x.to_ullong() >> 1;
        // cout << cn << " " << i << " : " << r1s[i] << "\n";
    }
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            if((r1s[i] | r1s[j]) == ((1 << n) - 1))
                return 1;
    return 0;
}
void work() {
    cin >> n >> k;
    memset(f, 0, sizeof f);
    for(int i = 1; i <= n; i++) 
        adj[i].clear(), dep[i] = 0;
    for(int i = 1; i < n; i++) {
        ll u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    dfs(1, 1);
    for(int j = 1; j <= 10; j++)
        for(int i = 1; i <= n; i++) 
            f[i][j] = f[f[i][j - 1]][j - 1];
    ll l = 0, r = n, ans = 0;
    while(l <= r) {
        ll mid = l + r >> 1;
        if(chk(mid))
            r = mid - 1, ans = mid;
        else
            l = mid + 1;
    }
    cout << ans << "\n";
}
int main() {
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);     cout.tie(0);
    ll c, t;
    cin >> c >> t;
    while(t--)
        work();
    return 0;
}