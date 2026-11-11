#include <bits/stdc++.h>
#define ll long long
#define pii pair<int, int> 
#define fi first 
#define se second 
using namespace std;
const int N = 1005;

int n, k, ID, T, dep[N], mxd[N], f[N][N], F[N];
vector<int> g[N];

priority_queue<pii> q;

void Min(int &x, int y){ (x > y) && (x = y); }
void Max(int &x, int y){ (x < y) && (x = y); }

void dfs(int u, int fa, int ban){
    dep[u] = dep[fa] + 1, mxd[u] = 1, F[u] = fa;
    for(int v : g[u]){
        if(v == fa || v == ban) continue;
        dfs(v, u, ban);
        Max(mxd[u], mxd[v] + 1);
    }
}

void get(int rt, int ban){
    while(!q.empty()) q.pop();
    for(int u : g[rt]) if(dep[u] > dep[rt] && u != ban) q.push({mxd[u], u});
    f[rt][1] = (q.size() ? q.top().fi : 0);
    for(int i = 2; i <= k; i++){
        if(!q.empty()){
            int u = q.top().se; q.pop();
            for(int v : g[u]) if(dep[v] > dep[u] && v != ban) q.push({mxd[v], v});
        }
        f[rt][i] = (q.size() ? q.top().fi : 0);
    }
}

void solve(){
    cin >> n >> k;
    for(int i = 1; i <= n; i++) g[i].clear();
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v;
        g[u].push_back(v), g[v].push_back(u);
    }
    // if(T != 0) return;
    int ans = n;
    for(int rt1 = 1; rt1 <= n; rt1++){
        dfs(rt1, 0, 0), get(rt1, 0), Min(ans, f[rt1][k]);
        // cerr << rt1  << ' ' << f[rt1][k] << endl;
        for(int rt2 = 1; rt2 <= n; rt2++){
            if(rt1 == rt2) continue;
            dfs(rt1, 0, 0), get(rt2, 0);
            dfs(rt1, 0, rt2), get(rt1, rt2);
            // assert(mxd[F[rt2]] == 1);
            // cerr << rt1 << ' ' << rt2 << ' ' << F[rt2] << ' ' << mxd[F[rt2]] << endl;
            for(int x = 1; x < k; x++) Min(ans, max(f[rt1][x], f[rt2][k - x]));
        }
    }
    cout << ans << '\n';
}

int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> ID >> T;
    while(T--){
        solve();
        
    }
    return 0;
}
