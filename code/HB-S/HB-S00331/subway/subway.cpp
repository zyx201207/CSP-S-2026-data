#include <bits/stdc++.h>
#define int long long
using namespace std;

const int N=5e5+5,M=505,INF=1e18;
int c,n,m,d,q,k,a,t,x,y,ans;
int w[N],dis[M][M];
int cnt,head[N];

struct edge {int v,w,next;};
edge e[N*3];

inline void add (int u,int v,int w)
{
    cnt++;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].next=head[u];
    head[u]=cnt;
}

inline int read ()
{
    int x=0,f=1;
    char c=getchar();
    while (c<'0'||c>'9')
    {
        if (c=='-') f=-f;
        c=getchar();
    }
    while (c>='0'&&c<='9')
    {
        x=x*10+c-'0';
        c=getchar();
    }
    return x*f;
}

inline int minn (int a,int b) {return (a<b)?a:b;}

signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    c=read(),m=read(),n=read(),d=read(),q=read();
    //cout<<n<<' '<<m<<' '<<d<<' '<<q;
    for (int i=1;i<=n;i++) w[i]=read();
    for (int i=1;i<=m;i++)
    {
        cin>>k;
        for (int j=1;j<=k;j++) a=read(),t=read(),add(a,i,t);
    }
    for (int i=1;i<=m;i++) for (int j=1;j<=m;j++) if (i!=j) dis[i][j]=INF;
    for (int i=1;i<=n;i++)
    {
        for (int p=head[i];p;p=e[p].next)
        {
            x=e[p].v,t=e[p].w;
            for (int q=head[i];q;q=e[q].next)
            {
                y=e[q].v;
                dis[x][y]=dis[y][x]=minn(dis[x][y],t+e[q].w);
                //printf("(%d %d %d %d %d)\n",i,x,y,t,e[q].w);
            }
        }
    }
    for (int k=1;k<=m;k++)
        for (int i=1;i<=m;i++)
            for (int j=1;j<=m;j++)
                dis[i][j]=dis[j][i]=minn(dis[i][j],dis[i][k]+dis[k][j]);
    //for (int i=1;i<=m;i++) for (int j=1;j<=m;j++) printf("[%d %d %lld]\n",i,j,dis[i][j]);
    while (q--)
    {
        x=read(),y=read();
        ans=INF;
        for (int p=head[x];p;p=e[p].next)
        {
            for (int q=head[y];q;q=e[q].next)
            {
                ans=minn(ans,dis[e[p].v][e[q].v]+e[p].w+e[q].w);
            }
        }
        cout<<ans+w[x]+w[y]<<'\n';
    }
    return 0;
}

