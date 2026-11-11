#include<bits/stdc++.h>
#define ll long long
using namespace std;
long long int read()
{
    long long int x=0;
    char c=getchar();
    while(c<'0'||c>'9') c=getchar();
    while(c>='0'&&c<='9') x=(x<<1)+(x<<3)+c-'0',c=getchar();
    return x;
}
long long int dis[501][501],w[500001];
int c,n,m,d,q;
vector<pair<int,long long int>> a[500001];
int main()
{
  freopen("subway.in","r",stdin);
  freopen("subway.out","w",stdout);
    c=read();
    n=read();
    m=read();
    d=read();
    q=read();
    memset(dis,0x3f,sizeof dis);
    for(int i=1;i<=m;i++) w[i]=read();
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
        int k=read();
        while(k--)
        {
            int x;
            long long t;
            x=read();
            t=read();
            a[x].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(int x=0;x<a[i].size();x++)
        {
            for(int y=x+1;y<a[i].size();y++)
            {
                dis[a[i][y].first][a[i][x].first]=dis[a[i][x].first][a[i][y].first]=
                min(dis[a[i][x].first][a[i][y].first],a[i][x].second+a[i][y].second);
            }
        }
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
    while(q--)
    {
        int x,y;
        x=read();
        y=read();
        long long ans=LLONG_MAX;
        for(int i=0;i<a[x].size();i++)
            for(int j=0;j<a[y].size();j++)
                ans=min(ans,a[x][i].second+a[y][j].second+dis[a[x][i].first][a[y][j].first]);
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
