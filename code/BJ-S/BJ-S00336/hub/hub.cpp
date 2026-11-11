#include<bits/stdc++.h>
using namespace std;
using ll=long long;
constexpr ll N=1e5+5,inf=1e18;
ll n,k;
vector<ll> G[N];
void init(){
    for(int i=0;i<=n+1;i++){
        G[i].clear();
    }
}
namespace cod1{
    bool lab[N],vis[N];
    ll dis[105][105];
    void init(){
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++){
                dis[i][j]=0;
            }
        }
    }
    void dfs(ll x){
        if(vis[x] || !lab[x])return;
        vis[x]=1;
        for(auto &v:G[x]){
            dfs(v);
        }
    }
    bool chklian(ll S){
        for(int i=1;i<=n;i++)lab[i]=vis[i]=0;
        for(int i=1;i<=n;i++){
            if((S>>(i-1))&1){
                lab[i]=1;
            }
        }
        ll tot=0;
        for(int i=1;i<=n;i++){
            if(lab[i] && !vis[i]){
                dfs(i);
                tot++;
            }
        }
        return (tot<=2);
    }
    void ddfs(ll x,ll f,ll st){
        for(auto &v:G[x]){
            if(v==f)continue;
            dis[st][v]=dis[st][x]+1;
            ddfs(v,x,st);
        }
    }
    ll getd(ll S){
        ll ans=0;
        for(int i=1;i<=n;i++){
            ll res=inf;
            for(int j=1;j<=n;j++){
                if((S>>(j-1))&1){
                    res=min(res,dis[i][j]);
                }
            }
            ans=max(ans,res);
        }
        return ans;
    }
    void work(){
        init();
        for(int i=1;i<=n;i++){
            ddfs(i,0,i);
        }
        ll out=inf;
        for(int S=0;S<(1<<n);S++){
            if(__builtin_popcount(S)!=k){
                continue;
            }
            if(!chklian(S))continue;
            out=min(out,getd(S));
            //cerr<<S<<" "<<out<<"\n";
        }
        cout<<out<<"\n";
    }
}
namespace cod2{
    ll m;
    bool chk(ll d){
        ll pl=d-1,pr=m-d;
        ll len=k/2;
        pl=pl+len-1,pr=pr-len+1;
        if(k&1)pl++;
        if(pl+1>=pr)return true;
        for(int i=pl+1;i<pr;i++){
            if(i-pl+1>d && pr-i+1>d)return false;
        }
        return true;
    }
    void work(){
        if(n==k){
            cout<<0<<"\n";
            //cod1::work();
            return;
        }
        m=n/2;
        if(k>=m){
            cout<<1<<"\n";
            //cod1::work();
            return;
        }
        ll l=1,r=m,ans=m;
        while(l<=r){
            ll md=(l+r)>>1;
            if(chk(md)){
                r=md-1;
                ans=md;
            }else{
                l=md+1;
            }
        }
        cout<<ans<<"\n";
        //cod1::work();
    }
}
namespace cod3{
    constexpr ll N=1005;
    ll dis[N][N];
    void init(){
        for(int i=0;i<=n+1;i++){
            for(int j=0;j<=n+1;j++){
                dis[i][j]=0;
            }
        }
    }
    void ddfs(ll x,ll f,ll st){
        for(auto &v:G[x]){
            if(v==f)continue;
            dis[st][v]=dis[st][x]+1;
            ddfs(v,x,st);
        }
    }
    ll getd(ll x,ll y){
        ll ans=0;
        for(int i=1;i<=n;i++){
            ans=max(ans,min(dis[i][x],dis[i][y]));
        }
        return ans;
    }
    void work(){
        init();
        for(int i=1;i<=n;i++){
            ddfs(i,0,i);
        }
        ll out=inf;
        for(int i=1;i<=n;i++){
            for(int j=i+1;j<=n;j++){
                out=min(out,getd(i,j));
            }
        }
        cout<<out<<"\n";
        //cerr<<"OK";
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    ll Tid,Test;
    cin>>Tid>>Test;
    while(Test--){
        cin>>n>>k;
        init();
        for(int i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            G[x].push_back(y);
            G[y].push_back(x);
        }
        if(Tid<=3){
            cod1::work();
        }else if(Tid>=13 && Tid<=14){
            cod2::work();
        }else if(Tid<=6 && Tid>=4){
            cod1::work();
        }else if(Tid<=8 && Tid>=7){
            cod3::work();
        }else{
            cod2::work();
        }
    }
    return 0;
}