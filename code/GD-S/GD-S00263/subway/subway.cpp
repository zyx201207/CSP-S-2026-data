#include<bits/stdc++.h>
using namespace std;
namespace fastIO{
    const int IN_BUF=1<<20;
    char inbuf[IN_BUF],*p1=inbuf,*p2=inbuf;
    inline int gc(){
        if(p1==p2){
            p2=(p1=inbuf)+fread(inbuf,1,IN_BUF,stdin);
            if(p1==p2) return EOF;
        }
        return *p1++;
    }
    inline int read(){
        int k=0,f=1;
        int c=gc();
        while(c!=EOF&&!isdigit(c)){
            if(c=='-') f=-1;
            c=gc();
        }
        if(c==EOF) return 0;
        while(c!=EOF&&isdigit(c)){
            k=(k<<1)+(k<<3)+(c^48);
            c=gc();
        }
        return k*f;
    }
    const int OUT_BUF=1<<22;
    char outbuf[OUT_BUF],*now=outbuf;
    inline void pc(char c){
        if(now-outbuf==OUT_BUF){
            fwrite(outbuf,1,OUT_BUF,stdout);
            now=outbuf;
        }
        *now++=c;
    }
    inline void write(int x){
        if(x==0){
            pc('0');
            return ;
        }
        if(x<0){
            x=-x;
            pc('-');
        }
        char s[25];
        int len=0;
        while(x){
            s[len++]=x%10+'0';
            x/=10;
        }
        while(len--) pc(s[len]);
    }
    inline void flush(){
        fwrite(outbuf,1,now-outbuf,stdout);
        now=outbuf;
    }
}
using namespace fastIO;
int c,n,m,d,q,w[500001];
int k[501],a[500001],t[500001];
map<pair<int,int>,int> mp;
int tot;
int lt[500001][501];
struct query{
    int s,t,id;
}qy[100001];
vector<pair<int,int>> g[500005*20];
int dis[500005*20];
struct node{
    int id,d;
    bool operator< (const node &o) const {
        return d>o.d;
    }
};
priority_queue<node> pq;
bool vis[500005*20];
inline void dij(int s,int t){
    for(int i=1;i<=tot;i++){
        dis[i]=1e9;
        vis[i]=0;
    }
    while(!pq.empty()) pq.pop();
    dis[s]=0;
    pq.push({s,0});
    while(!pq.empty()){
        int u=pq.top().id,dd=pq.top().d;
        pq.pop();
        if(vis[u]) continue ;
        if(u==t) return ;
        vis[u]=1;
        for(auto e:g[u]){
            int v=e.first,w=e.second;
            if(dis[v]>dd+w){
                dis[v]=dd+w;
                if(!vis[v]) pq.push({v,dis[v]});
            }
        }
    }
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read();n=read();m=read();d=read();q=read();
    for(int i=1;i<=m;i++){
        w[i]=read();
    }
    for(int i=1;i<=m;i++){
        mp[{i,0}]=++tot;
    }
    for(int i=1;i<=n;i++){
        k[i]=read();
        for(int j=1;j<=k[i];j++){
            a[j]=read();
            t[j]=read();
            mp[{a[j],i}]=++tot;
            lt[a[j]][i]=t[j];
            if(j==1) continue ;
            g[mp[{a[j],i}]].push_back({mp[{a[j-1],i}],0});
            g[mp[{a[j-1],i}]].push_back({mp[{a[j],i}],0});
        }
    }
    for(int i=1;i<=q;i++){
        qy[i].s=read();
        qy[i].t=read();
        qy[i].id=i;
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<=n;j++){
            if(mp.count({i,j})){
                g[mp[{i,j}]].push_back({mp[{i,0}],lt[i][j]});
                g[mp[{i,0}]].push_back({mp[{i,j}],lt[i][j]});
            }
        }
    }
    for(int i=1;i<=q;i++){
        int ss=mp[{qy[i].s,0}],tt=mp[{qy[i].t,0}];
        dij(ss,tt);
        write(dis[tt]+w[qy[i].s]+w[qy[i].t]);
        pc('\n');
    }
    flush();
    return 0;
}
