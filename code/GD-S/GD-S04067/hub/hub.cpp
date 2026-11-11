#include<bits/stdc++.h>
#define pb push_back
#define pii pair<int, int>
#define ll long long
#define fi first
#define se second
using namespace std;

const int maxn = 1e6 + 5;
const int inf = (int)1e9 + 31;
int n, k, d[maxn], f[maxn], MN, dep[maxn], C;
vector<int> E[maxn];

void dfs1(int u, int fa, int x){
    d[u] = 0;
    f[u] = 1;
    for(int v : E[u]) if(v ^ fa){
        dfs1(v, u, x);
        d[u] = max(d[u], d[v] + 1);
        if(d[v] >= x) f[u] += f[v];
    }
}

void dfs2(int u, int fa, int x, int t){
    dep[u] = dep[fa] + 1;
    if(dep[u] <= t){
        MN = min(MN, f[u]);
    }
    int mx = 0, p = 0, mx1 = 0;
    for(int v : E[u]) if(v ^ fa){
        if(d[v] + 1 > mx) mx1 = mx, p = v, mx = d[v] + 1;
        else mx1 = max(mx1, d[v] + 1);
    }
    for(int v : E[u]) if(v ^ fa){
        int y = (v == p ? mx1 : mx), tt = t;
        if(dep[u] + y > x) tt = min(tt, x - y + dep[u]);
        dfs2(v, u, x, tt);
    }
}

bool check(int x){
    int mn = inf;
    for(int u = 1; u <= n; u++){
        dfs1(u, 0, x);
        dep[u] = 0;
        int sum = 1;
        for(int v : E[u]){
            if(d[v] >= x) sum += f[v];
        }
        for(int v : E[u]){
            MN = inf;
            dfs2(v, u, x, inf);
            mn = min(mn, MN + sum - (d[v] >= x ? f[v] : 0));
        }
    }
    return mn <= k;
}

namespace solve1{
    int m;
    bool check(int x){
        for(int i = x; i <= m; i++){
            int l1 = i - x + 1, l2 = k - l1;
            if(l2 < 0) continue;
            int j = m - l2 + 1 - x + 1;
            if(j <= i) return 1;
            int len = j - i + 1;
            if((len + 1) / 2 <= x) return 1;
        }
        return 0;
    }
    void solve(){
        if(k == n){
            cout << "0\n";
            return ;
        }
        m = n / 2;
        int l = 1, r = n / 2, ans = 0;
        while(l <= r){
            int mid = l + r >> 1;
            if(check(mid)) r = mid - 1, ans = mid;
            else l = mid + 1;
        }
        cout << ans << '\n';
    }
}

void solve(){
    for(int i = 1; i <= n; i++) E[i].clear();
    cin >> n >> k;
    for(int i = 1; i < n; i++){
        int u, v; cin >> u >> v; E[u].pb(v); E[v].pb(u);
    }
    if(C == 13 || C == 14){
        solve1::solve();
        return ;
    }
    int l = 0, r = n, ans = -1;
    while(l <= r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid - 1, ans = mid;
        else l = mid + 1;
    }
    cout << ans << '\n';
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> C >> t; while(t--) solve();

    return 0;
}
