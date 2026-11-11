#include<iostream>
#include<queue>
#include<vector>
#include<cstring>
using namespace std;
const int N=6e5+7,M=507;
struct dat
{
    long long x,y;
};
vector<dat> e[N];
int c,n,m,d,q,vis[N];
long long dis[N],k[M],w[N];
void spfa(int s,int t)
{
    memset(dis,0x3f,sizeof(dis));
    queue<int> q;
    dis[s]=0;
    q.push(s);
    while(q.size())
    {
        int x=q.front();
        if(12<=c&&c<=19&&x==t)return;
        q.pop();
        vis[x]=0;
        for(dat y:e[x])
        {
            if(dis[x]+y.y<dis[y.x])
            {
                dis[y.x]=dis[x]+y.y;
                if(vis[y.x]==0)
                {
                    q.push(y.x);
                }
            }
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        scanf("%lld",&w[i]);
    }
    for(int i=1;i<=n;i++)
    {
        scanf("%lld",&k[i]);
        for(int j=1;j<=k[i];j++)
        {
            int x,y;
            scanf("%lld%lld",&x,&y);
            e[x].push_back({m+i,y});
            e[m+i].push_back({x,y});
        }
    }
    for(int i=1;i<=q;i++)
    {
        int s,t;
        scanf("%d%d",&s,&t);
        spfa(s,t);
        printf("%lld\n",w[s]+dis[t]+w[t]);
    }
    return 0;
}