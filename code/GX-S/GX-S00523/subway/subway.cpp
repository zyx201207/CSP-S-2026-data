#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector <int> a[502],t[502];
struct Node{
    int to,next,w;
}e[1010];
int head[501],cnt;
void add(int u,int v,int w){
    e[++cnt].to=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}
inline int read(){
    int x=0;
    char ch=getchar();
    while(ch<'0'||ch>'9') ch=getchar();
    while(ch>='0'&&ch<='9'){
        x=(x<<3)+(x<<1)+(ch^48);
        ch=getchar();
    }
    return x;
}
struct node{
    int x,len;
    bool operator < (const node &w) const{
        return len>w.len;
    }
};
int dis[501];
char vis[501];
priority_queue <node> sss;
void dij(int s){
    fill(dis+1,dis+m+1,1e9);
    fill(vis+1,vis+m+1,0);
    dis[s]=0;
    sss.push({s,0});
    while(!sss.empty()){
        node p=sss.top();
        sss.pop();
        if(dis[p.x]<p.len) continue;
        vis[p.x]=1;
        for(int i=head[p.x];i;i=e[i].next){
            int v=e[i].to;
            if(dis[v]>dis[p.x]+e[i].w){
                dis[v]=dis[p.x]+e[i].w;
                if(!vis[v]) sss.push({v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d=read(),q=read();
    vector <int> w(m+2);
    for(int i=1;i<=m;i++) w[i]=read();
    vector <int> k(n+2);
    for(int i=1;i<=n;i++){
        k[i]=read();
        a[i].resize(k[i]+2);
        t[i].resize(k[i]+2);
        for(int j=1;j<=k[i];j++){
            a[i][j]=read(),t[i][j]=read();
            if(j>1){
                add(a[i][j-1],a[i][j],t[i][j]);
                add(a[i][j],a[i][j-1],t[i][j]);
            }
        }
    }
    while(q--){
        int x=read(),y=read();
        dij(x);
        cout<<dis[y]+w[x]+w[y]<<'\n';
    }
    return 0;
}
