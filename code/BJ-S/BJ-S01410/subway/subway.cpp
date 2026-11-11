#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll c,n,m,d,q;
ll f[501][501],w[500001],dis[501][501];
struct node{
    ll id,t;
    friend bool operator<(node x,node y){
        return x.t>y.t;
    }
};
vector<node> vec[500001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    cin >>c >>n >>m >>d >>q;
    for(int i=1;i<=m;i++) cin >>w[i];
    for(int i=1;i<=n;i++){
        ll g;cin >>g;
        for(int j=1;j<=g;j++){
            ll op,ops;
            cin >>op >>ops;
            vec[op].push_back({i,ops});
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            f[i][j]=2e18;
            dis[i][j]=2e18;
        }
        f[i][i]=0;dis[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        if(vec[i].size()>1){
            for(auto x:vec[i]){
                for(auto y:vec[i]){
                    if(x.id==y.id) continue;
                    f[x.id][y.id]=min(f[x.id][y.id],x.t+y.t);
                }
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            for(int k=1;k<=n;k++){
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    //for(int i=1;i<=n;i++) dij(i);
    while(q--){
        ll l,r;
        cin >>l >>r;
        ll ans=2e18;
        for(auto x:vec[l]){
            for(auto y:vec[r]){
                ans=min(ans,f[x.id][y.id]+x.t+y.t);
            }
        }
        cout <<ans+w[l]+w[r] <<'\n';
    }
    return 0;
}
