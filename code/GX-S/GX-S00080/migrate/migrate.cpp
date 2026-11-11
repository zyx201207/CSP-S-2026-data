#define DEF 2000005
#include <queue>
#include <stdio.h>
#include <utility>
using namespace std;
struct edge
{int head,next,to;}e[DEF*2];
int ans,c,egcnt,t;
int d,dis[DEF],n=0,upt[DEF],x[DEF];
void create_edge(int u,int v)
{
    e[++egcnt].next=e[u].head;
    e[egcnt].to=v;
    e[u].head=egcnt;
}
void dijkstra(int u)
{
    priority_queue<pair<int,int>>q;
    q.push({0,u});
    while(!q.empty())
    {
        int dist=q.top().first,num=q.top().second;
        q.pop();
        if(dist>dis[num])
            continue;
        dis[num]=dist;
        ++upt[num];
        if(upt[num]==2)++ans;
        else if(upt[num]==3)--ans;
        for(int i=e[num].head;i;i=e[i].next)
        {
            int to=e[i].to;
            if(dis[num]+1<=dis[to])
                q.push({dis[num]+1,to});
        }
    }
}
int main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    scanf("%d%d",&c,&t);
    while(t--)
    {
        ans=egcnt=0;
        for(int i=1;i<=n;++i)
        {
            dis[i]=0x3f3f3f3f;
            upt[i]=0;
        }
        scanf("%d%d",&n,&d);
        int l=1;
        for(int i=1;i<=n;++i)
        {
            scanf("%d",x+i);
            while(x[i]-x[l]>d)
                ++l;
            for(int j=l;j<i;++j)
                create_edge(j,i);
        }
        for(int i=1;i<=n;++i)
        {
            for(int j=1;j<=n;++j)
            {
                dis[j]=0x3f3f3f3f;
                upt[j]=0;
            }
            dijkstra(i);
        }
        printf("%d\n",ans);
    }
    return 0;
}
