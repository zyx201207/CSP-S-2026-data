#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
#define fi first
#define se second
using std::cin;
using std::cout;
using std::cerr;
using pii = std::pair<int,int>;
template<typename T>using vec = std::vector<T>;
template<typename T>using vec2 = vec<vec<T>>;
template<typename T1,typename T2>using map = __gnu_pbds::gp_hash_table<T1,T2>;
constexpr int maxd = 22,inf = 1e15+7;;
struct Solve{
    int c,n,m,d,q;
    vec<int>w;
    vec<map<int,int>>sta;
    vec2<int>g;
    void debug(){
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                cerr<<g[i][j]<<" \n"[j==n];
            }
        }
    }
    Solve(){
        cin>>c>>n>>m>>d>>q;
        w.assign(m+1,0);
        sta.resize(m+1);
        for(int i=1;i<=m;++i)cin>>w[i];
        for(int i=1;i<=n;++i){
            int k;
            cin>>k;
            for(int j=1;j<=k;++j){
                int station,time;
                cin>>station>>time;
                sta[station][i] = time;
            }
        }
        g.assign(n+1,vec<int>(n+1,inf));
        for(int i=1;i<=n;++i)g[i][i] = 0;
        for(int i=1;i<=m;++i){
            for(auto p1:sta[i]){
                int line1 = p1.fi,cost1 = p1.se;
                for(auto p2:sta[i]){
                    int line2 = p2.fi,cost2 = p2.se;
                    if(line1 != line2)g[line1][line2] = cost1 + cost2;
                }
            }
        }
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    g[i][j] = std::min(g[i][j],g[i][k] + g[k][j]);
                }
            }
        }
        // debug();
        for(int i=1;i<=q;++i){
            int u,v;
            cin>>u>>v;
            int ans = inf;
            for(auto p1:sta[u]){
                int line1 = p1.fi,cost1 = p1.se;
                for(auto p2:sta[v]){
                    int line2 = p2.fi,cost2 = p2.se;
                    ans = std::min(ans,cost1 + cost2 + g[line1][line2]);
                }
            }
            cout<<ans + w[u] + w[v]<<'\n';
        }
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    Solve();
    return 0;
}
