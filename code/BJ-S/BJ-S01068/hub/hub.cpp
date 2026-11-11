#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,k,vis[15],num,dis[15];
vector<ll> adj[15];
bool check(){
    ll cnt[15]={};
    queue<ll> q;
    q.push(1);
    cnt[1]=1;
    ll p=0;
    while(!q.empty()){

        ll u=q.front();//cout<<u<<" ";
        q.pop();
        ll h=0;
        for(int i=0;i<adj[u].size();i++){
            ll v=adj[u][i];
            if(cnt[v]) continue;
            if(!vis[v]) h++;
            q.push(v);
            cnt[v]=1;
            if(!vis[u]&&vis[v]) p++;
        }
        if(h==adj[u].size()&&u==1) p++;
    }
    return p<=2;
}
void dfs(ll u,ll f){
    for(int i=0;i<adj[u].size();i++){
        ll v=adj[u][i];
        if(v==f) continue;
        dis[v]=dis[u]+1;
        dfs(v,u);
    }
}
bool checkk(){
    ll cnt[15]={};
    queue<ll> q;
    q.push(1);
    cnt[1]=1;
    ll p=0;
    while(!q.empty()){

        ll u=q.front();cout<<u<<" ";
        q.pop();
        ll h=0;
        for(int i=0;i<adj[u].size();i++){
            ll v=adj[u][i];
            if(cnt[v]) continue;
            if(!vis[v]) h++;
            q.push(v);
            cnt[v]=1;
            if(!vis[u]&&vis[v]) p++;
        }
        if(h==adj[u].size()&&u==1) p++;
    }
    cout<<p<<" \n";
    return p<=2;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll T;
    cin>>T>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++) adj[i].clear();
        for(int i=1;i<=n-1;i++){
            ll u,v;
            cin>>u>>v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        ll ans=1e9;
        for(int mask=0;mask<(1ll<<n);mask++){
            ll kkk=0;
            memset(vis,0,sizeof vis);
            for(int j=0;j<n;j++){
                if(((1ll<<j)&mask)){
                    vis[j+1]=1;
                    kkk++;
                }
            }
            if(kkk!=k) continue;
            if(!check()) continue;
            ll res=-1;
            for(int i=1;i<=n;i++){
                num=1e9;
                memset(dis,0,sizeof dis);
                dfs(i,0);
                for(int j=1;j<=n;j++) if(vis[j]) num=min(num,dis[j]);
                res=max(res,num);
            }
            ans=min(ans,res);
            //if(res!=1) continue;
            //checkk();
            //cout<<k<<" "<<res<<endl;
            //for(int i=1;i<=n;i++) cout<<vis[i]<<" ";
            //cout<<endl;
        }
        cout<<ans<<endl;
    }
    return 0;
}
