#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
const int M=5e5+10;
int c,n,m,d,q;
ll dis[N][N],w[M];
vector<pair<ll,int> > a[M];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        int k,x,w;cin>>k;
        for(int j=1;j<=k;j++)
        {
            cin>>x>>w;
            a[x].push_back({w,i});
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
            dis[i][j]=(ll)1e18;
        dis[i][i]=0;
    }
    int x,i,j;
    for(x=1;x<=m;x++)
    {
        for(i=0;i<a[x].size();i++)
        {
            for(j=i+1;j<a[x].size();j++)
            {
                dis[a[x][i].second][a[x][j].second]=min(dis[a[x][i].second][a[x][j].second],a[x][i].first+a[x][j].first);
                dis[a[x][j].second][a[x][i].second]=dis[a[x][i].second][a[x][j].second];
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(i=1;i<n;i++)
        {
            for(j=i+1;j<=n;j++)
            {
                if(i!=k and j!=k)
                {
                    if(dis[i][k]==dis[k][j] and dis[i][k]==(ll)1e18) continue;
                    dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
                    dis[j][i]=dis[i][j];
                }
            }
        }
    }
    while(q--)
    {
        ll y,ans=(ll)1e18;
        cin>>x>>y;
        for(i=0;i<a[x].size();i++)
        {
            for(j=0;j<a[y].size();j++)
            {
                if(dis[a[x][i].second][a[y][j].second]==(ll)1e18) continue;
                ans=min(ans,dis[a[x][i].second][a[y][j].second]+a[x][i].first+a[y][j].first);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
