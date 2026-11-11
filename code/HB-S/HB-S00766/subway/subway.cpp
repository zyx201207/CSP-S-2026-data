#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define lx LONG_MAX
#define ln LONG_MIN

//zui duan lu
// bing ca ji
const int qq = 5e5+10;
const int qqq = qq*20;
ll c/*none*/,n,m,d/*none*/,q;
ll ans;
ll w[qq];
ll a[25][qq],t[25][qq];
ll f[qq];
void dfs(ll x,ll y){

}

int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i = 1;i <= m;i ++){f[i] = i;}
    for(int i = 1;i <= m;i ++){scanf("%lld",&w[i]);}
    for(int i = 1;i <= n;i ++){
        ll nn;scanf("lld",&nn);
        for(int j = 1;j <= nn;j ++){
            ll aa;scanf("%lld",&aa);
            scanf("%lld%lld",&t[n][aa]);
        }
    }
    for(int i = 1;i <= q;i ++){
        ll x,y;scanf("%lld%lld",&x,&y);
        dfs(x,y);
        ans += w[x]+w[y];
        printf("%lld",ans);
    }
    return 0;
}
