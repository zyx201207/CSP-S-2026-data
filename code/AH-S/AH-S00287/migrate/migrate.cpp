#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch))
    {
        if(ch=='-')f=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        x=x*10+(ch-'0');
        ch=getchar();
    }
    return x*f;
}
inline void write(int x)
{
    if(x<0)
    {
        putchar('-');
        x=-x;
    }
    if(x>9)write(x/10);
    putchar(x%10+'0');
}
const int INF=0x3f3f3f3f3f3f,N=2e6+10;
map<int,map<int,int>> k;
vector<pair<int,int>> g[N];
int x[N],d[N];
bool vis[N];
int c,t,n,d0,ans;
bool dij(int s,int f)
{
    fill(d,d+n+1,INF);
    memset(vis,0,sizeof vis);
    k.clear();
    d[s]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> q;
    q.push({0,s});
    while(!q.empty())
    {
        int dis=q.top().first;
        int u=q.top().second;
        q.pop();
        if(vis[u])continue;
        vis[u]=true;
        for(auto &e:g[u])
        {
            int v=e.first;
            int w=e.second;
            if(d[u]+w==d[v])k[v][d[v]]++;
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
    return k[f][d[f]]==1?true:false;
}
signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    c=read(),t=read();
    while(t--)
    {
        ans=0;
        n=read(),d0=read();
        for(int i=1;i<=n;++i)x[i]=read();
        for(int i=1;i<n;++i)
            for(int j=i+1;j<=n;++j)
                g[i].push_back({j,x[j]-x[i]});
        for(int i=1;i<n;++i)
            for(int j=i+1;j<=n;++j)
                if(dij(i,j))ans++;
        write(ans);
        puts("");
    }
    return 0;
}
