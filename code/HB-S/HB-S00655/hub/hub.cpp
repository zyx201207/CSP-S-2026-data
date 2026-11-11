#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pii pair<int,int>
const int N=1e6+5,P=1e9+7,inf=1e9;

int rd()
{
    int x=0,y=1;char c=getchar();
    while(c<'0'||c>'9')
    {
        if(c=='-')
            y=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*y;
}

void wt(int x,char c='~')
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>=10)
        wt(x/10);
    putchar(x%10+'0');
    if(c!='~')
        putchar(c);
}

int n,k,dfn[N],to[N],tot,rt,dep[N],fa[N],flag[N],a[N],m,pre[N],suc[N],sum[N],rnk[N],sz[N];
pii mn[N][25];
vector<int> e[N];

void dfs1(int x,int f)
{
    sz[x]=1;
    fa[x]=f;
    dep[x]=dep[f]+1;
    dfn[x]=++tot;
    to[tot]=x;
    mn[tot][0]={dep[x],x};
    for(int y:e[x])
        if(y!=f)
            dfs1(y,x),sz[x]+=sz[y];
}

int getmin(int l,int r)
{
    int lg=__lg(r-l+1);
    return min(mn[l][lg],mn[r-(1<<lg)+1][lg]).second;
}

int lca(int x,int y)
{
    if(x==y)
        return x;
    x=dfn[x];y=dfn[y];
    if(x>y)
        swap(x,y);
    return fa[getmin(x+1,y)];
}

int getdis(int x,int y)
{
    return dep[x]+dep[y]-2*dep[lca(x,y)];
}

pii dfs2(int x,int h)
{
    if(e[x].size()==1)
        return {dep[x],inf};
    int mn=inf;
    vector<pii> p;
    for(int y:e[x])
        if(y!=fa[x])
            p.push_back(dfs2(y,h));
    for(auto u:p)
        mn=min(mn,u.second);
    for(auto &u:p)
        if(u.first-dep[x]+mn-dep[x]<=h)
            u.first=-inf;
    pii ans={-inf,mn};
    for(auto u:p)
        ans.first=max(ans.first,u.first);
    if(ans.first-dep[x]==h||(x==rt&&ans.first!=-inf))
    {
        flag[dfn[x]]=1;
        return {-inf,dep[x]};
    }
    return ans;
}

struct node
{
    int l,r,sum,lca;
}f[N];

int ans;
void dfs3(int x,int h)
{
    f[x]={0,0,0,0};
    if(flag[dfn[x]])
        f[x]={rnk[x],rnk[x],0,x};
    vector<int> p;
    for(int y:e[x])
        if(y!=fa[x])
        {
            dfs3(y,h);
            if(!f[y].l)
                continue;
            p.push_back(y);
            if(!f[x].l)
            {
                f[x]=f[y];
                continue;
            }
            f[x].sum+=f[y].sum+getdis(f[x].r,f[y].l);
            f[x].r=f[y].r;
            f[x].lca=lca(f[x].lca,f[y].lca);
        }
    if(p.size()>1||flag[dfn[x]])
        for(int y:e[x])
            if(y!=fa[x]&&f[y].l)
            {
                int v=f[y].sum+getdis(a[f[y].l],a[f[y].r]);
                v+=sum[max(0,f[y].l-2)]+sum[m-1]-sum[max(m-1,f[y].r)];
                if(f[y].l==1)
                    v+=getdis(a[f[y].r+1],a[m]);
                else if(f[y].r==m)
                    v+=getdis(a[1],a[f[y].l-1]);
                else
                    v+=getdis(a[1],a[m]);
                int dis=dep[x]-dep[f[y].lca]-1;
                if(p.size()==2&&!flag[dfn[x]])
                {
                    if(y==*p.begin())
                        swap(p[0],p[1]);
                    dis=getdis(f[y].lca,f[p[0]].lca)-1;
                }
                if(dis>h)
                    v+=dis-h;
                ans=min(ans,v+4);
            }
}

bool check(int h)
{
    for(int i=1;i<=n;i++)
        flag[i]=0;
    dfs2(rt,h);
    m=0;
    for(int i=1;i<=n;i++)
        if(flag[i])
            a[++m]=to[i],rnk[to[i]]=m;
    ans=0;
    for(int i=1;i<m;i++)
        ans+=getdis(a[i],a[i+1]);
    ans+=getdis(a[m],a[1])+2;
    for(int i=1;i<m;i++)
        sum[i]=sum[i-1]+getdis(a[i],a[i+1]);
    pre[1]=a[1];
    for(int i=2;i<=m;i++)
        pre[i]=lca(pre[i-1],a[i]);
    suc[m]=a[m];
    for(int i=m-1;i>=1;i--)
        suc[i]=lca(suc[i+1],a[i]);
    dfs3(rt,h);
    return ans<=k*2;
}

void solve()
{
    for(int i=1;i<=n;i++)
        e[i].clear();
    n=rd();k=rd();
    for(int i=1;i<n;i++)
    {
        int x,y;
        x=rd();y=rd();
        e[x].push_back(y);
        e[y].push_back(x);
    }
    if(n==2)
    {
        puts("0");
        return;
    }
    if(k>=n)
    {
        puts("0");
        return;
    }
    for(int i=1;i<=n;i++)
        if(e[i].size()>1)
        {
            rt=i;
            break;
        }
    tot=0;
    dfs1(rt,0);
    for(int j=1;j<=20;j++)
        for(int i=1;i+(1<<j)-1<=n;i++)
            mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
    int l=1,r=n,ans=0;
    while(l<=r)
    {
        int mid=(l+r)>>1;
        if(check(mid))
        {
            ans=mid;
            r=mid-1;
        }
        else
            l=mid+1;
    }
    printf("%d\n",ans);
}

signed main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int op,T;
    op=rd();T=rd();
    while(T--)
        solve();
    return 0;
}