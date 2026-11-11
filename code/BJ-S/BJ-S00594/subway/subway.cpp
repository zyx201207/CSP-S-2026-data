#include<bits/stdc++.h>
#define ll unsigned long long
#define pll pair<ll,ll>
using namespace std;
const ll db=0;
const ll inf=1e18;
void solve(ll c,ll n,ll m,ll d,ll q,vector<ll>&w,vector<ll>&k,vector<vector<ll>>&a,vector<vector<ll>>&t,vector<ll>&x,vector<ll>&y){
    vector<vector<pll>>tr(m+n+1);
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=k[i];j++){
            tr[a[i][j]].push_back({m+i,t[i][j]});
            tr[m+i].push_back({a[i][j],t[i][j]});
        }
    }
    vector<vector<ll>>vis(n+1,vector<ll>(m+n+1,inf));
    auto dijk=[&](ll st){
        priority_queue<pll,vector<pll>,greater<pll>>q;
        q.push({0,st});vis[st-m][st]=0;
        while(!q.empty()){
            ll u=q.top().second,r=q.top().first;
            q.pop();
            if(vis[st-m][u]<r)continue;
            for(auto v:tr[u]){
                if(vis[st-m][v.first]<=r+v.second)continue;
                vis[st-m][v.first]=r+v.second;
                q.push({r+v.second,v.first});
            }
        }
    };
    for(ll i=m+1;i<=m+n;i++)dijk(i);
    for(ll i=1;i<=q;i++){
        ll ans=inf;
        for(ll j=1;j<=n;j++){
            ans=min(ans,vis[j][x[i]]+vis[j][y[i]]+w[x[i]]+w[y[i]]);
        }
        cout<<ans<<"\n";
    }
}
int main(){
    freopen("subway5.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll c,n,m,d,q;cin>>c>>n>>m>>d>>q;
    if(db&2)printf(":c=%lld:n=%lld:m=%lld:d=%lld:q=%lld\n",c,n,m,d,q);
    vector<ll>w(m+1),k(n+1);
    vector<vector<ll>>a(n+1,vector<ll>(1)),t(n+1,vector<ll>(1));
    for(ll i=1;i<=m;i++)cin>>w[i];
    for(ll i=1;i<=n;i++){
        cin>>k[i];
        for(ll j=1;j<=k[i];j++){
            ll ja,jt;cin>>ja>>jt;
            a[i].push_back(ja);
            t[i].push_back(jt);
        }
    }
    vector<ll>x(q+1),y(q+1);
    for(ll i=1;i<=q;i++)cin>>x[i]>>y[i];
    solve(c,n,m,d,q,w,k,a,t,x,y);
    return 0;
}
