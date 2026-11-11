#include<bits/stdc++.h>
using namespace std;
const int N=10005;
const int M=5e5+5;
int c,n,m,d,q;
int w[M];
int k[M];
vector<int> a[505],t[505];
int ge[M];
struct Edge
{
    int v,nxt,w;
} e[5*M];
int head[5*M],cnt;
void add(int u,int v,int w)
{
    cnt++;
    e[cnt].v=v;
    e[cnt].w=w;
    e[cnt].nxt=head[u];
    head[u]=cnt;
}
int xia;
long long dis[5*M];
struct Node
{
    int u,val;
    bool operator < (const Node &tmp_1) const
    {
        return val>tmp_1.val;
    }
};
int vit[5*M];
void dij(int s)
{
    for(int i=1;i<=xia;i++) dis[i]=-1,vit[i]=0;
    dis[s]=0;
    priority_queue<Node> q;
    q.push({s,dis[s]});
    while(q.size())
    {
        int u=q.top().u;
        q.pop();
        if(vit[u]) continue;
        vit[u]=1;
        for(int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].v,w=e[i].w;
            if(vit[v]) continue;
            if(dis[v]==-1 || dis[v]>dis[u]+w)
            {
                dis[v]=dis[u]+w;
                q.push({v,dis[v]});
            }
        }
    }
}
long long di[505][505];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            long long x,y;
            cin>>x>>y;
            a[i].push_back(x),t[i].push_back(y);
        }
    }
    if(1<=c && c<=8)
    {
        xia=m;
        long long bef=m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                add(bef+1,a[i][j-1],t[i][j-1]);
                add(a[i][j-1],bef+1,t[i][j-1]);
                //cout<<bef+1<<" "<<a[i][j-1]<<"\n";
                bef++;
                xia++;
            }
        }
        bef=m;
        for(int i=1;i<=n;i++)
        {
            xia++;
            for(int j=1;j<=k[i];j++)
            {
                add(bef+1,xia,0);
                add(xia,bef+1,0);
                //cout<<xia<<" "<<bef+1<<"\n";
                bef++;
            }
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            dij(x);
            cout<<dis[y]+w[x]+w[y]<<"\n";
        }
    }
    else 
    {
        xia=m;
        long long bef=m;
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=k[i];j++)
            {
                add(bef+1,a[i][j-1],t[i][j-1]);
                add(a[i][j-1],bef+1,t[i][j-1]);
                //cout<<bef+1<<" "<<a[i][j-1]<<"\n";
                bef++;
                xia++;
            }
        }
        bef=m;
        for(int i=1;i<=n;i++)
        {
            xia++;
            for(int j=1;j<=k[i];j++)
            {
                add(bef+1,xia,0);
                add(xia,bef+1,0);
                //cout<<xia<<" "<<bef+1<<"\n";
                bef++;
            }
        }
        for(int i=1;i<=m;i++)
        {
            dij(i);
            for(int j=1;j<=m;j++) di[i][j]=dis[j];
        }
        while(q--)
        {
            int x,y;
            cin>>x>>y;
            cout<<di[x][y]+w[x]+w[y]<<"\n";
        }
    }
    return 0;
}
