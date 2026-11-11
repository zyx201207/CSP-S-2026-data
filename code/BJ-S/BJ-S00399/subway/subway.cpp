#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll inf=1ll<<60;
#define pii pair<ll,ll>
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ll c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    ll dp[n+1][n+1];
    memset(dp,0x3f,sizeof(dp));
    ll w[m+1];
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    vector<ll> a[n+1];
    vector<ll> t[n+1];
    vector<pii> subs[m+1];
    ll k[n+1];
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            ll ta,tt;
            cin>>ta>>tt;
            subs[ta].push_back({i,tt});
            a[i].push_back(ta);
            t[i].push_back(tt);
        }
    }
    //edge val here
    for(int i=1;i<=n;i++){
        for(int j=1;j<=k[i];j++){
                for(pii p:subs[a[i][j]]){
                    if(p.first==i){
                        dp[i][p.first]=dp[p.first][i]=0;
                        continue;
                    }
                    dp[i][p.first]=dp[p.first][i]=t[i][j]+p.second;
                }
        }
    }
    //floyd here
    for(int T=1;T<=n;T++){
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][T]+dp[T][j]);
            }
        }
    }
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=inf;
        for(pii p1:subs[x])
            for(pii p2:subs[y])ans=min(ans,dp[p1.first][p2.first]+p1.second+p2.second+w[x]+w[y]);
        cout<<ans<<"\n";
    }
    return 0;
}
