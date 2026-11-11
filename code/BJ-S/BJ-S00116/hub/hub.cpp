#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 5;
long long C, T, n, k, U[N], V[N], d[105], e[105], f[105], ff[105], dis[105], ans = 1e18, fa[N], dep[N], maxdep[N], maxidep;
vector<long long> g[N];
void dfs(long long u, long long ffff){
    dis[u] = min(dis[u], dis[ffff] + 1);
    for (long long v : g[u]){
        if (v == ffff)
            continue;
        dfs(v, u);
        dis[u] = min(dis[u], dis[v] + 1);
    }
    return ;
}
long long findf(long long x){
    if (x == f[x])
        return x;
    return f[x] = findf(f[x]);
}
void Sreach(long long step, long long lst){
    if (step == k + 1){
        long long cnt = 0;
        for (int i = 1; i <= n; i ++)
            f[d[i]] = d[i], ff[i] = 0;
        for (int i = 1; i < n; i ++)
            if (e[U[i]] && e[V[i]])
                f[U[i]] = V[i];
        for (int i = 1; i <= n; i ++)
            findf(i);
        for (int i = 1; i <= k; i ++)
            if (ff[f[d[i]]] == 0)
                ff[f[d[i]]] = 1, cnt ++;
        if (cnt > 2)
            return ;
        for (int i = 0; i <= n; i ++)
            dis[i] = 1e18;
        for (int i = 1; i <= k; i ++)
            dis[d[i]] = 0;
        dfs(1, 0);
        long long maxn = 0;
        for (int i = 1; i <= n; i ++)
            maxn = max(maxn, dis[i]);
        ans = min(ans, maxn);
        return ;
    }
    for (int i = lst; i <= n - k + step; i ++){
        d[step] = i, e[i] = 1;
        Sreach(step + 1, i + 1);
        d[step] = i, e[i] = 0;
    }
    return ;
}
void dfs2(long long u, long long ffff){
    fa[u] = ffff, dep[u] = dep[ffff] + 1, maxdep[u] = dep[u];
    if (dep[maxidep] < dep[u])
        maxidep = u;
    for (int v : g[u]){
        if (v == ffff)
            continue;
        dfs2(v, u);
        maxdep[u] = max(maxdep[u], dep[u]);
    }
    return ;
}
bool check(long long flag){
    long long u1 = maxidep;
    while (maxdep[u1] - dep[u1] < flag && u1 != 0)
        u1 = fa[u1];
    if (u1 <= 1)
        return 1;
    maxidep = 1;
    dfs2(u1, 0);
    long long u2 = maxidep;
    while (maxdep[u2] - dep[u2] < flag && u2 != 0)
        u2 = fa[u2];
    if (u2 == 0 || u2 == u1)
        return 1;
    for (int i = 0; i <= n; i ++)
        dis[i] = 1e18;
    dis[u1] = 0, dis[u2] = 0;
    dfs(1, 0);
    long long maxn = 0;
    for (int i = 1; i <= n; i ++)
        maxn = max(maxn, dis[i]);
    return maxn <= flag;
}
int main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    cin >> C >> T;
    while (T --){
        cin >> n >> k;
        for (int i = 1; i <= n; i ++)
            g[i].clear();
        for (int i = 1; i < n; i ++){
            cin >> U[i] >> V[i];
            g[U[i]].push_back(V[i]);
            g[V[i]].push_back(U[i]);
        }
        if (C <= 3){
            ans = 1e18;
            Sreach(1, 1);
            cout << ans << "\n";
        } else if (C == 7) {
            maxidep = 1;
            dfs2(1, 0);
            long long l = 0, r = n;
            while (l < r){
                long long mid = l + r >> 1;
                if (check(mid))
                    r = mid;
                else l = mid + 1;
            }
            cout << l << "\n";
        } else if (k == n)
            cout << "0\n";
        else cout << "1\n";
    }
    return 0;
}
