#include<bits/stdc++.h>
using namespace std;
#define pb push_back
typedef long long ll;
const ll N=1e6;
vector<ll> g[N+5];
bool flag[N+5];
ll dis[N+5];
void dfs(ll x,const ll mask){
    flag[x]=1;
    for(auto it:g[x]){
        if(flag[it]) continue;
        if(mask&(1<<(it-1))){
            dfs(it,mask);
        }
    }
    return ;
}
void dfs2(ll x){
    flag[x]=1;
    for(auto it:g[x]){
        if(flag[it]) continue;
        dis[it]=min(dis[it],dis[x]+1);
        dfs2(it);
    }
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll c,T;
    cin>>c>>T;
    while(T--){
        ll n,k;
        cin>>n>>k;
        for(ll i=0;i<=n;i++) g[i].clear();
        for(ll u,v,i=1;i<n;i++){
            cin>>u>>v;
            g[u].pb(v);
            g[v].pb(u);
        }
        ll ans=1e9;
        for(ll mask=3;mask<(1<<n);mask++){
            ll cnt=0;
            for(ll i=0;i<n;i++) if((mask&(1<<i))) cnt++;
            if(cnt!=k) continue;
            for(ll i=0;i<=n;i++) flag[i]=0,dis[i]=1e9;
            cnt=0;
            for(ll i=0;i<n;i++){
                if((mask&(1<<i))){
                    if(!flag[i+1]){
                        dfs(i+1,mask);
                        cnt++;
                    }
                }
            }
            if(cnt>2) continue;
            for(ll i=0;i<n;i++){
                if((mask&(1<<i))){
                    dis[i+1]=0;
                }
            }
            for(ll i=0;i<n;i++){
                if((mask&(1<<i))){
                    for(ll i=0;i<=n;i++) flag[i]=0;
                    dfs2(i+1);
                }
            }
            ll tmp=0;
            for(ll i=1;i<=n;i++){
                tmp=max(tmp,dis[i]);
            }
            ans=min(ans,tmp);
        }
        cout<<ans<<'\n';
    }
    return 0;
}
