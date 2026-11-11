#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=505,M=5e5+5;
ll c,n,m,d,q,b[M],f[N][N];
vector<array<ll,2>> a[M];
void solve(){
    cin>>c>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>b[i];
    }
    for(ll i=1,k,x,y;i<=n;i++){
        cin>>k;
        for(ll j=1;j<=k;j++){
            cin>>x>>y;
            a[x].push_back({i,y});
        }
    }
    memset(f,0x3f,sizeof(f));
    for(ll i=1;i<=n;i++) f[i][i]=0;
    for(ll i=1;i<=m;i++){
        for(auto [u,wu]:a[i]){
            for(auto [v,wv]:a[i]){
                f[u][v]=min(f[u][v],wu+wv);
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                f[i][j]=min(f[i][j],f[i][k]+f[k][j]);
            }
        }
    }
    for(ll i=1,x,y;i<=q;i++){
        cin>>x>>y;
        ll ans=1e18;
        for(auto [u,wu]:a[x]){
            for(auto [v,wv]:a[y]){
                ans=min(ans,b[x]+wu+f[u][v]+wv+b[y]);
            }
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
