#include <bits/stdc++.h>
#define int long long 
using namespace std;
const int N=500;
const int M=5e5;
const int D=20;

int c,n,m,d,_T,w[M+10];

struct edge
{
    int v,tt;
};
vector<edge>tr[M+10],a[N+10];

bool cg[N+10][N+10];
int g[N+10][N+10];

int in()
{
    char c=getchar();
    while(!('0'<=c&&c<='9')&&c!=EOF)c=getchar();
    int num=0;
    while(('0'<=c&&c<='9')&&c!=EOF)
    {
        num=(num<<1)+(num<<3)+c-'0';
        c=getchar();
    }
    return num;
}

void out(int num)
{
    if(num>=10)out(num/10);
    putchar(num%10+'0');
}

vector<edge>G[N+10];

void addedgetoG(int u,int v,int w)
{
    G[u].push_back({v,w});
}

int dis[N+10];
bool vis[N+10];

struct node
{
    int u,dd;
    bool operator<(node n1) const
    {
        return dd>n1.dd;
    }
};
priority_queue<node>q;

void dij(int s)
{
    for(int i=1;i<=n;i++)
    {
        dis[i]=1e18;
        vis[i]=0;
    }
    dis[s]=0;
    q.push({s,0});
    while(!q.empty())
    {
        int u=q.top().u;
        q.pop();
        if(vis[u])continue;
        vis[u]=1;
        for(int v=1;v<=n;v++)
        {
            if(!cg[u][v])continue;
            if(dis[u]+g[u][v]<dis[v])
            {
                dis[v]=dis[u]+g[u][v];
                q.push({v,dis[v]});
            }
        }
    }
}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    // scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&_T);
    c=in();n=in();m=in();d=in();_T=in();
    for(int i=1;i<=m;i++)
    {
        // scanf("%lld",&w[i]);
        w[i]=in();
    }
    for(int i=1;i<=n;i++)
    {
        // scanf("%lld",&ak[i]);
        int ak=in();
        for(int j=1;j<=ak;j++)
        {
            // scanf("%lld",&a[i][j]);
            int tmpv=in();
            // scanf("%lld",&t[i][j]);
            int tmpt=in();
            tr[tmpv].push_back({i,tmpt});
            a[i].push_back({tmpv,tmpt});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            g[i][j]=1e17;
        }
        g[i][i]=0;
        cg[i][i]=1;
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<a[i].size();j++)
        {
            int aa=a[i][j].v;
            int at=a[i][j].tt;
            for(int k=0;k<tr[aa].size();k++)
            {
                int v=tr[aa][k].v,tt=tr[aa][k].tt;
                cg[v][i]=cg[i][v]=1;
                g[v][i]=g[i][v]=min(g[i][v],at+tt);
            }
        }
    }
    // for(int i=1;i<=n;i++)
    // {
    //     for(int j=1;j<=n;j++)
    //     {
    //         if(i!=j&&cg[i][j])
    //         {
    //             addedgetoG(i,j,g[i][j]);
    //         }
    //     }
    // }
    for(int i=1;i<=n;i++)
    {
        // dij(i);
        // for(int j=1;j<=n;j++)
        // {
        //     if(vis[j])
        //     {
        //         g[j][i]=g[i][j]=dis[j];
        //         cg[j][i]=cg[i][j]=1;
        //     }
        // }
        for(int j=1;j<=n;j++)
        {
            for(int k=1;k<=n;k++)
            {
                if(cg[i][k]&&cg[k][j])
                {
                    cg[i][j]=cg[j][i]=1;
                    if(g[i][k]+g[k][j]<g[i][j])
                    {
                        g[j][i]=g[i][j]=g[i][k]+g[k][j];
                    }
                }
            }
        }
    }
    while(_T--)
    {
        int x,y;
        scanf("%lld%lld",&x,&y);
        int ans=1e18;
        for(int i=0;i<tr[x].size();i++)
        {
            int u=tr[x][i].v,ut=tr[x][i].tt;
            for(int i=0;i<tr[y].size();i++)
            {
                int v=tr[y][i].v,vt=tr[y][i].tt;
                if(cg[u][v])
                {
                    ans=min(ans,ut+g[u][v]+vt);
                }
            }
        }
        out(ans+w[x]+w[y]);
        putchar('\n');
    }

    return 0;
}