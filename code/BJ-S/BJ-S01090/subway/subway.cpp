#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll N = 5e2+5,M=5e5+5;
ll C,n,m,d,q;
ll w[M];ll c[N][N];
struct sss{
    ll i,w;
};
vector<sss>s[M];
vector<ll>a[N];
vector<ll>t[N];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&C,&n,&m,&d,&q);
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=n;j++)c[i][j]=1e18;
        c[i][i]=0;
    }
    for(ll i = 1;i<=m;i++)scanf("%lld",&w[i]);
    for(ll i = 1;i<=n;i++){
        ll k;
        scanf("%lld",&k);
        for(ll j = 0;j<k;j++){
            ll k,o;
            scanf("%lld%lld",&k,&o);
            a[i].push_back(k),t[i].push_back(o);
            if(s[a[i][j]].empty()){
                s[a[i][j]].push_back({i,t[i][j]});continue;
            }
            for(auto v:s[a[i][j]]){
                c[v.i][i]=c[i][v.i]=min(1ll*v.w+t[i][j],c[v.i][i]);
            }
            s[a[i][j]].push_back({i,t[i][j]});
        }
    }
    for(ll i = 1;i<=n;i++){
        for(ll j = 1;j<=n;j++){
            for(ll k = 1;k<=n;k++){
                c[i][j]=min(c[i][j],c[i][k]+c[k][j]);
            }
        }
    }
    while(q--){
        ll b,t;
        scanf("%lld%lld",&b,&t);
        ll ans = 1e18+7;
        for(auto u:s[b]){
            for(auto v:s[t]){
                ans = min(ans,u.w+v.w+c[u.i][v.i]);
            }
        }
        ans+=w[b]+w[t];
        printf("%lld\n",ans);
    }
}