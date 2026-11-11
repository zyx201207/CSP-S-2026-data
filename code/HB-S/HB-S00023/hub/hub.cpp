#include<bits/stdc++.h>
using namespace std;
const int N=1e6+100;
int n,k;
int s[N],b[N];
int f[N],pq[N];
int fa[N][26],d[N];
int ans=0;
vector<int>t[N];
long long read()
{
    long long sum=0;
    char ch=getchar();
    while (ch<'0'||ch>'9') ch=getchar();
    while (ch>='0'&&ch<='9') sum=sum*10+(ch-'0'),ch=getchar();
    return sum;
}
void write(long long num)
{
    if (num>9) write(num/10);
    putchar(num%10+'0');
}
int find(int x)
{
    if (x==f[x]) return x;
    return f[x]=find(f[x]);
}
void merge(int u,int v)
{
    int x=find(u),y=find(v);
    if (x==y) return;
    f[x]=y;
}
void dfs2(int u,int fa_id)
{
    d[u]=d[fa_id]+1;
    fa[u][0]=fa_id;
    for (int i=0;i<t[u].size();i++)
    {
        int v=t[u][i];
        if (v==fa_id) continue;
        dfs2(v,u);
    }
}
int lca(int u,int v)
{
    if (d[u]<d[v]) swap(u,v);
    for (int i=20;i>=0;i--)
    {
        if (d[fa[u][i]]>=d[v]) u=fa[u][i];
    }
    if (u==v) return u;
    for (int i=20;i>=0;i--)
    {
        if (fa[u][i]!=fa[v][i]) u=fa[u][i],v=fa[v][i];
    }
    return fa[u][0];
}
int dist(int u,int v)
{
    return d[u]+d[v]-2*d[lca(u,v)];
}
bool check()
{
    for (int i=1;i<=n;i++) f[i]=i;
    for (int u=1;u<=n;u++)
    {
        for (int i=0;i<t[u].size();i++)
        {
            int v=t[u][i];
            if (b[u]&&b[v]) merge(u,v);
        }
    }
    memset(pq,0,sizeof(pq));
    for (int i=1;i<=k;i++)
    {
        pq[find(s[i])]=1;
    }
    int num=0;
    for (int i=1;i<=k;i++) num+=pq[i];
    return num<=2;
}
void work()
{
    if (check())
    {
        int ans1=0;
        for (int u=1;u<=n;u++)
        {
            if (b[u]) continue;
            int ans2=1e9;
            for (int i=1;i<=k;i++)
            {
                int v=s[i];
                ans2=min(ans2,dist(u,v));
            }
            ans1=max(ans1,ans2);
        }
        ans=min(ans,ans1);
    }
    else return;
}
void dfs(int x,int p)
{
    if (x==k+1)
    {
        work();
        return;
    }
    for (int i=p;i<=n;i++)
    {
        s[x]=i;
        b[i]=1;
        dfs(x+1,i+1);
        b[i]=0;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    int c=read(),T=read();
    while (T--)
    {
        ans=1e9;
        n=read(),k=read();
        for (int i=1;i<=n;i++) t[i].clear();
        for (int i=1;i<n;i++)
        {
            int u,v;
            u=read(),v=read();
            t[u].push_back(v);
            t[v].push_back(u);
        }
        memset(fa,0,sizeof(fa));
        memset(d,0,sizeof(d));
        dfs2(1,0);
        dfs(1,1);
        write(ans);
        putchar('\n');
    }
    return 0;
}
