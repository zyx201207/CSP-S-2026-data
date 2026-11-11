#include<bits/stdc++.h>
using namespace std;

vector<int> g[1000010];
int fa[1000010][20],dep[1000010],u[1000010],v[1000010],n,kk;
int du[1000010];
void dfs(int x,int faa)
{
    //cout<<x<<" "<<faa<<endl;
    fa[x][0]=faa;
    dep[x]=dep[faa]+1;
    for (auto y:g[x])
    {
        if(y==faa) continue;
        dfs(y,x);
    }
}
int lca(int x,int y)
{
    if(dep[x]<dep[y]) swap(x,y);
    int s=0;
    for (int k=log2(n);k>=0;k--)
    {
        if(dep[fa[x][k]]>=dep[y])
        {
            s+=(1<<k);
            x=fa[x][k];
        }
    }
    if(x==y) return s;
    for (int k=log2(n);k>=0;k--)
    {
        if(fa[x][k]!=fa[y][k])
        {
            s+=(1<<k+1);
            x=fa[x][k];
            y=fa[y][k];
        }
    }
    return s+2;
}
int dis[1000010],duu,duv,vis[1000010];
void dfs1(int x,int faa)
{
    if(x==duu&&faa==duv) return;
    if(x==duv&&faa==duu) return;
    dis[x]=dis[faa]+1;
    //cout<<x<<" "<<faa<<endl;
    vis[x]=1;
    for (auto y:g[x])
    {
        if(y==faa) continue;
        dfs1(y,x);
    }
}
int yao;
int f[1000010],ll[1000010];
void dfs2(int x,int faa)
{
    for (auto y:g[x])
    {
        if(y==faa) continue;
        if(y==duu&&x==duv) continue;
        if(y==duv&&x==duu) continue;
        dfs2(y,x);
        ll[x]=max(ll[x],ll[y]);
        f[x]+=f[y];
    }
    ll[x]++;
    if(ll[x]>=yao+1) f[x]++;
}
int lcx[4040][4040];
int qiu(int x)
{
    if(!x) return 0;
    for (int j=1;j<=n;j++) vis[j]=0,f[j]=0,ll[j]=0;
    //cout<<x<<endl;
    dfs1(x,0);
    int maxn=0,maxid=0;
    for (int j=1;j<=n;j++)
    {
        if(!vis[j]) continue;
        if(dis[j]>maxn)
        {
            maxn=dis[j];
            maxid=j;
        }
    }
    dis[0]=-1;
    dfs1(maxid,0);
    maxn=0;int max2id=0;
    for (int j=1;j<=n;j++)
    {
        if(!vis[j]) continue;
        if(dis[j]>maxn)
        {
            maxn=dis[j];
            max2id=j;
        }
    }
    //cout<<maxid<<" "<<max2id<<" "<<x<<" "<<maxn<<endl;
    int id=-1;
    for (int j=1;j<=n;j++)
    {
        if(!vis[j]) continue;
        int s1=lcx[j][maxid],s2=lcx[j][max2id];
        //if(maxid==5&&max2id==2) cout<<j<<" "<<s1<<" "<<s2<<endl;
        if(abs(s1-s2)<=1&&s1+s2==maxn)
        {
            id=j;
            break;
        }
    }
    //if(id==-1) cout<<id<<endl;
    dfs2(id,0);
    //cout<<id<<" "<<yao<<" "<<lcx[id][maxid]<<" "<<lcx[id][max2id]<<" "<<maxid<<" "<<max2id<<" "<<f[id]<<endl;
    return max(1,f[id]);
}
int ef(int i)
{
    int l=1,r=n;
    while(l<r)
    {
        int mid=(l+r)/2;yao=mid;
        if(qiu(u[i])+qiu(v[i])<=kk) r=mid;
        else l=mid+1;
    }
    return r;
}
void solve()
{
    cin >>n>>kk;
    for (int i=1;i<=n;i++)
    {
        g[i].clear();
        dep[i]=0;du[i]=0;f[i]=0;ll[i]=0;dis[i]=0;vis[i]=0;
        for (int j=0;j<=log2(n);j++) fa[i][j]=0;
    }
    int flag=1;
    if(n%2==0) flag=0;
    for (int i=1;i<n;i++)
    {
        cin >>u[i]>>v[i];
        g[u[i]].push_back(v[i]);
        g[v[i]].push_back(u[i]);
        //cout<<u[i]<<" "<<v[i]<<endl;
        du[u[i]]++;du[v[i]]++;
        if(i<=n/2&&(u[i]!=i||v[i]!=i+1)) flag=0;
        if(i>n/2&&(u[i]!=i-n/2||v[i]!=i+1)) flag=0;
    }
    //cout<<flag<<endl;
    if(flag&&n>1000)
    {
        n=n/2+2;
        int x=(n-kk)/2;
        int s1=max((x+1)/2,(n-kk-x+1)/2),s2=max((x+2)/2,(n-kk-x)/2);
        if(x+1>n) s2=0;
        //cout<<s1<<" "<<s2<<" "<<x<<endl;
        cout<<min(s1,s2)<<"\n";
        return;
    }
    if(n==kk)
    {
        cout<<"0\n";
        return;
    }
    dfs(1,0);
    for (int k=1;k<=log2(n);k++)
        for (int i=1;i<=n;i++)
            fa[i][k]=fa[fa[i][k-1]][k-1];
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
        {
            lcx[i][j]=lca(i,j);
            //cout<<i<<" "<<j<<" "<<lcx[i][j]<<endl;
        }
    }
    int minn=1e9;
    duu=0,duv=0;u[0]=1,v[0]=0;
    minn=min(minn,ef(0));
    for (int i=1;i<n;i++)
    {
        duu=u[i],duv=v[i];
        minn=min(minn,ef(i));
        //cout<<u[i]<<" "<<v[i]<<" "<<minn<<endl;
    }
    cout<<minn<<"\n";
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t;
    cin >>t>>t;
    while(t--) solve();
    return 0;
}
