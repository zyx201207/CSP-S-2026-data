#include<bits/stdc++.h>
#define int long long
using namespace std;
inline int read(){
    register int x=0;
    char c=getchar();
    while(!isdigit(c)) c=getchar();
    while(isdigit(c)) x=x*10+c-48,c=getchar();
    return x;
}
const int N=500001;
int c,n,m,d,q;
int w[N];
struct edge{
    int to,next,dis;
}e[N*3];
int tot,head[N*3];
void add(int from,int to,int dis){
    e[++tot].to=to;
    e[tot].dis=dis;
    e[tot].next=head[from];
    head[from]=tot;
}
int vis[N],f[N];
/*
struct node{
    int dis,id;
    node(int a,int b) {id=a;dis=b;}
};*/
void spfa(int s){
    memset(vis,0,sizeof(vis));
    memset(f,0x7f,sizeof(f));
    f[s]=0;vis[s]=1;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int now=q.front();
        q.pop();
        vis[now]=0;
        for(int i=head[now];i;i=e[i].next){
            int to=e[i].to,dis=e[i].dis;
            if(f[now]+dis<f[to]){
                f[to]=f[now]+dis;
                if(vis[to]==0){
                    q.push(to);
                    vis[to]=1;
                }
            }
        }
    }
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++){
        int k=read();
        for(int j=1;j<=k;j++){
            int a=read(),t=read();
            add(a,m+i,t);
            add(m+i,a,t);
        }
    }
    while(q--){
        int x=read(),y=read();
        spfa(x);
        printf("%lld\n",w[x]+w[y]+f[y]);
    }
    return 0;
}
