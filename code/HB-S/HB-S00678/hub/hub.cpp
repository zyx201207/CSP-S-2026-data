#include<bits/stdc++.h>
#define ll long long
#define pii pair<ll,ll>
#define db double
using namespace std;
const ll mx=1e6+5;
ll n,k;
vector<ll>v[mx];
bool ck(ll x){
    if(x+k/2+2*x+(k+1)/2+x>n/2)return true;
    else return false;
}
ll vis[mx],col[mx];
inline void dfs(ll x,ll cl){
    col[x]=cl;
    for(int i:v[x]){
        if(vis[i]&&!col[i])dfs(i,cl);
    }return ;
}
inline bool cek(){
    ll cnt=0;
    for(int i=1;i<=n;i++)col[i]=0;
    for(int i=1;i<=n;i++){
        if(vis[i]&&!col[i])cnt++,dfs(i,cnt);
    }return (cnt<=2);
}
ll dis[mx];
inline ll cal(){
    queue<int>q;
    for(int i=1;i<=n;i++){
        dis[i]=0;
        if(vis[i])dis[i]=1,q.push(i);
    }
    while(!q.empty()){
        ll x=q.front();q.pop();
        for(int i:v[x]){
            if(!dis[i]){
                dis[i]=dis[x]+1;
                q.push(i);
            }
        }
    }ll ms=0;
    for(int i=1;i<=n;i++)ms=max(ms,dis[i]);
    return ms-1;
}
inline void solve(){
    ll ans=1e18;
    for(int i=3;i<(1<<n);i++){
        int cnt=0;
        for(int j=1;j<=n;j++)vis[j]=0;
        for(int j=0;j<n;j++)if((1<<j)&i)cnt++,vis[j+1]=1;
        if(cnt!=k)continue;
        if(cek())ans=min(cal(),ans);
    }cout<<ans<<"\n";
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int c,T;
    cin>>c>>T;
    while(T--){
        cin>>n>>k;
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<n;i++){
            ll x,y;
            cin>>x>>y;
            v[x].push_back(y);
            v[y].push_back(x);
        }if(k==n){cout<<"0\n";continue;}
        if(c==13||c==14){
            ll l=0,r=n,ans;
            while(l<=r){
                ll mid=(l+r)>>1;
                if(ck(mid))r=mid-1,ans=mid;
                else l=mid+1;
            }cout<<ans+1<<"\n";
            continue;
        }if(c<=3){
            solve();
            continue;
        }
    }
    return 0;
}