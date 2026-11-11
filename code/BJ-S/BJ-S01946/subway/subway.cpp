#include <bits/stdc++.h>
using namespace std;
long long c, n, m, d, q, f[505][505], w[5000005];
long long k[500005];
vector<long long> f1[500005], a[505], t[505];
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            long long o, p;
            cin>>o>>p;
            a[i].push_back(o);
            t[i].push_back(p);
            f1[a[i][j-1]].push_back(i);

        }
    }

    memset(f, 0x3f, sizeof(f));
    for(int i=1;i<=n;i++) f[i][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=i+1;j<=n;j++)
        {
            if(i==j) continue;
            for(int l=0;l<k[i];l++)
            {
                for(int r=0;r<k[j];r++)
                {
                    if(a[i][l]==a[j][r])
                    {
                        f[j][i]=f[i][j]=min(f[i][j], t[i][l]+t[j][r]);
                    }
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
                f[i][j]=min(f[i][j], f[i][k]+f[k][j]);
            }
        }
    }

    while(q--)
    {

        long long x, y, ans=0x3f3f3f3f3f3f;
        cin>>x>>y;
        if(x==y){cout<<0;continue;}
        for(long long i:f1[x])
        {
            for(long long j:f1[y])
            {
                long long x1t, y1t;
                for(int l=0;l<k[i];l++)
                {
                    if(a[i][l]==x) {x1t=t[i][l];break;}
                }
                for(int l=0;l<k[j];l++)
                {
                    if(a[j][l]==y) {y1t=t[j][l];break;}
                }
                ans=min(ans, f[i][j]+x1t+y1t);
            }
        }
        cout<<ans+w[x]+w[y]<<"\n";
    }
    return 0;
}
