#include<bits/stdc++.h>
using namespace std;
const  int maxn = 1e7+5;
long long c,n,m,d,q,qt[maxn];
long long w[maxn],k[maxn],x[maxn],y[maxn];
long long a[5000][5000],t[5000][5000];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i = 1;i<=n;i++)
    {
        cin>>k[i];
        for(int j = 1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
    }
    for(int i = 1;i<=q;i++)
    {
        cin>>x[i]>>y[i];
    }
    for (int v = 1;v<=q;v++)
    {
        qt[v]=(w[x[v]] + w[y[v]]);
        for(int i = 1;i<=n;i++)
        {
            for(int j = 1;j<=k[i];j++)
            {
                if(a[i][j]!=y[v])
                {
                    if(a[i][j]==x[v])
                    {
                        qt[v]+=t[i][j];
                    }
                }

                if(a[i][j]==y[v])
                {
                    qt[v]+=t[i][j];
                }
            }
        }
        cout<<qt[v]<<endl;
    }
    return 0;
}
