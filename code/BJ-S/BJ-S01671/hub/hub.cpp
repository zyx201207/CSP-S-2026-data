#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int c,T;
int n,k;
vector<int> g[20];
int vis[20];
int ans=0x3f3f3f3f;
void ckdfs(int x,int f){
    vis[x]=0;
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]==f){
            continue;
        }
        if(vis[g[x][i]]==1){
            ckdfs(g[x][i],x);
        }
    }
}
bool check(int ch){
    memset(vis,0,sizeof vis);
    for(int i=1;i<=n;i++){
        vis[i]=(ch&1);
        ch>>=1;
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(vis[i]==1){
            ckdfs(i,0);
            cnt++;
        }
    }
    if(cnt==2){
        return true;
    }
    return false;
}
int dfs(int x,int f){
    if(vis[x]==1){
        return 0;
    }
    int ret=0x3f3f3f3f;
    for(int i=0;i<g[x].size();i++){
        if(g[x][i]==f){
            continue;
        }
        ret=min(dfs(g[x][i],x)+1,ret);
    }
    return ret;
}
void cho(int x,int cnt,int lcho){
    if(x==n+1){
        if(cnt==k&&check(lcho)){
            int ch=lcho;
            for(int i=1;i<=n;i++){
                vis[i]=(ch&1);
                ch>>=1;
            }
            int mx=-1;
            for(int i=1;i<=n;i++){
                int dis=dfs(i,0);
                mx=max(dis,mx);
            }
            ans=min(ans,mx);
        }
        return;
    }
    cho(x+1,k+1,lcho|(1<<(x-1)));
    cho(x+1,k,lcho);
}
void run(){
    memset(vis,0,sizeof vis);
    ans=0x3f3f3f3f;
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        g[i].clear();
    }
    for(int i=1;i<=n-1;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    cho(1,0,0);
    cout<<ans<<endl;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        run();
    }
    return 0;
}
