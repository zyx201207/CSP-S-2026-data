#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll MAXN=1e6+16;
ll testid,_,n,k,u,v,cnt,ans;
ll dist[MAXN];
bool can[MAXN],vis[MAXN];
vector<ll> adj[MAXN];
void dfs(const ll &u){
    vis[u]=true;
    for(auto &i:adj[u]){
        if(vis[i]) continue;
        if(!can[i]) continue;
        dfs(i);
    }
    return;
}
void dfs2(const ll &u){
    for(auto &i:adj[u]){
        if(vis[i]) continue;
        dist[i]=dist[u]+1;
        vis[i]=true;
        dfs2(i);
    }
    return;
}
ll check(){
    ll r,cnt=0,res=0;
    for(ll i=1;i<=n;i++) vis[i]=false;
    for(ll i=1;i<=n;i++){
        if(can[i]&&!vis[i]){
            dfs(i);
            cnt++;
            if(cnt>2) return 1e18;
        }
    }
    // cout<<"DEBUG";
    for(ll i=1;i<=n;i++){
        for(ll j=1;j<=n;j++) vis[j]=false;
        for(ll j=1;j<=n;j++) dist[j]=0;
        vis[i]=true;
        dfs2(i);
        r=1e18;
        for(ll j=1;j<=n;j++) if(can[j]) r=min(dist[j],r);
        res=max(r,res);
    }
    return res;
}
void solve1(){
    ans=1e18;
    cin>>n>>k;
    for(ll i=1;i<=n;i++) adj[i].clear();
    for(ll i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=0;i<1ll<<n;i++){
        cnt=0;
        for(ll j=0;j<n;j++){
            if(i>>j&1) can[j+1]=true,cnt++;
            else can[j+1]=false;
        }
        if(cnt!=k) continue;
        // cout<<cnt<<' ';
        ans=min(check(),ans);
    }
    cout<<ans<<'\n';
    return;
}
void solve2(){
    ans=1e18;
    cin>>n>>k;
    for(ll i=1;i<=n;i++) adj[i].clear();
    for(ll i=1;i<n;i++){
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    for(ll i=1;i<=n;i++){
        can[i]=true;
        for(ll j=i+1;j<=n;j++){
            can[j]=true;
            ans=min(check(),ans);
            can[j]=false;
        }
        can[i]=false;
    }
    cout<<ans<<'\n';
    return;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>testid>>_;
    while(_--){
        if(testid==7) solve2();
        else solve1();
    }
    return 0;
}