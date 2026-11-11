#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,p;
vector<pair<int,int>>v[500001];
long long ans[501]={};
int k[500001];
long long  dfs(long long x,long long y)
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=k[i];j++)
            if(v[i][j].first==x)
                for(int j=1;j<=k[i];j++)
                {
                    if(v[i][j].first!=x)
                    {
                        ans[v[i][j].first]=min(ans[v[i][j].first],ans[x]+v[i][j].second);
                        dfs(v[i][j].first,y);
                    }
                }
}
int main()
{
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long x,y;
    cin>>c>>n>>m>>d>>p;
    long long a[501];
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=m;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>x>>y;
            v[i].push_back({x,y});
        }
    }
    for(int i=1;i<=p;i++)
    {
        memset(ans,1e18,sizeof(ans));
        cin>>x>>y;
        dfs(x,y);
        cout<<ans[y]+a[x]+a[y]<<endl;
    }
    return 0;
}
