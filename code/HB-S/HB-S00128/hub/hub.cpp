#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
    ll x = 0,h = 1;
    char ch = getchar();
    while(!(ch=='-'||('0'<=ch&&ch<='9'))) ch = getchar();
    if(ch=='-') h = -1;
    else x = ch-'0';
    ch = getchar();
    while('0'<=ch&&ch<='9'){
        x = x*10+ch-'0';
        ch = getchar();
    }
    return x*h;
}
namespace G4M1{
    const ll N = 210;
    const ll INF = 1e16;
    ll n,k;
    vector<ll> vec[N];
    bool vis[N];
    ll dis[N][N];
    ll fa[N];
    ll find(ll x){return x==fa[x]?x:fa[x] = find(fa[x]);}
    void merge(ll x,ll y){
        x = find(x),y = find(y);
        if(x!=y) fa[x] = y;
    }
    void main(ll cid){
        n = read(),k = read();
        for(ll i = 1; i <= n; i++){
            for(ll j = 1; j <= n; j++) dis[i][j] = (i==j?0:INF);
        }
        for(ll i = 1; i < n; i++){
            ll u = read(),v = read();
            vec[u].push_back(v);
            vec[v].push_back(u);
            dis[u][v] = dis[v][u] = 1;
        }
        for(ll k = 1; k <= n; k++) for(ll i = 1; i <= n; i++) for(ll j = 1; j <= n; j++){
            dis[i][j] = min(dis[i][j],dis[i][k]+dis[k][j]);
        }
        ll ans = n;
        for(ll i = 0; i < (1LL<<n); i++){
            if(__builtin_popcount(i)!=k) continue;
            ll cur = 0;
            for(ll j = 1; j <= n; j++){
                ll res = n;
                for(ll k = 1; k <= n; k++){
                    if((i>>(k-1))&1) res = min(res,dis[k][j]);
                }
                cur = max(cur,res);
            }
            for(ll j = 1; j <= n; j++) if((i>>(j-1))&1) fa[j] = j;
            for(ll p = 1; p <= n; p++) for(ll q = 1; q <= n; q++){
                if(dis[p][q]==1&&((i>>(p-1))&1)&&((i>>(q-1))&1)) merge(p,q);
            }
            set<ll> st;
            for(ll p = 1; p <= n; p++) if((i>>(p-1))&1) st.insert(fa[p]);
            //printf("{%lld,%lld,%lld}\n",i,cur,(ll)st.size());
            //for(ll p = 1; p <= n; p++) if((i>>(p-1))&1) printf("%lld ",p);puts("");
            if(st.size()<=2) ans = min(ans,cur);
        }
        printf("%lld\n",ans);
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll cid = read(),T = read();
    while(T--) G4M1::main(cid);
    return 0;
}
