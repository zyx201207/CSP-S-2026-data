#include<bits/stdc++.h>
using namespace std;
using ll = long long;
vector<ll> g[1000005];
bool vis[1000005];
bool dis[1000005];
ll d[1000005];
void bfs(ll x){
    queue<ll> q;
    q.push(x);
    dis[x]=1;
    while(!q.empty()){
        ll u=q.front();
        q.pop();
        for (const auto &v:g[u]){
            if(dis[v]){
                continue;
            }
            if(vis[v]){
                q.push(v);
                dis[v]=1;
            }
        }
    }
}
#define lb(x) (x&(-x))
int main(){
    ios::sync_with_stdio(0),cin.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c,_;
    cin>>c>>_;
    while(_--){
        ll n,k;
        cin>>n>>k;
        for (int i=1;i<n;i++){
            ll u,v;
            cin>>u>>v;
            u--,v--;
            g[u].push_back(v);
            g[v].push_back(u);
        }
        ll all=(1<<n);
        ll ans=1e18;
        for (int S=0;S<all;S++){
            ll t=S;
            ll cnt=0;
            while(t){
                t-=lb(t);
                cnt++;
            }
            if(cnt!=k){
                continue;
            }
            for (int i=0;i<n;i++){
                vis[i]=0;
                d[i]=1e18;
                dis[i]=0;
                if(S>>i&1){
                    vis[i]=1;
                }
            }
            cnt=0;
            for (int i=0;i<n;i++){
                if(!dis[i]&&vis[i]){
                    bfs(i);
                    cnt++;
                }
            }
            if(cnt==0||cnt>2){
                continue;
            }
            queue<ll> q;
            for (int i=0;i<n;i++){
                if(vis[i]){
                    q.push(i);
                    d[i]=0;
                }
            }
            while(!q.empty()){
                ll u=q.front();
                q.pop();
                for (const auto &v:g[u]){
                    if(d[v]>d[u]+1){
                        d[v]=d[u]+1;
                        q.push(v);
                    }
                }
            }
            ll mx=0;
            for (int i=0;i<n;i++){
                mx=max(mx,d[i]);
            }
            ans=min(ans,mx);
        }
        cout<<ans<<"\n";
    }
    return 0;
}