#include<bits/stdc++.h>
using namespace std;
#define int long long
#define pii pair<int,int>
#define fr first 
#define sc second 
#define mk make_pair 
#define pb push_back
#define inx(u) int I=h[(u)],v=edge[I].v;I;I=edge[I].nx,v=edge[I].v
const int MAXN=200010,N=25,inf=3e18;
int read(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}while(c>='0'&&c<='9')x=(x<<1)+(x<<3)+(c^48),c=getchar();return x*f;}
int n,m,k,ans;
struct Edge{int v,nx;}edge[MAXN<<1];int h[MAXN],CNT;void add_side(int u,int v){edge[++CNT]={v,h[u]};h[u]=CNT;edge[++CNT]={u,h[v]};h[v]=CNT;}
// // vector<pii>G[MAXN];
// // int fa[MAXN],dfn[MAXN],dep[MAXN];
// // bool cmp(int x,int y){return dep[x]<dep[y];}
// // int f[N+2][MAXN],lg2[MAXN],bg[MAXN],ed[MAXN],tot;
// // void init(int u,int lst){
// //     f[bg[u]=ed[u]=++tot][0]=u,fa[u]=lst;
// //     for(inx(u))if(v!=lst)dep[v]=dep[u]+1,init(v,u),f[ed[u]=++tot]=u;
// // }
// // int Min(int x,int y){return dep[x]<dep[y]?x:y;}
// // int lca(int x,int y){
// //     int l=min(bg[x],bg[y]),r=max(ed[x],ed[y]);
// //     int g=lg2[r-l+1];
// //     return Min(f[g][l],f[g][r-(1<<g)+1]);
// // }
// bool fl[MAXN]
int ID,MX,X,Y,fa[MAXN];
void far(int u,int lst,int dep){
    if(dep>MX)MX=dep,ID=u;
    for(inx(u))if(v!=lst)far(v,u,dep+1);
}
int p[MAXN],cnt;
bool get(int u,int lst,int t){
    if(u==t){
        p[++cnt]=u;//,fl[u]=1;
        return 1;
    }
    for(inx(u))if(v!=lst){
        if(get(v,u,t)){
            p[++cnt]=u;//,fl[u]=1;
            return 1;
        }
    }
    return 0;
}
int len[MAXN];
void idfs(int u,int lst){
    len[u]=0,fa[u]=lst;
    for(inx(u))if(v!=lst)idfs(v,u),len[u]=max(len[u],len[v]+1);
}
// // void init(){
// //     // dep[1]=0,init(1,1);
// //     // for(int i=2;i<=tot;i++)lg2[i]=lg2[i>>1]+1;
// //     // for(int i=1;i<N;i++)for(int j=1;j+(1<<i)-1<=tot;j++)f[i][j]=Min(f[i-1][j],f[i-1][j+(1<<i-1)]);
// //     MX=ID=0;
// //     far(1,1,0);
// //     X=ID,MX=ID=0;
// //     far(X,X,0);
// //     Y=ID,MX=ID=0;
// //     get(X,X,Y);
// //     for(int i=1;i<=cnt;i++)idfs(p[i],p[i]);
// // }
// // int lz[MAXN],id[MAXN];
// // int dfs(int u,int lst,int now){
// //     int res=0;
// //     if(now<len[u])now=k,res=1;
// //     else return 0;
// //     for(inx(u))if(v!=lst&&!fl[v])res+=dfs(v,u,now-1);
// //     return res;
// // }
// // int f[MAXN];
// // bool check(int x){k=x;
// //     if(k>=cnt-k+1)return 1;
// //     int sum=0;
// //     for(int i=k;i<=n-k+1;i++)if(len[i]>=k){
// //         sum+=f[i]=dfs(p[i],p[i],0);
// //     }else f[i]=0;
// //     // for(int l=k,r=k;l<=n-k+1;l++){
// //     //     while(r<=n-k+1&&)
// //     // }
// //     // if(cnt-k+1-k+1<=m){

// //     // }
// // }
struct side{
    int u,v;
}s[MAXN];

void get(int x){
    // dep[1]=0,init(1,1);
    // for(int i=2;i<=tot;i++)lg2[i]=lg2[i>>1]+1;
    // for(int i=1;i<N;i++)for(int j=1;j+(1<<i)-1<=tot;j++)f[i][j]=Min(f[i-1][j],f[i-1][j+(1<<i-1)]);
    MX=ID=cnt=0;
    far(x,x,0);
    X=ID,MX=ID=0;
    far(X,X,0);
    Y=ID,MX=ID=0;
    get(X,X,Y);
    // for(int i=1;i<=n;i++)fl[i]=0;
    // for(int i=1;i<=cnt;i++)idfs(p[i],p[i]);
    // return mk(X,Y);
}
priority_queue<pii>Q;
void slv1(){
    n=read(),m=read();
    if(m==n){
        puts("0");
        return;
    }
    for(int i=1;i<n;i++)s[i].u=read(),s[i].v=read();
    ans=n;
    for(int x=1;x<n;x++){
        for(int i=1;i<=n;i++)h[i]=0;CNT=1;
        for(int i=1;i<n;i++)if(i!=x)add_side(s[i].u,s[i].v);
        get(s[x].u);
        int u=p[(cnt+1)>>1];
        idfs(u,u);
        for(inx(u))Q.push(mk(len[v],v));
        get(s[x].v);
        u=p[(cnt+1)>>1];
        idfs(u,u);
        for(inx(u))Q.push(mk(len[v],v));
        for(int now=3;now<=m;now++){
            u=Q.top().sc;Q.pop();
            for(inx(u))if(v!=fa[u])Q.push(mk(len[v],v));
        }
        ans=min(ans,Q.top().fr+1);
        while(!Q.empty())Q.pop();
    }
    // for(int i=1;i<n;i++){
    //     int u=read(),v=read();
    //     add_side(u,v);
    // }
    // init();
    // int l=read(),r=read();
    // while(l<r){
    //     int mid=(l+r)>>1;
    //     if(check(mid))r=mid;
    //     else l=mid+1;
    // }
    printf("%lld\n",ans);
}
// void slv2(){
//     n=read(),m=read();
//     for(int i=1;i<n;i++){
//         int u=read(),v=read();
//         add_side(u,v);
//     }
//     init();
//     int l=read(),r=read();
//     while(l<r){
//         int mid=(l+r)>>1;
//         if(check(mid))r=mid;
//         else l=mid+1;
//     }
//     printf("%lld\n",l);
// }
// void slv3(){
//     n=read(),m=read();
//     for(int i=1;i<n;i++){
//         int u=read(),v=read();
//         add_side(u,v);
//     }
//     init();
//     int l=read(),r=read();
//     while(l<r){
//         int mid=(l+r)>>1;
//         if(check(mid))r=mid;
//         else l=mid+1;
//     }
//     printf("%lld\n",l);
// }
signed main(){
    freopen("hub.in","r",stdin);freopen("hub.out","w",stdout);
    int __=read(),_=read();while(_--)
  //  if(__<=10)
    slv1();
    // else if(__<=12)slv2();
    // else slv3();
    cerr<<clock()*1.0/CLOCKS_PER_SEC<<"s\n";
    return 0;
}