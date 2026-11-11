#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll w[50005],f[505][505];
vector<pri<ll,ll> >,a[505],b[50005];
int main(){
    freopen("subway.in","r".stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,q,ans=1e18;
    cin>>c>>n>>m>>q;
    
    for(ll i=1;i<=m;i++) cin>>w[i];
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=m;j++){
            if(i==j) f[i][j]=0;
            else f[i][j]=1e18;
        }
    }
    for(ll i=1;i<=n;i++){
        ll k;cin>>k;
        for(ll j=1;j<=k;j++){
            ll t,x;
            cin>>t>>x;
            a[i].push_back{(t,x)};
            b[i].push_back({i,x});
        }
    }
    for(ll i=1;i<=n;i++){
        for(auto u:a[i]){
            for(auto v:b[u.first]){
                f[i][v.first]=min(f[i][v.first],u.second+v.second);
            }
        }
    }
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++){
            for(ll k=1;k<=n;k++){
                f[j][k]=min(f[j][k],f[j][i]+f[i][k]);
            }
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        for(auto i:b[x]){
            for(auto j:b[y]){
                ans=min(f[i.first][j.first]+i.second+j.second,ans);
            }
        }
        ans+=w[x]+w[y];
        cout<<ans<<"\n";
    }
 //   cout<<ans;
    return 0;
}
