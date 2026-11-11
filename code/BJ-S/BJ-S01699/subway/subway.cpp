#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
using namespace std;
int c,m,n,d,q;
struct A
{
    long long x,y;
};
bool operator <(A x,A y)
{
    return x.y>y.y;
}
vector<A> v[100010];
long long dis[510][510],a[100010];
int f[510][100010];
int vis[510];
void dij()
{
    for(int i=1;i<=n;i++)
    {
        priority_queue <A> q;
        q.push((A){i,0});
        while(!q.empty())
        {
            int nx=q.top().x,ny=q.top().y;
            q.pop();
            if(vis[nx]==i)continue;
            vis[nx]=i;
            //cout<<nx<<endl;
            for(int j=1;j<=n;j++)
            {
                //cout<<dis[i][j]<<" "<<dis[i][nx]+dis[nx][j]<<endl;
                //cout<<i<<' '<<nx<<" "<<j<<' '<<endl;
                if(dis[i][j]<dis[i][nx]+dis[nx][j])continue;
                dis[i][j]=dis[i][nx]+dis[nx][j];
                q.push((A){j,dis[i][nx]+dis[nx][j]});
            }
        }
    }
}
long long check(int x,int y,int t)
{
    long long ans=1e18;
    for(int i=0;i<v[x].size();i++)
    {
        for(int j=0;j<v[y].size();j++)
        {
            int nx=v[x][i].x,ny=v[y][j].x;
            ans=min(ans,dis[nx][ny]+f[nx][x]+f[ny][y]);
        }
    }
    return ans;

}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>a[i];
    for(int i=1;i<=n;i++)dis[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        int p;
        cin>>p;
        for(int j=1;j<=p;j++)
        {
            int x,y;
            cin>>x>>y;
            v[x].push_back((A){i,y});
            f[i][x]=y;
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<v[i].size();j++)
        {
            for(int k=j+1;k<v[i].size();k++)
            {
                dis[v[i][j].x][v[i][k].x]=v[i][j].y+v[i][k].y;
                dis[v[i][k].x][v[i][j].x]=v[i][j].y+v[i][k].y;
                //cout<<dis[v[i][j].x][v[i][k].x]<<' '<<v[i][j].x<<' '<<v[i][k].x<<endl;
            }
        }
    }
    dij();
    //for(int i=1;i<=n;i++)
    //{////
       //for(int j=1;j<=n;j++)cout<<dis[i][j]<<' ';
        //cout<<endl;
    //}
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        //cout<<1<<endl;
        cout<<check(x,y,i)+a[x]+a[y]<<endl;
    }
}