#include<bits/stdc++.h>
const int N=1e6;
int n,K;
std::vector<int>e[N+5];
int d[N+5];
int dis[N+5],q[N+5],head,tail,dis2[N+5];
int vis[N+5];
int id[N+5],m;
std::vector<int>g[N+5];
int ms[N+5];
int z[N+5],tot;
int kmn[N+5];
int tm=0;
int getwork(int x,int y,int mid){
    tot=0;
    while(g[y].size()==2){
        z[++tot]=y;
        //++tm;
        y=(g[y][0]==x?g[y][1]:g[y][0]);
        x=z[tot];
    }
    for(int i=1;i<=tot;++i)kmn[i]=tot;
    //if(mid==1)printf("ee%d\n",tot);
    for(int i=1;i<=tot;++i){
        int dd=mid-ms[z[i]];
        //if(x==1)printf("%d %d\n",i,z[i]);
        if(dd+i<=tot&&i-dd>=1){
        //if(mid==1)printf("cc%d %d\n",i,dd);
            kmn[i-dd]=std::min(kmn[i-dd],i+dd-1);
        }
    }
    for(int i=tot;i;--i){
        //if(mid==1)printf("%d %d\n",i,kmn[i]);
        if(i!=tot)kmn[i]=std::min(kmn[i],kmn[i+1]);
        if(m-(kmn[i]-i+1)<=K){
            //if(mid==1)printf("%d %d %d %d\n",x,y,i,kmn[i]);
            return 1;
        }
    }
    return 0;
}
int Max(int x,int y){return x<y?y:x;}
bool check(int x){
    //return 1;
    //if(x==1){
    //    for(int i=1;i<=n;++i)printf("%d",vis[i]);
    //    printf("\n");
    //}
    m=0;
    for(int i=1;i<=n;++i)if(dis[i]>=x)id[i]=++m,ms[m]=dis2[i];
    //if(x==2)printf("%d\n",m);
    if(m<=K)return 1;
    //return 1;
    for(int i=1;i<=n;++i)if(dis[i]>=x){
        g[id[i]].clear();
            //++tm;
        for(int v:e[i])if(dis[v]>=x)g[id[i]].push_back(id[v]);
    }
    //if(x==1){
    //for(int i=1;i<=m;++i){
    //    printf("%d\n",ms[i]);
    //    for(int v:g[i])printf("%d %d\n",i,v);
    //}}
    for(int i=1;i<=m;++i)if(g[i].size()!=2){
        for(int v:g[i])if(g[v].size()==2){
            if(getwork(i,v,x))return 1;
        }
    }
    return 0;
}
void clean(){
    for(int i=1;i<=n;++i)e[i].clear(),g[i].clear();
}
int read(){
    char c=getchar();int x=0;
    while(c<'0'||c>'9')c=getchar();
    while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();
    return x;
}
void work(){
    n=read(),K=read();
    for(int i=1,u,v;i<n;++i){
        u=read(),v=read();
        e[u].push_back(v);
        e[v].push_back(u);
    }
    if(K==n){
        printf("0\n");
        return;
    }
    for(int i=1;i<=n;++i)dis[i]=0,vis[i]=0,dis2[i]=0;
    head=tail=0;
    for(int i=1;i<=n;++i){
        d[i]=e[i].size();
        if(d[i]==1)dis[i]=0,q[tail++]=i,vis[i]=1;
    }
    //for(int i=1;i<=n;++i)for(int v:e[i])++tm;
    while(head!=tail){
        int u=q[head];
        for(int v:e[u])if(!vis[v]){
            dis[v]=dis[u]+1;
            --d[v];
            if(d[v]==2){
                dis2[v]=dis[v];
            }
            if(d[v]==1){
                q[tail++]=v;
                vis[v]=1;
            }
        }
        ++head;
    }
    //return;
    int l=0,r=n;
    while(r-l>1){
        int mid=l+r>>1;
        if(check(mid))r=mid;
        else l=mid;
    }
    printf("%d\n",r);
    //printf("%d\n",tm);
}
int caseid,Tcase;
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    caseid=read(),Tcase=read();
    while(Tcase--){
        clean();
        work();
    }
    return 0;
}