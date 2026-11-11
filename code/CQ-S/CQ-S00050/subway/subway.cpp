#include<iostream>
#include<cstdio>
#include<vector>
#include<cstring>
using namespace std;
struct node
{
    int id;
    long long t;
};
long long w[500001];
long long dis[501][501];
vector<node>v[500001];
node tonode(int nid,long long nt)
{
    node ret;
    ret.id=nid;
    ret.t=nt;
    return ret;
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    memset(dis,0x3f,sizeof(dis));
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
        int k;
        cin>>k;
        while(k--)
        {
            int a;
            long long t;
            cin>>a>>t;
            v[a].push_back(tonode(i,t));
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            for(int k=0;k<v[i].size();k++)
            {
                if(j!=k)dis[v[i][j].id][v[i][k].id]=v[i][j].t+v[i][k].t;
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long minn=0x3f3f3f3f3f3f3f3f;
        for(int i=0;i<v[x].size();i++)
        {
            for(int j=0;j<v[y].size();j++)
            {
                minn=min(minn,w[x]+w[y]+dis[v[x][i].id][v[y][j].id]+v[x][i].t+v[y][j].t);
            }
        }
        cout<<minn<<"\n";
    }
    return 0;
}
