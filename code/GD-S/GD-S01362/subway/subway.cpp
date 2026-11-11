#include <bits/stdc++.h>
#define _rep(i, x, y) for(int i = x; i <= y; ++i)
#define _req(i, x, y) for(int i = x; i >= y; --i)
#define fi first
#define se second
#define pb push_back
#define mst(f, i) memset(f, i, sizeof f)
using namespace std;
typedef long long ll;
typedef pair<ll, ll> PII;
#define debug(...) fprintf(stderr, __VA_ARGS__), fflush(stderr)
namespace fastio{
    template<typename T> inline void read(T &t){
        T x = 0, f = 1;
        char c = getchar();
        while(!isdigit(c)){
            if(c == '-') f = -f;
            c = getchar();
        }
        while(isdigit(c)) x = x * 10 + c - '0', c = getchar();
        t = x * f;
    }
    template<typename T, typename ... Args> inline void read(T &t, Args &...args){
        read(t), read(args...);
    }
    void write(int x){printf("%d", x);}
    void writes(int x){printf("%d ", x);}
    void writeln(int x){printf("%d\n", x);}
    void write(ll x){printf("%lld", x);}
    void writes(ll x){printf("%lld ", x);}
    void writeln(ll x){printf("%lld\n", x);}
}
using namespace fastio;
#define multitest() int T; read(T); _rep(tCase, 1, T)
const int N = 505, M = 5e5 + 5;
const ll inf = 0x3f3f3f3f3f3f3f3f;
int tid, n, m, d, q;
vector<PII> vt[M];
ll w[M], dis[N][N];

int main(){
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    read(tid, n, m, d, q);
    _rep(i, 1, m) read(w[i]);
    _rep(i, 1, n){
        int k; read(k);
        _rep(j, 1, k){
            int u, t; read(u, t);
            vt[u].pb({i, t});
        }
    }
    _rep(i, 1, n) _rep(j, 1, n) dis[i][j] = inf;
    _rep(i, 1, n) dis[i][i] = 0;
    _rep(i, 1, m){
        int len = vt[i].size();
        _rep(x, 0, len - 1) _rep(y, x + 1, len - 1){
            int u = vt[i][x].fi, v = vt[i][y].fi; ll cur = vt[i][x].se + vt[i][y].se;
            dis[u][v] = min(dis[u][v], cur);
            dis[v][u] = min(dis[v][u], cur);
        }
    }
    _rep(k, 1, n){
        _rep(i, 1, n){
            _rep(j, 1, n){
                dis[i][j] = min(dis[i][j], dis[i][k] + dis[k][j]);
            }
        }
    }
    _rep(i, 1, q){
        int x, y; read(x, y);
        ll ans = inf;
        for(auto &[u, l] : vt[x]) for(auto &[v, r] : vt[y]){
            ans = min(ans, dis[u][v] + l + r);
        }
        ans += w[x] + w[y];
        writeln(ans);
    }
    return 0;
}