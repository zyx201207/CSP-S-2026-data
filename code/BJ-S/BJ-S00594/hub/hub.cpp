#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll,ll>
using namespace std;
const ll db=0;
const ll inf=1e18;
struct bcj{
    ll n;
    vector<ll>f;
    bcj(ll nn):n(nn),f(nn+1){for(ll i=1;i<=nn;i++)f[i]=i;}
    ll fd(ll x){
        if(f[x]==x)return x;
        return f[x]=fd(f[x]);
    }
    bool mg(ll a,ll b){
        a=fd(a);b=fd(b);
        if(a==b)return 0;
        f[a]=f[b];
        return 1;
    }
};
void solve(ll n,ll k,vector<ll>&u,vector<ll>&v){
    vector<vector<ll>>tr(n+1);
    for(ll i=1;i<n;i++){
        tr[u[i]].push_back(v[i]);
        tr[v[i]].push_back(u[i]);
    }
    vector<ll>h(n+1);
    auto check=[&](){
        bcj bj(n+1);
        for(ll i=1;i<n;i++){
            if(h[u[i]]&&h[v[i]]){
                bj.mg(u[i],v[i]);
            }
        }
        ll ct=0;
        for(ll i=1;i<=n;i++)if(h[i]&&bj.fd(i)==i)ct++;
        if(ct>2)return inf;
        vector<ll>vis(n+1);
        auto bfs=[&](ll st){
            queue<ll>q;
            q.push(st);
            while(!q.empty()){
                ll u=q.front();q.pop();
                if(db&4)printf(":u=%lld:v=%lld\n",u,vis[u]);
                for(auto v:tr[u]){
                    if(vis[v])continue;
                    vis[v]=vis[u]+1;
                    q.push(v);
                }
            }
        };
        ll maxx=0;
        for(ll i=1;i<=n;i++){
            if(h[i])continue;
            for(ll i=1;i<=n;i++)vis[i]=0;
            bfs(i);
            ll minn=inf;
            for(ll j=1;j<=n;j++){
                if(h[j])minn=min(minn,vis[j]);
                if(db&2&&h[j])printf(":i=%lld:j=%lld:h=%lld:minn=%lld:vis=%lld\n",i,j,h[j],minn,vis[i]);
            }
            maxx=max(maxx,minn);
            if(db&4)printf(":i=%lld:max=%lld:min=%lld:k=%lld\n",i,maxx,minn,k);
        }
        return maxx;
    };
    ll ans=inf;
    for(ll v=0;v<(1<<n);v++){
        for(ll i=1;i<=n;i++)h[i]=0;
        ll ct=0;
        for(ll i=0;i<n;i++){
            if(v&(1<<i))h[i+1]=1,ct++;
        }
        if(ct!=k)continue;
        ll cv=check();
        if(db&2)printf(":v=%lld:ct=%lld:cv=%lld\n",v,ct,cv);
        ans=min(ans,cv);
    }
    cout<<ans<<"\n";
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0);
    ll c,t;cin>>c>>t;
    while(t--){
        ll n,k;cin>>n>>k;
        vector<ll>u(n),v(n);
        for(ll i=1;i<n;i++)cin>>u[i]>>v[i];
        solve(n,k,u,v);
    }

    return 0;
}
