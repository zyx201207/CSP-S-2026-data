#include <bits/stdc++.h>
#define int long long
using namespace std;
int n,k;
vector<int> g[500005];
int f[500005][21];
int dep[500005];
void dfs(int u,int fa,bool flg=0){
    dep[u]=dep[fa]+1;
    if(!flg){
        f[u][0]=fa;
        for(int i=1;i<=20;i++){
            f[u][i]=f[f[u][i-1]][i-1];
        }
    }
    for(auto v : g[u]){
        if(v==fa){
            continue;
        }
        dfs(v,u);
    }
}
int lca(int u,int v){
    if(dep[u]<dep[v]){
        swap(u,v);
    }
    for(int i=20;i>=0;i--){
        if(dep[f[u][i]]>=dep[v]){
            u=f[u][i];
        }
    }
    if(u==v){
        return u;
    }
    for(int i=20;i>=0;i--){
        if(f[u][i]!=f[v][i]){
            u=f[u][i];
            v=f[u][i];
        }
    }
    return f[u][0];
}
int dis(int u,int v){
    return dep[u]+dep[v]-2*dep[lca(u,v)];
}
int ans=1e9;
bool vis[500005];
bool viss[500005];
bool check(const vector<int> &v){
    for(int i=1;i<=n;i++){
        vis[i]=0;
        viss[i]=0;
    }
    for(auto i : v){
        viss[i]=1;
    }
    int cnt=0;
    for(auto i : v){
        if(vis[i]){
            continue;
        }
        cnt++;
        if(cnt>2){
            return 0;
        }
        queue<int> q;
        q.push(i);
        vis[i]=1;
        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(auto v : g[u]){
                if(viss[v] && !vis[v]){
                    vis[v]=1;
                    q.push(v);
                }
            }
        }
    }
    return 1;
}
void dfsw(int i,int cnt,vector<int> v){
    if(i>n){
        if(cnt!=k){
            return ;
        }
        if(!check(v)){
            return ;
        }
        int res=0;
        for(int i=1;i<=n;i++){
            int tmp=1e9;
            for(int j : v){
                tmp=min(tmp,dis(i,j));
                // cout<<i<<" "<<j<<" "<<lca(i,j)<<" "<<dis(i,j)<<endl;
            }
            res=max(res,tmp);
        }
        ans=min(ans,res);
        return ;
    }
    dfsw(i+1,cnt,v);
    v.push_back(i);
    dfsw(i+1,cnt+1,v);
}
int work1(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dep[i]=0;
        g[i].clear();
        for(int j=0;j<=20;j++){
            f[i][j]=0;
        }
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    ans=1e9;
    dfs(1,0);
    // cout<<lca(1,2)<<endl;
    dfsw(1,0,{});
    cout<<ans<<endl;
    return 0;
}
int work2(){
    cin>>n>>k;
    for(int i=1;i<=n;i++){
        dep[i]=0;
        g[i].clear();
        for(int j=0;j<=20;j++){
            f[i][j]=0;
        }
    }
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(1,0,1);
    int maxp=1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[maxp]){
            maxp=i;
        }
    }
    dfs(maxp,0,1);
    maxp=1;
    for(int i=2;i<=n;i++){
        if(dep[i]>dep[maxp]){
            maxp=i;
        }
    }
    // cout<<dep[maxp]<<endl;
    cout<<(dep[maxp]+2)/3-1<<endl;
    return 0;
}
signed main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(0){
        while(t--){
            work2();
        }
    }else{
        while(t--){
            work1();
        }
    }
    return 0;
}
//15(don't know how to do k=2,and O(nk))
//100+100+48+15=263?    :(