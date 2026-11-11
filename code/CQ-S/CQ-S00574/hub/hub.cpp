#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int N=1e6+50;
int c,T,n,k,ans=inf;
int col[N],mn[N],dis[N];
vector<int> vec[N];
bool vis[N];
void bfs(int s){
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:vec[u]){
            if(col[v]!=1 || vis[v])continue;
            vis[v]=1;
            q.push(v);
        }
    }
}
void GetAns(int s){
    for(int i=1;i<=n;i++)dis[i]=-1;
    dis[s]=0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int u=q.front();q.pop();
        for(int v:vec[u]){
            if(dis[v]==-1){
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
}
void check(){
    for(int i=1;i<=n;i++)vis[i]=0;
    int B=0;
    for(int i=1;i<=n;i++){
        if(col[i]==1 && !vis[i]){
            bfs(i);
            B++;
        }
    }
    if(B>2)return ;
    for(int i=1;i<=n;i++)mn[i]=inf;
    for(int i=1;i<=n;i++){
        if(col[i]==1){
            GetAns(i);
            for(int j=1;j<=n;j++)mn[j]=min(mn[j],dis[j]);
        }
    }
    int ret=0;
    for(int i=1;i<=n;i++)ret=max(ret,mn[i]);
    ans=min(ans,ret);
}
void dfs(int dep,int num){
    if(dep>n){
        if(num==k)check();
        return ;
    }
    if(n-dep+1+num<k)return ;
    col[dep]=0;
    dfs(dep+1,num);
    if(num<k){
        col[dep]=1;
        dfs(dep+1,num+1);
        col[dep]=0;
    }
}
void init(){
    for(int i=1;i<=n;i++)vec[i].clear();
    ans=inf;
}
void solve(){
    cin>>n>>k;
    init();
    for(int i=1,u,v;i<n;i++){
        cin>>u>>v;
        vec[u].push_back(v);
        vec[v].push_back(u);
    }
    dfs(1,0);
    cout<<ans<<'\n';
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>T;
    while(T--){
        solve();
    }
    return 0;
}
/*
0 2
5 2
1 2
2 3
3 4
4 5
10 3
1 2
1 3
2 4
2 5
3 6
3 7
3 8
7 9
9 10
*/