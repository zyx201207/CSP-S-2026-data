#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=550;
const int M=1e3+10;
int c,n,m,d,q;
int w[M],t[M][N],deg[M],f[M][25],cnt[M];
ll dis[M][M];
vector <int> a[N];
struct node
{
    int x,w;
};
vector <node> g[N];
bool operator <(node x,node y)
{
    return x.w>y.w;
}
void dijkstra(int s)
{
    dis[s][s]=w[s];
    priority_queue <node> q;
    q.push({s,w[s]});
    while(!q.empty())
    {
        node t=q.top();
        q.pop();
        if(t.w!=dis[s][t.x]) continue;
        for(auto i:g[t.x])
        {
            if(dis[s][i.x]>dis[s][t.x]+i.w)
            {
                dis[s][i.x]=dis[s][t.x]+i.w;
                q.push({i.x,dis[s][i.x]});
            }
        }
    }
}
int main()
{

    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof dis);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;i++) scanf("%d",&w[i]);
    for(int i=1,k;i<=n;i++)
    {
        scanf("%d",&k);
        a[i].push_back(k);
        for(int j=1,x,tt;j<=k;j++)
        {
            scanf("%d%d",&x,&tt);
            a[i].push_back(x);
            t[x][i]=tt;
            deg[x]++;
            f[x][++cnt[x]]=i;
        }
    }
    for(int i=1,k;i<=n;i++)
    {
        k=a[i][0];
        for(int j=1;j<=k;j++)
        {
            if(deg[a[i][j]]<=1) continue;
            for(int q=1;q<=k;q++)
            {
                if(q==j) continue;
                g[a[i][q]].push_back({a[i][j],t[a[i][q]][i]+t[a[i][j]][i]});
                g[a[i][j]].push_back({a[i][q],t[a[i][q]][i]+t[a[i][j]][i]});
            }
        }
    }
    if(n==2&&m>1e5)
    {
        while(q--)
        {
            int x,y,ans=1e9,flag=0;
            scanf("%d%d",&x,&y);
            for(int i=1;i<=cnt[x];i++)
            {
                for(int j=1;j<=cnt[y];j++)
                {
                    if(f[x][i]==f[y][j])
                    {
                        int num=f[x][i];
                        flag=1;
                        ans=w[x]+w[y]+t[x][num]+t[y][num];
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag)
            {
                dijkstra(x);
                dis[x][y]+w[y];
            }
            printf("%lld\n",ans);
        }
    }
    else
    {
        for(int i=1;i<=m;i++)
        {
            dijkstra(i);
        }
        while(q--)
        {
            int x,y,ans=1e9,flag=0;
            scanf("%d%d",&x,&y);
            for(int i=1;i<=cnt[x];i++)
            {
                for(int j=1;j<=cnt[y];j++)
                {
                    if(f[x][i]==f[y][j])
                    {
                        int num=f[x][i];
                        flag=1;
                        ans=w[x]+w[y]+t[x][num]+t[y][num];
                        break;
                    }
                }
                if(flag) break;
            }
            if(!flag)
            {
                ans=dis[x][y]+w[y];
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
