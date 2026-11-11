#include<iostream>
#include<limits>
#include<vector>
using namespace std;
using ll=long long;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    vector<ll> w(m+1);
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    vector<vector<pair<int,ll>>> rs_edges(m+1);
    for(int i=1;i<=n;i++)
    {
        int k;
        cin>>k;
        for(int j=1;j<=k;j++)
        {
            int a;
            ll t;
            cin>>a>>t;
            rs_edges[a].emplace_back(i,t);
        }
    }
    vector<vector<ll>> F(n+1,vector<ll>(n+1,numeric_limits<ll>::max()>>1));
    for(int i=1;i<=n;i++)
    {
        F[i][i]=0;
    }
    for(int i=1;i<=m;i++)
    {
        for(int j=0;j<rs_edges[i].size();j++)
        {
            for(int k=0;k<rs_edges[i].size();k++)
            {
                if(j!=k)
                {
                    ll weight=rs_edges[i][j].second+rs_edges[i][k].second;
                    F[rs_edges[i][j].first][rs_edges[i][k].first]=min(F[rs_edges[i][j].first][rs_edges[i][k].first],weight);
                }
            }
        }
    }
    for(int k=1;k<=n;k++)
    {
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                F[i][j]=min(F[i][j],F[i][k]+F[j][k]);
            }
        }
    }
    for(int i=1;i<=q;i++)
    {
        int x,y;
        cin>>x>>y;
        ll res=numeric_limits<ll>::max()>>1;
        for(int j=0;j<rs_edges[x].size();j++)
        {
            for(int k=0;k<rs_edges[y].size();k++)
            {
                res=min(res,rs_edges[x][j].second+F[rs_edges[x][j].first][rs_edges[y][k].first]+rs_edges[y][k].second);
            }
        }
        res+=w[x]+w[y];
        cout<<res<<'\n';
    }
}
