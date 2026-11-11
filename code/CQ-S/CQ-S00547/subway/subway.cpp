#include<bits/stdc++.h>
using namespace std;
namespace mycode{
    typedef long long ll;
    const ll INF=1e16;
    int c,n,m,d,q;
    ll rzk[500005];
    ll f[505][505];
    vector<pair<int,ll> > b[500005];
    void solve(){
        cin>>c>>n>>m>>d>>q;
        for(int i=1;i<=m;i++) cin>>rzk[i];
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++) f[i][j]=INF;
            f[i][i]=0;
        }
        for(int i=1,k;i<=n;i++){
            cin>>k;
            int v;ll w;
            for(int j=1;j<=k;j++){
                cin>>v>>w;
                for(auto [yv,yw]:b[v]){
                    f[yv][i]=min(f[yv][i],yw+w);
                    f[i][yv]=min(f[i][yv],yw+w);
                }
                b[v].push_back({i,w});
            }
        }
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
        for(int i=1,x,y;i<=q;i++){
            cin>>x>>y;
            ll ans=INF;
            for(auto [xv,xw]:b[x])
                for(auto [yv,yw]:b[y])
                    ans=min(ans,xw+f[xv][yv]+yw);
            printf("%lld\n",ans+rzk[x]+rzk[y]);
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    mycode::solve();
    return 0;
}