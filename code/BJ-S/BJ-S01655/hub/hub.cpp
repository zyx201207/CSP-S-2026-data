#include<iostream>
#include<vector>
using namespace std;
int cid,t,n,k;
const int nr=1e5+10;
int ex[nr],ey[nr];
struct edge{
    int x,id;
};
vector<edge>v[nr];
bool flag[nr];
int dep[nr],maxd[nr],fa[nr];
void dfs(int x,int last)
{
    dep[x]=dep[last]+1,fa[x]=last;
    for(auto e:v[x])if(flag[e.id]&&e.x!=last)dfs(e.x,x);
}
void dfs2(int x,int last)
{
    int maxn=0;
    for(auto e:v[x])
        if(flag[e.id]&&e.x!=last)
        {
            dfs2(e.x,x);
            maxn=max(maxn,maxd[e.x]);
        }
    maxd[x]=maxn+1;
}
int cnt[nr];
namespace solvek2
{
    int dep[nr],fa[nr][20];
    void dfs(int x,int last)
    {
        dep[x]=dep[last]+1;
        fa[x][0]=last;
        for(int i=1;i<20;i++)fa[x][i]=fa[fa[x][i-1]][i-1];
        for(auto e:v[x])
            if(e.x!=last)dfs(e.x,x);
    }
    int lca(int x,int y)
    {
        if(dep[x]<dep[y])swap(x,y);
        for(int i=19;i>=0;i--)
            if(dep[fa[x][i]]>=dep[y])x=fa[x][i];
        if(x==y)return x;
        for(int i=19;i>=0;i--)
            if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];
        return fa[x][0];
    }
    int dis(int x,int y){
        return dep[x]+dep[y]-2*dep[lca(x,y)];
    }
    struct diam{
        int u,v;
    };
    int len(diam x){
        return dis(x.u,x.v);
    }
    diam merge(diam x,diam y)
    {
        diam z;
        int maxn=-1;
        int p[4];
        p[0]=x.u,p[1]=x.v,p[2]=y.u,p[3]=y.v;
        for(int i=0;i<4;i++)
            for(int j=i+1;j<4;j++)
            {
                int now=dis(p[i],p[j]);
                if(now>maxn)maxn=now,z.u=p[i],z.v=p[j];
            }
        return z;
    }
    diam f[nr],g[nr],pr[nr],su[nr];
    int ans[nr];
    void pre(int x)
    {
        f[x]={x,x};
        for(auto e:v[x])
        {
            pre(e.x);
            f[x]=merge(f[x],f[e.x]);
        }
    }
    void calc(int x)
    {
        //cout<<x<<" "<<g[x].u<<" "<<g[x].v<<endl;
        diam now={x,x};
        for(auto e:v[x])
        {
            now=merge(now,f[e.x]);
            pr[e.x]=now;
        }
        now={x,x};
        for(int i=v[x].size()-1;i>=0;i--)
        {
            auto e=v[x][i];
            now=merge(now,f[e.x]);
            su[e.x]=now;
        }
        for(int i=0;i<v[x].size();i++)
        {
            auto e=v[x][i];
            now=merge({x,x},g[x]);
            if(i)now=merge(now,pr[v[x][i-1].x]);
            if(i<v[x].size()-1)now=merge(now,su[v[x][i+1].x]);
            g[e.x]=now;
            calc(e.x);
        }
    }
    void solve()
    {
        dfs(1,0);
        for(int i=1;i<=n;i++)
        {
            int pos=-1;
            for(int j=0;j<v[i].size();j++)
            {
                if(v[i][j].x==fa[i][0])pos=j;
            }
            vector<edge>v2;
            v2.clear();
            for(int j=0;j<v[i].size();j++)
            {
                if(j==pos)continue;
                v2.push_back(v[i][j]);
            }
            v[i]=v2;
        }
        pre(1);
        //for(int i=1;i<=n;i++)cout<<f[i].u<<" "<<f[i].v<<endl;
        g[1]={1,1};
        calc(1);
        //for(int i=1;i<=n;i++)cout<<g[i].u<<" "<<g[i].v<<endl;
        int ans=n;
        for(int i=2;i<=n;i++)ans=min(ans,max((len(f[i])+1)/2,(len(g[i])+1)/2));
        cout<<ans<<'\n';
    }
};
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);cin.tie(0),cout.tie(0);
    cin>>cid>>t;
    while(t--)
    {
        cin>>n>>k;
        for(int i=1;i<=n;i++)v[i].clear();
        for(int i=1;i<n;i++)
        {
            int x,y;
            cin>>x>>y;
            ex[i]=x,ey[i]=y;
            v[x].push_back({y,i});
            v[y].push_back({x,i});
        }
        if(cid<=10)
        {
            for(int i=1;i<n;i++)flag[i]=1;
            int ans=n;
            for(int i=1;i<n;i++)
            {
                flag[i]=0;
                //=====================================
                int U=0,V=0,rtx,rty;
                for(int j=1;j<=n;j++)dep[j]=0;
                dfs(ex[i],0);
                for(int j=1;j<=n;j++)
                    if(dep[j]>dep[U])U=j;
                dfs(U,0);
                for(int j=1;j<=n;j++)
                    if(dep[j]>dep[V])V=j;
                rtx=V;
                for(int j=1;j<=dep[V]/2;j++)rtx=fa[rtx];
                //=====================================
                U=V=0;
                for(int j=1;j<=n;j++)dep[j]=0;
                dfs(ey[i],0);
                for(int j=1;j<=n;j++)
                    if(dep[j]>dep[U])U=j;
                dfs(U,0);
                for(int j=1;j<=n;j++)
                    if(dep[j]>dep[V])V=j;
                rty=V;
                for(int j=1;j<=dep[V]/2;j++)rty=fa[rty];
                //=====================================
                for(int j=1;j<=n;j++)maxd[j]=0;
                dfs2(rtx,0),dfs2(rty,0);
                for(int j=1;j<=n;j++)cnt[j]=0;
                for(int j=1;j<=n;j++)cnt[maxd[j]]++;
                /*cout<<ex[i]<<" "<<ey[i]<<":::\n";
                cout<<rtx<<", "<<rty<<endl;
                for(int j=1;j<=n;j++)cout<<maxd[j]<<" ";cout<<endl;*/
                int nans=n,nowk=k;
                while(nowk>=cnt[nans])nowk-=cnt[nans],nans--;
                ans=min(ans,nans);
                flag[i]=1;
            }
            cout<<ans<<'\n';
        }
        else if(cid<=12)
        {
            solvek2::solve();
        }
    }
    return 0;
}
