#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int mx = 6e5;
vector <pair <int, long long>> G[mx];
vector <pair <int, int>> qst[mx];
long long fst[mx];
int x[mx], y[mx];
int lca[mx];

void adr(int u, int v, int w){
    G[u].push_back({v, w});
    G[v].push_back({u, w});
}

struct edges{
    int u, v, w;
    friend bool operator<(edges a, edges b){
        return a.w < b.w;
    }
};
vector <edges> eds;

int S[mx];
int fd(int x){return x == S[x]? x : S[x] = fd(S[x]);}

long long dpt[mx];
bool vis[mx];
void dfs(int u, int f){
    vis[u] = true;
    for(auto &[v, id] : qst[u]){
        if(!vis[v]) continue;
        lca[id] = fd(v);
    }

    for(auto &[v, w] : G[u]){
        if(v == f) continue;
        dpt[v] = dpt[u] + w;
        dfs(v, u);
        S[v] = u;
    }
}

int main(){
    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);

    int c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i <= m; ++i) cin >> fst[i];
    for(int i = 1; i <= n; ++i){
        int k;
        cin >> k;
        int u = m + i;
        for(int j = 1; j <= k; ++j){
            int a, t;
            cin >> a >> t;
            eds.push_back({u, a, t});
        }
    }
    sort(eds.begin(), eds.end());

    for(int i = 1; i <= m + n; ++i) S[i] = i;
    for(auto [u, v, w] : eds){
        int l = fd(u), r = fd(v);
        if(l == r) continue;
        adr(u, v, w);
        S[l] = r;
    }

    for(int i = 1; i <= q; ++i){
        cin >> x[i] >> y[i];
        qst[x[i]].push_back({y[i], i});
        qst[y[i]].push_back({x[i], i});
    }

    for(int i = 1; i <= m + n; ++i) S[i] = i;
    dfs(1, 0);

    for(int i = 1; i <= q; ++i){
        long long fs = fst[x[i]] + fst[y[i]];
        long long dis = dpt[x[i]] + dpt[y[i]] - dpt[lca[i]] * 2;
        cout << fs + dis << '\n';
    }
}
