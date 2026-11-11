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
const int INF=0x3f3f3f3f3f3f,N=510,M=5e5+10;
vector<pair<int,int>> g[M+N];
int w[M],d[M+N];
bool vis[M+N];
int c,n,m,d0,q,k,a,t,x,y,ans;
int dij(int s,int f)
{
    fill(d,d+m+n+1,INF);
    memset(vis,0,sizeof vis);
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
            if(d[u]+w<d[v])
            {
                d[v]=d[u]+w;
                q.push({d[v],v});
            }
        }
    }
    return d[f];
}
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),n=read(),m=read(),d0=read(),q=read();
    for(int i=1;i<=m;++i)w[i]=read();
    for(int i=1;i<=n;++i)
    {
        k=read();
        for(int j=1;j<=k;++j)
        {
            a=read(),t=read();
            g[a].push_back({i+m,t});
            g[i+m].push_back({a,t});
        }
    }

    while(q--)
    {
        x=read(),y=read();
        ans=w[x]+w[y];
        ans+=dij(x,y);
        write(ans);
        puts("");
    }
    return 0;
}
