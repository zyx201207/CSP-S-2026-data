#include<bits/stdc++.h>
using namespace std;
const long long inf=1e18;
int c,n,m,d,q;
long long w[1000005];
long long e[505][505];
vector<long long> lx[1000005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    int K,a,t;
    for(int i=1;i<=n;i++)
    {
        cin>>K;
        for(int j=1;j<=K;j++)
        {
            cin>>a>>t;
            lx[a].push_back(i);
            lx[a].push_back(t);
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                e[i][j]=0;
            }
            else
            {
                e[i][j]=inf;
            }
        }
    }
    for(int x=1;x<=m;x++)
    {
        for(int i=0;i<lx[x].size();i+=2)
        {
            for(int j=0;j<lx[x].size();j+=2)
            {
                if(i!=j)
                {
                    e[lx[x][i]][lx[x][j]]=min(e[lx[x][i]][lx[x][j]],lx[x][i+1]+lx[x][j+1]);
                }
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int x=1;x<=n;x++)
        {
            if(e[x][k]==inf)
            {
                continue;
            }
            for(int y=1;y<=n;y++)
            {
                if(e[k][y]==inf)
                {
                    continue;
                }
                if(e[x][y]>e[x][k]+e[k][y])
                {
                    e[x][y]=e[x][k]+e[k][y];
                }
            }
        }
    }
    long long u,v,ans;
    while(q--)
    {
        cin>>u>>v;
        ans=inf;
        for(int i=0;i<lx[u].size();i+=2)
        {
            for(int j=0;j<lx[v].size();j+=2)
            {
                ans=min(ans,e[lx[u][i]][lx[v][j]]+lx[u][i+1]+lx[v][j+1]);
            }
        }
        cout<<ans+w[u]+w[v]<<"\n";
    }
    return 0;
}