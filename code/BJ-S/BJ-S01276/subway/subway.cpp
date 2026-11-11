#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<pair<ll,ll>>g[500505];
ll w[500050],dis[500050],dp[505][505];
bool vis[500050];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    ll C,n,m,d,q;
    cin>>C>>n>>m>>d>>q;
    for(ll i=1;i<=m;i++){
        cin>>w[i];
    }
    for(ll i=1;i<=n;i++){
        ll ki;
        cin>>ki;
        for(ll j=1;j<=ki;j++){
            ll ai,ti;
            cin>>ai>>ti;
            g[ai].push_back({i+m,ti});
            // cout<<ai<<" "<<i+m<<":"<<ti<<endl;
            // cout<<i+m<<" "<<ai<<":"<<ti<<endl;
        }
    }
    memset(dp,0x3f,sizeof dp);
    for(ll i=1;i<=n;i++)dp[i][i]=0;
    for(ll i=1;i<=m;i++){
        for(auto p:g[i]){
            for(auto p2:g[i]){
                if(p==p2)continue;
                ll u=p.first-m,v=p2.first-m;
                dp[u][v]=min(dp[u][v],p.second+p2.second);
                // cout<<u<<"->"<<v<<" "<<p.second+p2.second<<endl;
            }
        }
    }
    for(ll k=1;k<=n;k++){
        for(ll i=1;i<=n;i++){
            for(ll j=1;j<=n;j++){
                dp[i][j]=min(dp[i][j],dp[i][k]+dp[k][j]);
            }
        }
    }
    // for(ll i=1;i<=n;i++){
    //     for(ll j=1;j<=n;j++){
    //         cout<<dp[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    while(q--){
        ll x,y;
        cin>>x>>y;
        ll ans=1e18;
        for(auto p:g[x]){
            for(auto p2:g[y]){
                ans=min(ans,dp[p.first-m][p2.first-m]+p.second+p2.second);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    // priority_queue<pair<ll,ll>,vector<pair<ll,ll>>,greater<pair<ll,ll>>>q;
    // q.push()
    return 0;
}