#include <iostream>
#include <cstring>
#include <vector>
#define N 505
#define M 500005
using namespace std;

int c,n,m,d,q;
int w[M], k[N];
int f[500][500];//floyd

vector< pair<int,int> > t;
vector<int> g[M];//linjie

inline int read()
{
    char c;
    for(c=getchar(); c>'9' && c<'0'; c=getchar());
    int x;
    for(x=0; c<='9' && c>='0'; c=getchar())
    {
        x=(x<<3)+(x<<1)+(c^48);
    }
    return x;
}

bool vis[M];
int T;
int qu[M],l,r, endv, dis[M];
void bfs(int u)
{
    for(int v : g[u])
    {
        if(vis[v]!=0)continue;
        if(v==endv)
        {
            dis[v]=dis[u]+T;
            return;
        }
        //cout<<v<<endl;
        qu[++r]=v;
        vis[v]=1;
        dis[v]=dis[u]+T;
    }
    bfs(qu[l++]);
}

int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    c=read(), n=read(), m=read(), d=read(), q=read();
    for(int i=1; i<=m; ++i)
    {
        w[i]=read();
    }
    int total=0;
    for(int i=1; i<=n; ++i)
    {
        k[i]=read();
        total+=k[i];
        for(int j=1; j<=k[i]; ++j)
        {
            int x=read(), xt=read();
            T=xt;
            t.push_back(make_pair(x,xt));
        }
    }
    if(c>=12 && c<=19)//c>=12 && c<=19
    {
        int cnt=0,i=total+1;
        for(auto p : t)
        {
            g[p.first].push_back(i);
            g[i].push_back(p.first);
            ++cnt;
            if(cnt==k[i-total])
            {
                ++i;
                cnt=0;
            }
        }
        for(int i=1; i<=q; ++i)
        {
            memset(vis, 0, sizeof(vis));
            memset(dis, 0, sizeof(dis));
            int u=read();
            endv=read();
            vis[0]=vis[u]=1;
            l=1, r=0;
            bfs(u);
            printf("%d\n", dis[endv]+w[u]+w[endv]);
        }
    }
    else
    {
        //floyd
        memset(f, 0x3f, sizeof(f));
        int cnt=0,i=total+1;
        for(auto p : t)
        {
            f[p.first][i]=p.second;
            f[i][p.first]=p.second;
            ++cnt;
            if(cnt==k[i-total])
            {
                ++i;
                cnt=0;
            }
        }
        int endi=i;
        for(int k=1; k<=endi; ++k)
        {
            for(i=1; i<=endi; ++i)
            {
                for(int j=1; j<=endi; ++j)
                {
                    f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
                }
            }
        }
        for(i=1; i<=q; ++i)
        {
            int u=read(), v=read();
            printf("%d\n", f[u][v]+w[u]+w[v]);
        }
    }
    return 0;
}

