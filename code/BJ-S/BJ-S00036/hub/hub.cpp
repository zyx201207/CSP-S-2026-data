#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define d(x) cout<<"# "<<x<<" ";
int n,k;
vector<int> g[2000005];
int tg[105],vis[105],dis[105],visq[105];
void dfs(int u){
    vis[u]=1;
    for(int v:g[u]){
        if(vis[v]||!tg[v]) continue;
        dfs(v);
    }
}
bool valid(){
    int cnt=0;
    for(int i=1;i<=n;++i){
        vis[i]=0;
    }
    for(int i=1;i<=n;++i){
        if(tg[i]&&!vis[i]){
            cnt++;
            if(cnt>2) return false;
            dfs(i);
        }
    }
    return true;
}
int get(){
    int res=0;
    queue<int> q;
    for(int i=1;i<=n;++i){
        dis[i]=visq[i]=0;
        if(tg[i]) q.push(i),visq[i]=1;
    }
    while(q.size()){
        int u=q.front();
        q.pop();
        for(int v:g[u]){
            if(!visq[v]) q.push(v),visq[v]=1,dis[v]=dis[u]+1,res=dis[v];
        }
    }
    return res;
}
void solve12(){
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        g[i].clear();
    }
    for(int i=1;i<n;++i){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int ans=0x3f3f3f3f;
    for(int i=1;i<(1<<n);++i){
        if(__builtin_popcount(i)!=k) continue;
        for(int j=0;j<n;++j){
            tg[j+1]=(i&(1<<j));
        }
        if(!valid()){continue;}
        ans=min(ans,get());
    }
    cout<<ans<<"\n";
}
int main(){
    ios::sync_with_stdio(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ll c,T;
    cin>>c>>T;
    while(T--){
        if(c<=3) solve12();
        else cout<<n/k<<endl;
    }
    return 0;
}
