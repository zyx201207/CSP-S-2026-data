#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fi first
#define se second
using namespace std;

const int MAXN = 5e5 + 505;
const ll inf = 1e18;
int n, m, D, q, tot, tot1;
int w[MAXN]; pii a[MAXN], b[MAXN];
struct Edge{ int to, nxt, w; }e[MAXN];
int head[MAXN], cur;
void Add(int u, int v, int w){ e[++cur] = {v, head[u], w}; head[u] = cur; }
ll d[505][505];

signed main(){
    freopen("subway.in", "r", stdin), freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int _; cin >> _ >> n >> m >> D >> q;
    for(int i = 1; i <= m; ++i) cin >> w[i];
    for(int i = 1; i <= n; ++i){
        int k; cin >> k;
        for(int j = 1, x, y; j <= k; ++j){
            cin >> x >> y;
            Add(x, i + m, y);
        }
    }
    for(int i = 1; i <= n; ++i){
        for(int j = 1; j <= n; ++j){
            d[i][j] = inf;
        }
        d[i][i] = 0;
    }
    for(int u = 1; u <= m; ++u){
        tot = 0;
        for(int i = head[u]; i; i = e[i].nxt){
            int v = e[i].to, w = e[i].w;
            a[++tot] = {v - m, w};
        }
        for(int i = 1; i <= tot; ++i) for(int j = 1; j <= tot; ++j){
            if(i != j){
                int u = a[i].fi, v = a[j].fi;
                d[u][v] = min(d[u][v], (ll)(a[i].se + a[j].se));
                d[v][u] = min(d[v][u], (ll)(a[i].se + a[j].se));
            }
        }
    }
    for(int k = 1; k <= n; ++k) for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j){
        d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
    }
    for(int x, y; q; --q){
        cin >> x >> y; tot = tot1 = 0;
        for(int i = head[x]; i; i = e[i].nxt){
            int v = e[i].to, w = e[i].w;
            a[++tot] = {v - m, w};
        }
        for(int i = head[y]; i; i = e[i].nxt){
            int v = e[i].to, w = e[i].w;
            b[++tot1] = {v - m, w};
        }
        ll ans = inf;
        for(int i = 1; i <= tot; ++i) for(int j = 1; j <= tot1; ++j){
            ans = min(ans, d[a[i].fi][b[j].fi] + a[i].se + b[j].se);
        }
        cout << ans + w[x] + w[y] << '\n';
    }

    return 0;
}