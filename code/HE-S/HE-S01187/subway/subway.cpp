#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
long long w[500010];
long long dis[510][510];
struct jade
{
    int id;
    long long t;
};
vector <jade> node[500010];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(dis,0x3f,sizeof(dis));
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        dis[i][i]=0;
        int cnt;
        cin>>cnt;
        for(int j=1;j<=cnt;j++)
        {
            int x;
            long long t;
            cin>>x>>t;
            node[x].push_back({i,t});
        }
    }
    for(int i=1;i<=m;i++)
    {
        for(jade x:node[i])
        {
            for(jade y:node[i])
            {
                if(x.id==y.id)
                {
                    continue;
                }
                dis[x.id][y.id]=x.t+y.t;
                dis[y.id][x.id]=x.t+y.t;
            }
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i==j)
            {
                continue;
            }
            for(int k=1;k<=n;k++)
            {
                if(i==k||j==k)
                {
                    continue;
                }
                if(dis[i][j]>dis[i][k]+dis[k][j])
                {
                    dis[i][j]=dis[i][k]+dis[k][j];
                }
            }
        }
    }
    while(q--)
    {
        int x,y;
        cin>>x>>y;
        long long ans=w[x]+w[y];
        long long res=2e18;
        for(jade i:node[x])
        {
            for(jade j:node[y])
            {
                res=min(res,i.t+j.t+dis[i.id][j.id]);
            }
        }
        cout<<ans+res<<'\n';
    }
    return 0;
}

