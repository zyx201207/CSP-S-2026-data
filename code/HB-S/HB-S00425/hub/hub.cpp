#include<bits/stdc++.h>
using namespace std;
int c,T;
const int mx=5e5+100;
int fa[mx];
int read()
{
    int x=0,w=1;char ch=getchar();
    while(ch<'0'||ch>'9') w=ch=='-'?-1:1,ch=getchar();
    while(ch>='0'&&ch<='9') x=x*10+(ch-'0'),ch=getchar();
    return x*w;
}
void write(int x)
{
    if(x<0) putchar('-'),x*=-1;
    if(x>=10) write(x/10);
    putchar(x%10+'0');
    return ;
}
int n,k;
struct edge
{
    int to,nxt;
}e[2*mx];
int h[mx],tot;
void build(int u,int v)
{
    e[++tot].nxt=h[u];
    h[u]=tot;
    e[tot].to=v;
    return ;
}
int vis[20];
int find(int x) 
{
    if(fa[x]==x) return x;
    return fa[x]=find(fa[x]);
}
void merge(int x,int y)
{
    int xx=find(x),yy=find(y);
    fa[xx]=yy;
}
bool che()
{
    int sum=0;
    for(int i=1;i<=n;i++) sum+=vis[i];
    if(sum!=k) return 0;
    for(int i=1;i<=n;i++) fa[i]=i;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==1)
        {
            for(int j=h[i];j;j=e[j].nxt)
            {
                int v=e[j].to;
                if(vis[v]) merge(i,v);
            }
        }
    }
    // for(int i=1;i<=n;i++) cout<<vis[i]<<' ';cout<<endl;
    int ans1=0,ans2=0; 
    for(int i=1;i<=n;i++)
    {
        if(vis[i]==0) continue;
        int x=find(i);
        // cout<<ans1<<' '<<ans2<<' '<<x<<endl;
        if(ans1==x||ans2==x) continue;
        if(ans1&&ans2) return 0;
        if(ans1) ans2=x;
        ans1=x; 
    }
    return 1;
}
int gg(int u,int f)
{
    int aa=2e9;
    if(vis[u]) return 0;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==f) continue;
        aa=min(aa,gg(v,u)+1);
    }
    return aa;
}
int getans()
{
    int maxn=0;
    for(int i=1;i<=n;i++)
    {
        if(vis[i]) continue;
        maxn=max(maxn,gg(i,0));
    }
    return maxn;
}
int ans=1e9;
void dfs(int st)
{
    if(st==n)
    {
        if(che()) ans=min(ans,getans());
        return ;
    }
    vis[st+1]=1;
    dfs(st+1);
    vis[st+1]=0;
    dfs(st+1);
    return ;
}
int fre[mx];
int len[mx];
void getlen(int u,int f)
{
    fre[u]=u;
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==f) continue;
        getlen(v,u);
        if(len[v]+1>len[u])
        len[u]=len[v]+1,fre[u]=fre[v];
    }
}
vector<int> pa;
void getpath(int u,int f)
{
    for(int i=h[u];i;i=e[i].nxt)
    {
        int v=e[i].to;
        if(v==f) continue;
        if(len[v]==len[u]-1)
        {
            pa.push_back(v);
            getpath(v,u);
            return ;
        }
    }
    return ;
}
int del[mx];
struct ee
{
    int u,v;
}bc[mx*2];
vector<int> g[mx];
void solve()
{
    getlen(1,0);
    int st=fre[1];
    for(int i=1;i<=n;i++) len[i]=0;
    getlen(st,0);
    int en=fre[st];
    // cout<<st<<' '<<en<<endl;
    int l=len[st]+1;
    // cout<<l<<endl;
    pa.clear();
    pa.push_back(st);
    getpath(st,0);
    if(l%2==1)
    {
        int del1=pa[l/2];
        // cout<<"DD:"<<del1<<endl;
        tot=0;
        memset(h,0,sizeof(h));
        for(int i=1;i<n;i++)
        {
            int u=bc[i].u,v=bc[i].v;
            if(u==del1||v==del1) continue;
            build(u,v),build(v,u);
        }
        int ans1=0,ans2=0;
        // for(int i=h[del1];i;i=e[i].nxt)
        for(int i=0;i<g[del1].size();i++)
        {
            int v=g[del1][i];
            for(int j=1;j<=n;j++) len[j]=1;
            getlen(v,0);
            st=fre[v];
            getlen(st,0);
            en=fre[st];
            // cout<<st<<' '<<en<<endl;
            int ll=len[st]+1;
            int now=(ll)/2;
            if(now>ans1) ans2=ans1,ans1=now;
            else if(now>ans2) ans2=now;
        }
        cout<<ans2<<endl;
        return ;
    }
    else
    {
        // cout<<"DD:";
        int del1=pa[l/2];
        tot=0;
        memset(h,0,sizeof(h));
        for(int i=1;i<n;i++)
        {
            int u=bc[i].u,v=bc[i].v;
            if(u==del1||v==del1) continue;
            build(u,v),build(v,u);
        }
        int ans1=0,ans2=0;
        for(int i=0;i<g[del1].size();i++)
        {
            int v=e[i].to;
            for(int j=1;j<=n;j++) len[j]=1;
            getlen(v,0);
            st=fre[v];
            getlen(st,0);
            en=fre[st];
            // cout<<"DEBUG:"<<st<<" "<<en<<endl;
            int ll=len[st]+1;
            int now=(ll)/2;
            if(now>ans1) ans2=ans1,ans1=now;
            else if(now>ans2) ans2=now;
        }
        int aaa=ans2;
        del1=pa[(l-1)/2];
        tot=0;
        memset(h,0,sizeof(h));
        for(int i=1;i<n;i++)
        {
            int u=bc[i].u,v=bc[i].v;
            if(u==del1||v==del1) continue;
            build(u,v),build(v,u);
        }
        ans1=0,ans2=0;
        for(int i=0;i<g[del1].size();i++)
        {
            int v=e[i].to;
            for(int j=1;j<=n;j++) len[j]=1;
            getlen(v,0);
            st=fre[v];
            getlen(st,0);
            en=fre[st];
            int ll=len[st]+1;
            int now=(ll)/2;
            if(now>ans1) ans2=ans1,ans1=now;
            else if(now>ans2) ans2=now;
        }
        aaa=min(ans2,aaa);
        cout<<aaa<<endl;
        return ;
    }
}
int main()
{
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    c=read(),T=read();
    if(c<=3)
    {
        while(T--)
        {
            n=read(),k=read();
            tot=0;
            memset(h,0,sizeof(h));
            for(int i=1;i<n;i++)
            {
                int u=read(),v=read();
                build(u,v);
                build(v,u);
            }
            if(c<=3)
            {
                ans=1e9;
                dfs(0);
                cout<<ans<<endl;
            }
        }
        return 0;
    }
    if(c==7||c==11||c==12)
    {
        while(T--)
        {
            tot=0;
            memset(h,0,sizeof(h));
            n=read(),k=read();
            for(int i=1;i<n;i++)
            {
                int u=read(),v=read();
                build(u,v),build(v,u);
                g[u].push_back(v);
                g[v].push_back(v);
                bc[i].u=u,bc[i].v=v;
            }
            solve();
        }
    }
    return 0;
}