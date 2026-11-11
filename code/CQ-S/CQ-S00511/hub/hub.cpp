#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
using namespace std;
namespace Manaka_Ao{
    #define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<20,stdin),p1==p2)?EOF:*p1++)
    char buf[1<<20],*p1=buf,*p2=buf;
    inline int read(){
        int ans=0,w=1;
        char ch=getchar();
        while(ch<48||ch>57){
            if(ch=='-')w=-1;
            ch=getchar();
        }
        while(ch>=48&&ch<=57){
            ans=(ans<<1)+(ans<<3)+ch-48;
            ch=getchar();
        }
        return w*ans;
    }
    const int N=1000005;
    int C,T;
    int n,K;
    basic_string<int>e[N];
    int dep[N],dfn[N],up[N],tim;
    int get(int x,int y){return dep[x]<dep[y]?x:y;}
    void dfs(int x,int fa){
        dep[x]=dep[fa]+1,dfn[x]=++tim,up[x]=fa;
        for(int v:e[x])if(v!=fa)dfs(v,x);
    }
    int lca(int x,int y){
        if(dep[x]<dep[y])swap(x,y);
        while(dep[x]>dep[y])x=up[x];
        if(x==y)return x;
        while(x!=y)x=up[x],y=up[y];
        return x;
    }
    void get_dis(int x,int fa,int *d){d[x]=d[fa]+1;for(int v:e[x])if(v!=fa)get_dis(v,x,d);}
    pair<int,int> find(){
        static int d[N];
        for(int i=0;i<=n;i++)d[i]=0;
        get_dis(1,0,d);int L=0;for(int i=1;i<=n;i++)if(d[i]>d[L])L=i;
        for(int i=0;i<=n;i++)d[i]=0;
        get_dis(L,0,d);int R=0;for(int i=1;i<=n;i++)if(d[i]>d[R])R=i;
        return {L,R};
    }
    int L,R;
    int tmp[N],tot;
    void get_path(int L,int R){
        tot=0;
        int l=lca(L,R);
        while(L!=l)tmp[++tot]=L,L=up[L];
        tmp[++tot]=l;
        int now=tot;
        while(R!=l)tmp[++tot]=R,R=up[R];
        if(tot>now)reverse(tmp+now+1,tmp+tot+1);
        tmp[tot+1]=0;
    }
    int f1[N],d1[N],f2[N],d2[N];
    int o1[N],o2[N],u1[N],u2[N],t1,t2;
    void get_ord(int x,int fa,int *o,int &t,int *u,int *d){
        u[x]=fa;
        for(int v:e[x])if(v!=fa)get_ord(v,x,o,t,u,d),d[x]=max(d[x],d[v]+1);
        o[++t]=x;
    }
    void dp(int *o,int t,int m,int *f,int *d,int *up){
        static bool vis[N];
        for(int i=1;i<=n;i++)vis[i]=0,f[i]=0;
        for(int i=1;i<=t;i++){
            int x=o[i];
            ++f[x];
            if(d[x]>=m)f[up[x]]+=f[x];
            // d[up[x]]=max(d[up[x]],d[x]+1);
        }
    }
    int lp[N],rp[N],lc[N],rc[N];
    int w[N];
    int que[N];
    bool solve(int m){
        dp(o1,t1,m,f1,d1,u1);
        dp(o2,t2,m,f2,d2,u2);
        lp[0]=1;
        int L=1,R=0;
        for(int i=1;i<=tot;i++){
            int x=tmp[i];
            for(int v:e[x])if(v!=tmp[i-1]&&v!=tmp[i+1])w[x]=max(w[x],d1[v]+1);
            lp[i]=max(lp[i-1],i-max(m-w[x],0));//显然可以为本身
            while(L<=R&&f1[x]<f1[tmp[que[R]]])--R;
            que[++R]=i;
            while(L<=R&&que[L]<lp[i])++L;
            lc[i]=f1[tmp[que[L]]];
        }
        rp[tot+1]=tot;
        L=1,R=0;
        for(int i=tot;i;i--){
            int x=tmp[i];
            rp[i]=min(rp[i+1],i+max(m-w[x],0));
            while(L<=R&&f2[x]<f2[tmp[que[R]]])--R;
            que[++R]=i;
            while(L<=R&&que[L]>rp[i])++L;
            rc[i]=f2[tmp[que[L]]];
        }
        bool bj=0;
        for(int i=1;i<tot;i++)if(lc[i]+rc[i+1]<=K){bj=1;break;}
        for(int i=0;i<=n;i++)lp[i]=rp[i]=lc[i]=rc[i]=f1[i]=f2[i]=w[i]=que[i]=0;
        return bj;
    }
    int main(){
        C=read(),T=read();
        while(T--){
            n=read(),K=read();
            for(int i=1;i<n;i++){
                int x=read(),y=read();
                e[x].push_back(y),e[y].push_back(x);
            }
            dfs(1,0);
            pair<int,int> Path=find();
            L=Path.first,R=Path.second;
            get_path(L,R);
            t1=0,t2=0;
            get_ord(tmp[tot],0,o1,t1,u1,d1);
            get_ord(tmp[1],0,o2,t2,u2,d2);
            int L=0,R=n;
            int ans=n;
            while(L<=R){
                int mid=L+R>>1;
                if(solve(mid))ans=mid,R=mid-1;
                else L=mid+1;
            }
            cout<<ans<<'\n';
            tim=0;
            for(int i=0;i<=n;i++){
                dfn[i]=dep[i]=up[i]=o1[i]=o2[i]=u1[i]=u2[i]=d1[i]=d2[i]=0;
                e[i].clear();
            }
        }
        return 0;
    }
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    Manaka_Ao::main();
    return 0;
}
/*
g++ -std=c++14 hub.cpp -o hub -lm -O2 -static -Wl,-stack=2000000000
.\hub

*/
//189MB