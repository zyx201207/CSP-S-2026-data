#include <bits/stdc++.h>
using namespace std;
const int N=2005;
vector<int>g[N];
int dis[N];
int n,k;

int bfs(int s) {
    memset(dis,-1,sizeof dis);
    queue<int>q;q.push(s); dis[s]=0;
    int mx=0;
    while(!q.empty()){
        int u=q.front();q.pop();
        mx=max(mx,dis[u]);
        for(int v:g[u]) if(dis[v]==-1){
            dis[v]=dis[u]+1;
            q.push(v);
        }
    }
    return mx;
}
bool check(int x){
    if(k>n) return false;
    for(int i=1;i<=n;i++){
        if(bfs(i)<=x) return true;
    }
    return false;
}
void solve(){
    cin>>n>>k;
    for(int i=1;i<=n;i++) g[i].clear();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int l=0,r=n,ans=n;
    while(l<=r){
        int mid=l+r>>1;
        if(check(mid)) ans=mid, r=mid-1;
        else l=mid+1;
    }
    cout<<ans<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    int c,t;cin>>c>>t;
    while(t--) solve();
    return 0;
}
