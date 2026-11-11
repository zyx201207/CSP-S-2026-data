// Wyh is extremely cute
// I love Wyh
#include<bits/stdc++.h>
#define int long long 
using namespace std;

const int maxn=1e6+10;
const int inf=1e18;
int c,t,n,k,cnt,ans=inf;
int head[maxn];
bool is[maxn],vis[maxn];
int dis[maxn];
struct edge{
    int v,nxt;
}e[maxn<<1];
queue<int>q;
inline void add(int u,int v){
    e[++cnt].v=v;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
inline void ipt(){
    cnt=0,ans=inf;
    scanf("%lld%lld",&n,&k);
    for(int i=1;i<=n;i++)head[i]=0;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        add(u,v);
        add(v,u);
    }
}
inline void bfs(int s){
    // for(int i=1;i<=n;i++)vis[i]=false;
    q.push(s);
    vis[s]=true;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(!vis[v]&&is[v]){
                vis[v]=true;
                q.push(v);
            }
        }
    }
}
inline bool check(){
    for(int i=1;i<=n;i++)vis[i]=false;
    int ct=0;
    for(int i=1;i<=n;i++){
        if(is[i]){
            if(!vis[i]){
                ++ct;
                bfs(i);
            }
        }
    }
    if(ct>2)return false;
    return true;
}
inline int get_ans(){
    for(int i=1;i<=n;i++)vis[i]=false;
    for(int i=1;i<=n;i++){
        if(is[i])dis[i]=0,q.push(i),vis[i]=true;
        else dis[i]=inf;
    }
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(!vis[v]){
                vis[v]=true;
                dis[v]=dis[u]+1;
                q.push(v);
            }
        }
    }
    int mx=-inf;
    for(int i=1;i<=n;i++)mx=max(mx,dis[i]);
    // if(mx==1){
    //     for(int i=1;i<=n;i++){
    //         if(is[i])printf("1 ");
    //         else printf("0 ");
    //     }
    //     printf("\n");
    // }
    return mx;
}
inline void solve(int i,int tot){
    if(i==n+1){
        // printf("= %lld %lld\n",i,tot);
        if(tot!=k)return ;
        if(!check())return ;
        ans=min(ans,get_ans());
        return ;
    }
    solve(i+1,tot);
    if(tot<k){
        is[i]=true;
        solve(i+1,tot+1);
        is[i]=false;
    }
}
signed main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    scanf("%lld%lld",&c,&t);
    while(t--){
        ipt();
        solve(1,0);
        printf("%lld\n",ans);
    }

    return 0;
}