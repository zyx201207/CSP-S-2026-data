#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define rep(i, a, b) for(int i = (a) ; i <= (b) ; i++)
void read(int &x){
    x = 0;
    int f = 1;
    char ch = getchar();
    while(ch < '0' || ch > '9')
        f = (ch == '-' ? -1 : 1), ch = getchar();
    while(ch >= '0' && ch <= '9')
        x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
    x *= f;
}
constexpr int INF = 0x3f3f3f3f3f3f3f3f;
typedef pair<int, int> P;
int dis[510][510];
int c, n, m, d, q;
vector<vector<P>> vec;
int w[500000 + 10];
static inline void chkmin(int &x, int y){
    if(y < x)
        x = y;
}
// #define DEBUG
signed main(){
    #ifndef DEBUG
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    #endif 
    read(c), read(n), read(m), read(d), read(q);
    rep(i, 1, m) read(w[i]);
    vec.resize(m + 1);
    memset(dis, 0x3f, sizeof dis);
    rep(i, 1, n){
        dis[i][i] = 0;
        int k;
        read(k);
        rep(j, 1, k){
            int a, t;
            read(a), read(t);
            vec[a].emplace_back(i, t);
        }
    }
    rep(i, 1, m){
        for(auto x : vec[i])
            for(auto y : vec[i]){
                chkmin(dis[x.fi][y.fi], x.se + y.se);
            }
    }
    rep(k, 1, n)
        rep(i, 1, n)
            rep(j, 1, n)
                chkmin(dis[i][j], dis[i][k] + dis[k][j]);
    rep(i, 1, q){
        int x, y;
        read(x), read(y);
        int ans = INF;
        for(auto px : vec[x])
            for(auto py : vec[y])
                chkmin(ans, dis[px.fi][py.fi] + px.se + py.se + w[x] + w[y]);
        printf("%lld\n", ans);
    }
    return 0;
}