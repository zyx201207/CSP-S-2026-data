#include <bits/stdc++.h>
using namespace std;
using std::vector;
typedef long long ll;
#define FASTIO ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
vector<vector<ll>>adj;
void add(ll u,ll v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}
ll n,d;
ll bfs(ll x){
    vector<ll>dis(n+1,1e16),cnt(n+1,1);
    vector<bool>vis(n+1,0);
    queue<ll>q;
    q.push(x);
    dis[x]=1;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(ll v:adj[u]){
            //cout<<v<<" ";
            if(dis[v]==dis[u]+1){
                ++cnt[v];
            }
            if(dis[v]>dis[u]+1){
                dis[v]=dis[u]+1;
                cnt[v]=1;
                q.push(v);
            }
        }
    }
    /*for(ll i=1;i<=n;++i){
        cout<<dis[i]<<" ";
    }
    cout<<"\n";*/
    ll ans=0;
    for(ll i=x+1;i<=n;++i){
        if(cnt[i]==2){
            ++ans;
        }
    }
    return ans;
}
void sol(){
    cin>>n>>d;
    vector<ll>a(n+1);
    adj.resize(n+1);
    for(ll i=0;i<=n;++i){
        adj[i].clear();
    }
    for(ll i=1;i<=n;++i){
        cin>>a[i];
    }
    for(ll i=1;i<=n;++i){
        for(ll j=1;j<i;++j){
            if(a[i]-a[j]<=d){
                add(i,j);
            }
        }
    }
    /*for(ll i=1;i<=n;++i){
        cout<<i<<":";
        for(ll j:adj[i]){
            cout<<j<<" ";
        }
        cout<<"\n";
    }*/
    ll ans=0;
    for(ll i=1;i<=n;++i){
        ans+=bfs(i);
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    FASTIO;
    ll c,t;
    cin>>c>>t;
    while(t--){
        sol();
    }
    return 0;
}
