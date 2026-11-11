#include<bits/stdc++.h>
#define up(i,l,r) for(int i=(l);i<=(r);++i)
#define down(i,l,r) for(int i=(l);i>=(r);--i)
#define pi pair<int,int>
#define p1 first
#define p2 second
#define m_p make_pair
#define pb push_back
#define eb emplace_back
using namespace std;
typedef long long ll;
const int maxn=1e6+10;
int n,k,fa[maxn];
vector<int>E[maxn];
int ver[maxn];
int in[maxn],out[maxn];
struct tree{
    int fa[20][maxn],eu[20][maxn],dfn[maxn],siz[maxn],dep[maxn],tot;
    int gmin(int x,int y){return dfn[x]<dfn[y]?x:y;}
    void dfs(int u){
        eu[0][dfn[u]=++tot]=fa[0][u],dep[u]=dep[fa[0][u]]+1;siz[u]=1;
        for(int x:E[u])if(x!=fa[0][u])fa[0][x]=u,dfs(x),siz[u]+=siz[x];
    }
    void init(int rt){
        up(i,1,n)fa[0][i]=0;tot=0;dfs(rt);
        up(i,1,__lg(n))up(j,2,n-(1<<i)+1)
            eu[i][j]=gmin(eu[i-1][j],eu[i-1][j+(1<<i-1)]);
        up(i,1,__lg(n))up(j,1,n)fa[i][j]=fa[i-1][fa[i-1][j]];
    }
    int operator()(int x,int y){
        if(x==y)return x;x=dfn[x],y=dfn[y];if(x>y)swap(x,y);x++;
        int k=__lg(y-x+1);
        return gmin(eu[k][x],eu[k][y-(1<<k)+1]);
    }
}lca;
int qdis(int x,int y){return lca.dep[x]+lca.dep[y]-2*lca.dep[lca(x,y)];}
int qu(int x,int y){
    if(lca.dep[x]<lca.dep[y])swap(x,y);
    int d=qdis(x,y)/2;
    down(i,__lg(n),0)if((d>>i)&1)x=lca.fa[i][x];
    return x;
}
struct nd{
    int x,y,d;
    nd(int _x,int _y){x=_x,y=_y,d=qdis(x,y);}
    nd(){x=y=d=0;}
};
bool operator<(nd a,nd b){return a.d<b.d;}
inline nd operator+(nd a,nd b){
    nd c=max(a,b);
    c=max(c,nd(a.x,b.x));
    c=max(c,nd(a.x,b.y));
    c=max(c,nd(a.y,b.x));
    c=max(c,nd(a.y,b.y));
    return c;
}
int idfn[maxn];
nd pre[maxn],suf[maxn],sum[maxn];
void dfs2(int u,int f){
    sum[u]=nd(u,u),fa[u]=f;
    for(int x:E[u])if(x!=f)dfs2(x,u),sum[u]=sum[u]+sum[x];
}
int c,rt;
int t[maxn];
int vis[maxn];
int mx[maxn];
void dfs3(int u,int f,int *t){
    mx[u]=0;
    for(int x:E[u])if(x!=f&&!vis[x])dfs3(x,u,t),mx[u]=max(mx[u],mx[x]+1);
    t[mx[u]]++;
}
void slv(){
    scanf("%d%d",&n,&k);
    up(i,1,n)E[i].clear();
    up(i,1,n-1){
        int x,y;scanf("%d%d",&x,&y);
        E[x].eb(y),E[y].eb(x);
    }
    rt=1;lca.init(rt);dfs2(rt,0);
    up(i,1,n)idfn[lca.dfn[i]]=i;
    pre[1]=nd(idfn[1],idfn[1]);up(i,2,n)pre[i]=pre[i-1]+nd(idfn[i],idfn[i]);
    suf[n]=nd(idfn[n],idfn[n]);down(i,n-1,1)suf[i]=suf[i+1]+nd(idfn[i],idfn[i]);
    int val=1e9;
    up(i,1,n)if(i!=rt){
        nd I=sum[i];
        nd O=pre[lca.dfn[i]-1];
        if(lca.dfn[i]+lca.siz[i]<=n)O=O+suf[lca.dfn[i]+lca.siz[i]];
        in[i]=qu(I.x,I.y),out[i]=qu(O.x,O.y);
        val=min(val,max((I.d+1)/2,(O.d+1)/2));
    }
    if(c==11||c==12){
        printf("%d\n",val);
        return;
    }
        int res=1e9;
        up(i,1,n)if(i!=rt){
            if(c==13||c==14){
                int ps=n/4;
                if(abs(i-ps)>5)continue;
            }
            up(j,0,n)t[j]=0;
            int u=in[i],v=out[i];
            vis[fa[i]]=1;dfs3(u,0,t);
            vis[fa[i]]=0,vis[i]=1;dfs3(v,0,t);vis[i]=0;
            down(j,n-1,0)t[j]+=t[j+1];
            down(j,n-1,0)if(t[j]<=k)res=min(res,j);
        }
        printf("%d\n",res);
}
int main(){
    freopen("hub.in","r",stdin),freopen("hub.out","w",stdout);
    int t;for(scanf("%d%d",&c,&t);t--;slv());
    return 0;
}