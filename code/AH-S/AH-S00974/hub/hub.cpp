#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
int n,k,lim;
vector<int> g[N];
struct Data{
    int val[3],id[3];
    void clear(){
        for(int i=0;i<3;i++) val[i]=0;
        for(int i=0;i<3;i++) id[i]=0;
    }
    void insert(int p,int v){
        for(int i=0;i<3;i++)
            if(v>val[i]){
                for(int j=2;j>i;j--)
                    val[j]=val[j-1],id[j]=id[j-1];
                val[i]=v; id[i]=p;
                break;
            }
    }
    void pop(int x){
        for(int j=x;j<2;j++)
            val[j]=val[j+1],id[j]=id[j+1];
    }
}mx[N];
int f[N],r[N],to[N][20],mxd[N][20];
void calc(int u){
    to[u][0]=mx[u].id[0]; mxd[u][0]=mx[u].val[1]+1;
    int rg=__lg(mx[u].val[0]+1);
    for(int i=1;i<=rg;i++){
        to[u][i]=to[to[u][i-1]][i-1];
        mxd[u][i]=max(mxd[u][i-1]+(1<<i-1),mxd[to[u][i-1]][i-1]);
    }
}
int findpos(int u){
    int x=u,mx=0;
    int rg=__lg(::mx[u].val[0]+1);
    for(int i=rg;i>=0;i--){
        int tmp=max(mx+(1<<i),mxd[x][i]);
        if(to[x][i]&&tmp<=lim)
            mx=tmp,x=to[x][i];
    }
    return x;
}
void dfs(int u,int fa){
    mx[u].clear(); f[u]=r[u]=0;
    for(int v:g[u]){
        if(v==fa) continue;
        dfs(v,u); mx[u].insert(v,mx[v].val[0]+1);
        f[u]+=f[v];
    }
    if(mx[u].val[0]>=lim) f[u]++;
    calc(u); int x=findpos(u); r[u]=max(f[x],1);
}
bool dfs2(int u,int fa){
    int orif=f[u];
    if(mx[u].val[0]>=lim) f[u]--;
    Data ori=mx[u];
    if(fa) mx[u].insert(fa,mx[fa].val[0]+1),f[u]+=f[fa];
    int tmpf=f[u]; 
    Data tmp=mx[u];
    for(int v:g[u]){
        if(v==fa) continue;
        mx[u]=tmp; f[u]=tmpf;
        if(v==mx[u].id[0]) mx[u].pop(0);
        else if(v==mx[u].id[1]) mx[u].pop(1);
        calc(u); f[u]-=f[v];
        if(mx[u].val[0]>=lim) f[u]++;
        int x=findpos(u);
        int req=max(f[x],1)+r[v];
        if(req<=k) return 1;
        if(dfs2(v,u)) return 1;
    }
    mx[u]=ori;
    calc(u);
    f[u]=orif;
    return 0;
}
void init(){
    for(int i=1;i<=n;i++)
        g[i].clear();
}
void work(){
    init();
    scanf("%d%d",&n,&k);
    for(int i=1;i<n;i++){
        int u,v; scanf("%d%d",&u,&v);
        g[u].push_back(v);
        g[v].push_back(u);
    }
    int l=0,r=n/2,mid;
    while(l<=r){
        mid=l+r>>1; lim=mid;
        dfs(1,0);
        if(dfs2(1,0)) r=mid-1;
        else l=mid+1;
    }
    printf("%d\n",l);
}
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c,t; scanf("%d%d",&c,&t);
    while(t--) work();
    return 0;
}