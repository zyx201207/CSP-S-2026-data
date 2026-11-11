#include<bits/stdc++.h>
#include<bits/extc++.h>
#define int long long
using std::cin;
using std::cout;
using std::cerr;
using pii = std::pair<int,int>;
template<typename T>using vec = std::vector<T>;
template<typename T>using vec2 = vec<vec<T>>;
template<typename T1,typename T2>using map = __gnu_pbds::gp_hash_table<T1,T2>;
constexpr int inf = 2e18+7;
struct Solve{
    int n,d;
    vec<int>a;
    vec2<int>g;
    vec2<int>cnt;
    Solve(){
        cin>>n>>d;
        a.assign(n+1,0);
        g.assign(n+1,vec<int>(n+1,inf));
        cnt.assign(n+1,vec<int>(n+1,1));
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int u=1;u<=n;++u){
            for(int v=1;v<=n;++v){
                if(a[v] - a[u] <= d)g[u][v] = 1;
            }
        }
        for(int i=1;i<=n;++i)g[i][i] = 0,cnt[i][i] = 0;
        for(int k=1;k<=n;++k){
            for(int i=1;i<=n;++i){
                for(int j=1;j<=n;++j){
                    int res = g[i][k] + g[k][j];
                    if(res < g[i][j]){
                        g[i][j] = res;
                        cnt[i][j] = 1;
                    }else if(res == g[i][j]){
                        cnt[i][j] += cnt[i][k] * cnt[k][j];
                    }
                }
            }
        }
        int ans = 0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=n;++j){
                if(cnt[i][j] == 2)ans++;
            }
        }
        cout<<ans<<'\n';
    }
};
signed main(){
    cin.tie(0)->sync_with_stdio(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin>>c>>t;
    while(t--){
        Solve();
    }
    return 0;
}
