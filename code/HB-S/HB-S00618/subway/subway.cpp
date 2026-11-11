#include <bits/stdc++.h>
#define int long long
using namespace std;
int c,n,m,d,q,a[500005],b[505][505],ans;
vector<int> v[500005],w[500005];
signed main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    scanf("%lld%lld%lld%lld%lld",&c,&n,&m,&d,&q);
    for(int i = 1;i<=m;i++)
    {
        scanf("%lld",&a[i]);
    }
    for(int i = 1,x;i<=n;i++)
    {
        scanf("%lld",&x);
        for(int j = 1,y,z;j<=x;j++)
        {
            scanf("%lld%lld",&y,&z);
            v[y].push_back(i);
            w[y].push_back(z);
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            b[i][j] = 1e18;
            if(i==j)
            {
                b[i][j] = 0;
            }
        }
    }
    for(int i = 1;i<=m;i++)
    {
        for(int j = 0;j<(int)v[i].size();j++)
        {
            for(int k = j+1;k<(int)v[i].size();k++)
            {
                if(b[v[i][j]][v[i][k]]==-1)
                {
                    b[v[i][j]][v[i][k]] = w[i][j]+w[i][k];
                    b[v[i][k]][v[i][j]] = w[i][j]+w[i][k];
                }
                else
                {
                    b[v[i][j]][v[i][k]] = min(w[i][j]+w[i][k],b[v[i][j]][v[i][k]]);
                    b[v[i][k]][v[i][j]] = min(w[i][j]+w[i][k],b[v[i][k]][v[i][j]]);
                }
            }
        }
    }
    for(int i = 1;i<=n;i++)
    {
        for(int j = 1;j<=n;j++)
        {
            for(int k = 1;k<=n;k++)
            {
                b[j][k] = min(b[j][k],b[j][i]+b[i][k]);
            }
        }
    }
    for(int i = 1,x,y;i<=q;i++)
    {
        scanf("%lld%lld",&x,&y);
        ans = 1e18;
        for(int j = 0;j<(int)v[x].size();j++)
        {
            for(int k = 0;k<(int)v[y].size();k++)
            {
                ans = min(ans,a[x]+a[y]+w[x][j]+w[y][k]+b[v[x][j]][v[y][k]]);
            }
        }
        printf("%lld\n",ans);
    }
    return 0;
}
