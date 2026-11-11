#include<bits/stdc++.h>
using namespace std;
int head[1000002],vis[1000002],cnt,maxn,flag,mid,mid2,xxx;
struct edge{
    int to,next;
}e[2000002];
void add(int u,int v){
    e[++cnt]={v,head[u]},head[u]=cnt;
    return ;
}
void dfs(int now,int dis,int &kayuko){
    if(dis>maxn)maxn=dis,kayuko=now;
    for(int i=head[now];i;i=e[i].next)if(!vis[e[i].to])vis[now]=1,dfs(e[i].to,dis+1,kayuko),vis[now]=0;
    return ;
}
void dfs2(int now,int dis,int kayuko){
    if(kayuko==now)--maxn,flag=1;
    for(int i=head[now];i;i=e[i].next){
        if(!vis[e[i].to])vis[now]=1,dfs(e[i].to,dis+1,kayuko),vis[now]=0;
        if(flag){
            if(maxn==0)mid=now;
            if(maxn==-1)mid2=now,xxx=i;
            --maxn;
            break;
        }
    }
    return ;
}
void dfs3(int now,int dis,int kayuko){
    if(kayuko==now)--maxn,flag=1;
    for(int i=head[now];i;i=e[i].next){
        if(!vis[e[i].to])vis[now]=1,dfs(e[i].to,dis+1,kayuko),vis[now]=0;
        if(flag){
            if(maxn==0)mid=now;
            --maxn;
            break;
        }
    }
    return ;
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,T;
    while(T--){
        mt19937 rnd;
        int n,m,u,v,aa,bb,cc,dd;
        cin>>n>>m,memset(head,0,n+1),memset(e,0,n+1),xxx=0;
        for(int i=1;i<n;i++)cin>>u>>v,add(u,v),add(v,u);
        dfs(1,0,aa),dfs(aa,0,bb),maxn>>=1;
        if(m==1){
            cout<<maxn<<'\n';
            continue;
        }
        cout<<1<<'\n';
        // dfs2(aa,0,bb),maxn=0;
        // dfs(mid,0,aa),dfs(aa,0,bb),maxn>>=1,dfs3(aa,0,bb),maxn=0;
        // dfs(mid2,0,cc),dfs(cc,0,dd),maxn>>=1,dfs3(cc,0,dd),maxn=0;
    }
    return ( 0 - 0 );
}
//QAQ (ku ku nao nao)