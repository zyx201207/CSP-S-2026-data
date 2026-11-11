#define DEF 500005
#include <queue>
#include <stdio.h>
#include <utility>
#include <vector>
typedef long long ll;
struct edge
{int dist,head,next,to;}e[DEF*50+5];
bool flag[DEF*25];
int a,aa,k,t,ta,x,y;
int c,d,m,n,q;
int egcnt=0;
int w[DEF];
ll dist[DEF*25];
std::vector<int>v[DEF];
ll dijkstra(int from,int to)
{
    std::priority_queue<std::pair<ll,int>>q;
    q.push({0,from});
    while(!q.empty())
    {
        ll dis=q.top().first;
        int num=q.top().second;
        q.pop();
        if(flag[num])
            continue;
        dist[num]=dis,flag[num]=true;
        if(num==to)
            break;
        for(int i=e[num].head;i;i=e[i].next)
        {
            int t=e[i].to;
            if(!flag[t])
                q.push({1ll*dis+1ll*e[i].dist,t});
        }
    }
    return dist[to];
}
void create_edge(int u,int v,int dist=0)
{
    e[++egcnt].dist=dist;
    e[egcnt].next=e[u].head;
    e[egcnt].to=v;
    e[u].head=egcnt;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&c,&n,&m,&d,&q);
    for(int i=1;i<=m;++i)
    {
        scanf("%d",w+i);
        //地铁口-站厅
        create_edge(i,i+DEF,w[i]);
        create_edge(i+DEF,i,w[i]);
    }
    for(int i=1;i<=n;++i)
    {
        scanf("%d%d%d",&k,&aa,&ta);
        v[aa].push_back(i);
        int orda=v[aa].size();
        create_edge(aa+(orda+1)*DEF,aa+DEF,ta);
        create_edge(aa+DEF,aa+(orda+1)*DEF,ta);
        for(int j=2;j<=k;++j)
        {
            scanf("%d%d",&a,&t);
            v[a].push_back(i);
            int ord=v[a].size();
            create_edge(a+(ord+1)*DEF,a+DEF,t);
            create_edge(a+DEF,a+(ord+1)*DEF,t);
            create_edge(aa+(orda+1)*DEF,a+(ord+1)*DEF);
            create_edge(a+(ord+1)*DEF,aa+(orda+1)*DEF);
            aa=a,orda=ord,ta=t;
        }
    }
    while(q--)
    {
        scanf("%d%d",&x,&y);
        for(int i=1;i<=m;++i)
        {
            dist[i]=dist[i+DEF]=0x7f7f7f7f7f7f7f7f;
            flag[i]=flag[i+DEF]=false;
        }
        for(int i=1;i<=d;++i)
            for(int j=1;j<=m;++j)
                dist[j+(i+1)*DEF]=0x7f7f7f7f7f7f7f7f,flag[j+(i+1)*DEF]=false;
        dist[x]=0;
        printf("%lld\n",dijkstra(x,y));
    }
    return 0;
}
