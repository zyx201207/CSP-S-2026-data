#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll db=0;
const ll inf=1e18;
void solve(ll n,ll d,vector<ll>&x,ll f){
    ll ans=0,lw=n+1;
    auto bfs=[&](ll st){
        vector<ll>vis(n+1,inf),ct(n+1);
        queue<pll>q;vis[st]=0;
        q.push({st,0});
        while(!q.empty()){
            ll u=q.front().first,t=q.front().second;
            q.pop();
            if(vis[u]<t)continue;
            ct[u]++;
            for(ll i=u-1;i>=1&&x[u]-x[i]<=d;i--){
                if(vis[i]<t+1)continue;
                vis[i]=t+1;
                q.push({i,t+1});
            }
        }
        ll g=0;
        for(ll i=1;i<=n;i++)if(ct[i]==2)g++,lw=min(lw,i);
        ans+=g;
    };
    if(!f)for(ll i=n;i>=1;i--)bfs(i);
    else{
        bfs(n);
        ll v=ans;
        if(lw<=n)
            for(ll i=n-1;i>=(n-lw+1);i--)ans+=v;
    }
    cout<<ans<<"\n";
}
void solve2(ll n,ll d,vector<ll>&x){
    ll ans=0;
    for(ll i=n;i>=1;i--){
        ll w=i,v=0;
        for(ll j=1;w>=x[1];j++){
            ll nw=lower_bound(x.begin()+1,x.end(),x[w]-d)-x.begin();
            if(w<n){
                ll lw=lower_bound(x.begin()+1,x.end(),x[w+1]-d)-x.begin();
                if(lw>w)v+=lw-w;
            }
            w=nw;
            if(w==nw)break;
        }
        ans+=v;
        if(v<=0)break;
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll c,t;cin>>c>>t;
    while(t--){
        ll n,d;cin>>n>>d;
        vector<ll>x(n+5);
        for(ll i=1;i<=n;i++)cin>>x[i];
        ll gc=x[2]-x[1],f=1;
        for(ll i=3;i<=n;i++){
            if(x[i]-x[i-1]!=gc)f=0;
        }
        if(db&2)printf(":f=%lld\n",f);
        if(n<=5000||f)solve(n,d,x,f);
        else{
            solve2(n,d,x);
        }
    }

    return 0;
}
