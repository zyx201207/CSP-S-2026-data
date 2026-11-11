#include<bits/stdc++.h>
using namespace std;

#define vec basic_string
const int N = 1e6 + 5;
int typ, T, n, k, u, v;
vec<int> to[N];

inline void MAX(int &a, int b) {a = (a < b ? b : a);}
inline void MIN(int &a, int b) {a = (a < b ? a : b);}

int fmx[N], gmx[N], fa[N];
inline void init(int u, int from){
    fmx[u] = 0; fa[u] = from;
    for(auto v : to[u])
        if(v ^ from){
            init(v, u);
            fmx[u] = max(fmx[u], fmx[v] + 1);
        }
}
inline void init2(int u, int from){
    if(!from) gmx[u] = 0;
    int firv = -1, secv = -1;
    for(auto v : to[u])
        if(v ^ from){
            int vl = fmx[v] + 1;
            if(vl >= firv) secv = firv, firv = vl;
            else secv = max(secv, vl);
        }
    for(auto v : to[u])
        if(v ^ from){
            gmx[v] = gmx[u] + 1;
            if(fmx[v] + 1 == firv) gmx[v] = max(gmx[v], secv + 1);
            else gmx[v] = max(gmx[v], firv + 1); 
            init2(v, u);
        }
}

int D;
int f[N];
inline void dfs(int u, int from){
    f[u] = 1;
    for(auto v : to[u])
        if(v ^ from){
            dfs(v, u);
            if(fmx[v] >= D) f[u] += f[v];
        }
}

int res;
int mxdep[N], gmxdep[N];
bool vis[N];
inline void dfs2(int u, int from, int dep){
    f[u] = 1;
    if(dep <= D) mxdep[u] = -1, vis[u] = false;
    else mxdep[u] = 0, vis[u] = true;
    for(auto v : to[u])
        if(v ^ from){
            dfs2(v, u, dep + 1);
            if(mxdep[v] >= D) f[u] += f[v];
            if(mxdep[v] != -1) mxdep[u] = max(mxdep[u], mxdep[v] + 1);
        }
}
inline void dfs3(int u, int from){
    int firv = -1, secv = -1;
    if(vis[u]) gmxdep[u] = max(gmxdep[u], 0);
    if(gmxdep[u] <= D) res = min(res, f[u]);
    for(auto v : to[u])
        if(v ^ from){
            if(mxdep[v] == -1) continue;
            int vl = mxdep[v] + 1;
            if(vl >= firv) secv = firv, firv = vl;
            else secv = max(secv, vl);
        }
    for(auto v : to[u])
        if(v ^ from){
            gmxdep[v] = -1;
            if(gmxdep[u] != -1) gmxdep[v] = gmxdep[u] + 1;
            if(mxdep[v] != -1 && mxdep[v] + 1 == firv){
                if(secv != -1) MAX(gmxdep[v], secv + 1);
            }
            else if(firv != -1) MAX(gmxdep[v], firv + 1); 
            dfs3(v, u);
        }
}
inline int calc(int u, int v){
    dfs2(u, v, 1), res = n + 5;
    gmxdep[u] = -1, dfs3(u, v);
    return res;
}

int p[N];
mt19937 rnd(time(0));
inline void myzrnd(){
    for(int i = 1; i < n; ++i) swap(p[rnd() % (n - 1) + 1], p[rnd() % (n - 1) + 1]);
}

int savf[N];
inline bool chk(){
    dfs(1, 0);
    for(int i = 1; i <= n; ++i){
        if(f[i] <= k && gmx[i] <= D) return true;
        savf[i] = f[i];
    }
    // if(11 <= typ && typ <= 12) return solve2();
    for(int i = 1; i < n; ++i){
        int qwq = calc(fa[p[i]], p[i]);
        if(qwq + savf[p[i]] <= k) return true;  
    }
    return false;
}

signed main(){
    freopen("hub.in", "r", stdin);
    freopen("hub.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0), cout.tie(0);
    cin >> typ >> T;
    while(T--){
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) to[i].clear(), p[i] = i + 1;
        if(n > 10000 && k > 2) myzrnd();
        for(int i = 1; i < n; ++i) cin >> u >> v, to[u] += v, to[v] += u;
        if(k >= n) {cout << "0\n"; continue;}
        init(1, 0), init2(1, 0);
        int L = 0, R = n, mid;
        while(L + 1 < R){
            mid = L + R >> 1;
            D = mid;
            if(chk()) R = mid;
            else L = mid;
        }
        cout << R << '\n';
    }
    return 0;
}