#include<bits/stdc++.h>
using namespace std;
const int N=6e5;
int T,n,m,d,r;
vector <int> e[N];
int dis[N];
bool book[N];
void spfa(int s,int tm)
{
    queue <int> q;
    for(int i=1;i<=tm;i++)
    {
        dis[i]=INT_MAX;
        book[i]=0;
    }
    dis[s]=0;
    q.push(s);
    book[s]=1;
    while(!q.empty())
    {
        int u=q.front();
        for(int i=0;i<e[u].size();i+=2)
        {
            int v=e[u][i],w=e[u][i+1];
            if(dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                if(book[v]==0)
                {
                    q.push(v);
                    book[v]=1;
                }
            }
        }
        book[u]=0;
        q.pop();
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%d%d%d%d%d",&T,&m,&n,&d,&r);
    for(int i=1;i<=n;i++)
    {
        int t;
        scanf("%d",&t);
        e[i].push_back(n+i);
        e[i].push_back(t);
        e[n+i].push_back(i);
        e[n+i].push_back(t);
    }
    for(int i=1;i<=m;i++)
    {
        int k;
        scanf("%d",&k);
        for(int j=1;j<=k;j++)
        {
            int x,y;
            scanf("%d%d",&x,&y);
            e[n+x].push_back(n+n+i);
            e[n+x].push_back(y);
            e[n+n+i].push_back(n+x);
            e[n+n+i].push_back(y);
        }
    }
    int sm=n+n+m;

    for(int i=1;i<=r;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        spfa(x,sm);
        printf("%d\n",dis[y]);
    }
}
/*
dtk : 1~n;
zt:n+1~n+n;
xl:n+n+1~n+n+m;
spfa:O(r*(2*n+m)*m) 20~40pts
dij:O(r*(2*n+m)^2)?
*/