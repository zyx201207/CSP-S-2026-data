#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
int _,n,m,_1,q;
long long stw[500005];
struct edge
{
    int v;
    long long w;
};
vector<edge> e[500005];
long long dis[505][505];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>_>>n>>m>>_1>>q;
    for(int i=1;i<=m;i++) cin>>stw[i];
    for(int i=1;i<=n;i++)
        for(int j=1;j<i;j++)
            dis[i][j]=dis[j][i]=10000000000000;
    for(int i=1,k;i<=n;i++)
    {
        cin>>k;
        for(int j=1,u;j<=k;j++)
        {
            long long wu;
            cin>>u>>wu;
            for(auto eg:e[u])
                dis[i][eg.v]=dis[eg.v][i]=min(dis[i][eg.v],wu+eg.w);
            e[u].push_back((edge){i,wu});
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
            {
                if(dis[i][k]+dis[k][j]<dis[i][j]) 
                    dis[i][j]=dis[i][k]+dis[k][j];
            }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=10000000000000;
        for(auto ex:e[x])
        {
            for(auto ey:e[y])
                ans=min(ans,ex.w+dis[ex.v][ey.v]+ey.w);
        }
        cout<<stw[x]+ans+stw[y]<<"\n";
    }
    return 0;
}