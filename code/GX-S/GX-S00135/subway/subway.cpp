#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2e4+500,inf=0x3f3f3f3f;

int cnt,h[N],to[N],val[N],nxt[N];

void add(int u,int v,int w){
    to[++cnt]=v;
    val[cnt]=w;
    nxt[cnt]=h[u];
    h[u]=cnt;
}

int read(){
    int x=0,f=1;
    char c;
    c=getchar();
    while(!isdigit(c)){if(c=='-')f=-1;c=getchar();}
    while(isdigit(c)){x=x*10+c-'0';c=getchar();}
    return f*x;
}

struct node{
    int u,d;
    friend bool operator <(const node &a,const node &b){return a.d>b.d;}
}tmp;


int c,n,m,d,q,ww[N],www[500010],bel[500010];

priority_queue<node> qu;
int dis[N][N];
bool vis[N];


void dijkstra(int s){
    for(int i=1;i<=n+m;i++) {dis[s][i]=inf;vis[i]=0;}
    dis[s][s]=0;tmp.u=s,tmp.d=0;qu.push(tmp);
    while(!qu.empty()){
        //cout<<"*";
        int u=qu.top().u;
        qu.pop();
        if(vis[u]) continue;
        vis[u]=1;
        //cout<<u<<":";
        for(int i=h[u];i;i=nxt[i]){
            int v=to[i],w=val[i];
            //cout<<v<<" ";
            if(dis[s][v]>dis[s][u]+w){
                dis[s][v]=dis[s][u]+w;
                //cout<<v<<"->"<<dis[s][v]<<" ";
                tmp.u=v,tmp.d=dis[s][v];qu.push(tmp);
            }
        }
        //cout<<"\n";
    }
}


int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    if(c==20||c==21){
        for(int i=1;i<=m;i++) ww[i]=read();
        int p;
        for(int i=1;i<=n;i++){
            int k;
            k=read();
            for(int j=1;j<=k;j++){
                int a,t;
                a=read();t=read();
                if(www[a]) {p=www[a]+t;bel[a]=0;}
                else {www[a]=t;bel[a]=j;}
            }
        }
        for(int i=1;i<=q;i++){
            int x,y;
            x=read();y=read();
            if(bel[x]&&bel[y]){
                if(bel[x]!=bel[y]) cout<<ww[x]+www[x]+ww[y]+www[y]+p<<"\n";
                else cout<<ww[x]+www[x]+ww[y]+www[y]<<"\n";
            }
            else{
                if(bel[x]!=0) swap(x,y);
                if(bel[y]==1) cout<<ww[x]+www[x]+ww[y]+www[y]<<"\n";
                else if(bel[y]=2) cout<<ww[x]+p-www[x]+ww[y]+www[y]<<"\n";
            }
        }
    }
    else{
        for(int i=1;i<=m;i++) ww[i]=read();
        for(int i=1;i<=n;i++){
            int k;
            k=read();
            for(int j=1;j<=k;j++){
                int a,t;
                a=read();t=read();
                add(i,a+n,t);
                add(a+n,i,t);
            }
        }
        for(int i=1;i<=m;i++){
            dijkstra(i+n);
            //cout<<"\n";
        }
        for(int i=1;i<=q;i++){
            int x,y;
            x=read();y=read();
            cout<<ww[x]+ww[y]+dis[x+n][y+n]<<"\n";
        }
    }
    return 0;
}
