/*
*/
#include<bits/stdc++.h>
using namespace std;
int c,t;
int n,k;
bool vis[15],vis1[15];
int ans,cnt,res;
vector<int> g[15];
void dfs(int u){
    vis1[u]=1;
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(vis[v]&&!vis1[v]) dfs(v);
    }
}
void dfs1(int ed,int u,int fa,int step){
    if(u==ed){
        res=step;
        return ;
    }
    for(int i=0;i<g[u].size();i++){
        int v=g[u][i];
        if(v==fa) continue;
        dfs1(ed,v,u,step+1);
    }
}
void build(int x,int num){
    if(x>n) return ;
    if(num==k){

            cnt=0;
        for(int i=1;i<=x;i++){
            memset(vis1,0,sizeof(vis1));
            if(vis[i]&&!vis1[i]) dfs(i),cnt++;
        }
        if(cnt>2) return ;
        for(int i=1;i<=n;i++){
            res=0;
            for(int j=1;j<=x;j++){
                if(!vis[j]) continue;
                if(vis[i]&&vis[j]) continue;
                dfs1(j,i,0,0);
            }
            ans=min(ans,res);
        }
        return ;
    }
    vis[x]=1;
    build(x+1,num+1);
    vis[x]=0;
    build(x+1,num);
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    while(t--){
        memset(vis,0,sizeof(vis));
        ans=0x3f3f3f3f;
        cin>>n>>k;
        for(int i=1,u,v;i<n;i++){
            cin>>u>>v;
            g[u].push_back(v),g[v].push_back(u);
        }
        build(1,0);
        cout<<cnt<<"\n";
    }
    return 0;
}
