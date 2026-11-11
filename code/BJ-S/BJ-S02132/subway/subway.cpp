#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct _{
    ll id;
    ll val;
};
ll c,n,m,d,q,k,ans;
ll a[500010];
ll f[510][510];
vector<_> aa[500010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    for(int i=0;i<510;i++){
        for(int j=0;j<510;j++){
            f[i][j]=1e18;
        }
    }
    for(int i=0;i<510;i++){
        f[i][i]=0;
    }
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k;
        for(int j=1;j<=k;j++){
            ll x,y;
            cin>>x>>y;
            for(auto b:aa[x]){
                f[i][b.id]=min(f[i][b.id],y+b.val);
                f[b.id][i]=min(f[b.id][i],y+b.val);
            }
            aa[x].push_back({i,y});
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(int i=1;i<=q;i++){
        int u,v;
        ans=1e18;
        cin>>u>>v;
        for(auto x:aa[u]){
            for(auto y:aa[v]){
                ans=min(ans,a[u]+a[v]+x.val+y.val+f[x.id][y.id]);
            }
        }
        cout<<ans<<"\n";
    }
    // for(int i=1;i<=n;i++){
    //     for(int j=1;j<=n;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     cout<<"\n";
    // }
    return 0;
}