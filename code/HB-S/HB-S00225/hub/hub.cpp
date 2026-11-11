#include<bits/stdc++.h>
using namespace std;
const int N=1e6+55;
int c,t,n,k,U[N],V[N],dis[N],X,Y;
int use[N],ans=0x3f3f3f3f,fa[N];
bool vis[N];
int find(int u){
    if(fa[u]==u) return u;
    return fa[u]=find(fa[u]);
}
vector<int> ed[N];
queue<int> q;
void dfs(int t,int sum){
    if(t>n){
        if(sum!=k) return;
        int cnt=k;
        for(int i=1;i<=n;i++) fa[i]=i;
        for(int i=1;i<n;i++){
            if(use[U[i]]&&use[V[i]]){
                int fu=find(U[i]);
                int fv=find(V[i]);
                if(fu!=fv) fa[fu]=fv,cnt--;
            }
        }
        if(cnt>2) return;
        for(int i=1;i<=n;i++){
            vis[i]=0,dis[i]=0x3f3f3f3f;
        }
        for(int i=1;i<=n;i++){
            if(use[i]){
                q.push(i);
                vis[i]=1;
                dis[i]=0;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:ed[u]){
                if(vis[v]) continue;
                dis[v]=dis[u]+1;
                vis[v]=1;
                q.push(v);
            }
        }
        int mx=0;
        for(int i=1;i<=n;i++){
            mx=max(mx,dis[i]);
        }
        ans=min(ans,mx);
        return ;
    }
    use[t]=1;
    dfs(t+1,sum+1);
    use[t]=0;
    dfs(t+1,sum);
}
void Dfs(int u,int fa){
    for(int v:ed[u]){
        if(v==fa) continue;
        dis[v]=dis[u]+1;
        Dfs(v,u);
    }
}
void solve(){
    ans=0x3f3f3f3f;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        int len=ed[i].size();
        for(int j=0;j<len;j++){
            ed[i].pop_back();
        }
    }
    for(int i=1;i<n;i++){
        cin>>U[i]>>V[i];
        ed[U[i]].push_back(V[i]);
        ed[V[i]].push_back(U[i]);
    }
    if(k==1){
        for(int i=1;i<=n;i++){
            vis[i]=0,dis[i]=0x3f3f3f3f;
        }
        for(int i=1;i<=n;i++){
            int deeg=ed[i].size();
            if(deeg==1){
                q.push(i);
                vis[i]=1;
                dis[i]=0;
            }
        }
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int v:ed[u]){
                if(vis[v]) continue;
                dis[v]=dis[u]+1;
                vis[v]=1;
                q.push(v);
            }
        }
        int id=0,mx=0;
        for(int i=1;i<=n;i++){
            if(mx<dis[i]){
                id=i,mx=dis[i];
            }
        }
        cout<<mx<<'\n';
        return ;
    }
    dfs(1,0);
    cout<<ans<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>t;
    while(t--){
        solve();
    }
    return 0;
}
