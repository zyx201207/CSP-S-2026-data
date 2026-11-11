#include<bits/stdc++.h>
#define fi first
#define se second
// #define int long long
// #define W(x) cerr<<#x<<':'<<x<<'\n'
#define gc getchar_unlocked
#define pc putchar_unlocked
using namespace std;
using ll=long long;
using db=long double;
using ull=unsigned long long;
const int N = 505;
const int M = 5e5+10;
const int MOD = 1e9+7;
namespace IO{
    template<typename T> inline void rd(T &x){
        x=0;
        bool f = 0;
        char c = gc();
        for(;!isdigit(c);c=gc())if(c=='-')f=1;
        for(;isdigit(c);c=gc())x=(x<<1)+(x<<3)+(c^48);
        if(f)x=-x;
    }
    template<typename T> inline void wt(const T &x){
        if(x<0){
            pc('-');
            wt(-x);
            return;
        }
        if(x>9){
            wt(x/10);
        }
        pc(x%10+'0');
    }
}using namespace IO;
int subtask,n,m,d,q;
ll w[M];
struct Edge{
    int stat;
    ll t;
};
vector<Edge> g[M];
ll dis[N][N];
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    // cin >> subtask >> n >> m >> d >> q;
    rd(subtask),rd(n),rd(m),rd(d),rd(q);
    for(int i = 1;i<=m;i++){
        // cin >> w[i];
        rd(w[i]);
        g[i].reserve(d);
    }
    for(int i = 1;i<=n;i++){
        int k;
        // cin >> k;
        rd(k);
        for(int j = 1;j<=k;j++){
            int p;
            ll t;
            // cin >> p >> t;
            rd(p),rd(t);
            g[p].push_back({i,t});
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i!=j)dis[i][j] = LLONG_MAX;
        }
    }
    for(int i = 1;i<=m;i++){
        for(int j = 0;j<g[i].size();j++){
            for(int k = 0;k<j;k++){
                int u = g[i][j].stat,v = g[i][k].stat;
                ll cost = g[i][j].t + g[i][k].t;
                dis[u][v] = min(dis[u][v],cost);
                dis[v][u] = min(dis[v][u],cost);
            }
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            for(int k = 1;k<=n;k++){
                if(dis[i][k]==LLONG_MAX||dis[k][j]==LLONG_MAX){
                    continue;
                }
                dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        rd(x),rd(y);
        ll Ans = LLONG_MAX;
        for(int i = 0;i<g[x].size();i++){
            for(int j = 0;j<g[y].size();j++){
                if(dis[g[x][i].stat][g[y][j].stat]==LLONG_MAX)continue;
                ll now = dis[g[x][i].stat][g[y][j].stat] + g[x][i].t + g[y][j].t;
                Ans = min(Ans,now);
            }
        }
        Ans += w[x] + w[y];
        wt(Ans);
        pc('\n');
    }
    return 0;
}
/*
compile:
g++ -o B B.cpp -O2 -static -std=c++14


*/