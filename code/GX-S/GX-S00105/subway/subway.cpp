#include <bits/stdc++.h>
using namespace std;
struct zt
{
    long long int bh;
    long long int jl;
};
int dtz[505][500005];
int j[505][500005];
vector<zt>a[500005];
queue<zt>b;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    long long int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    long long int x[n+5];
    long long int dtk[m+5];
    for(long long int i=1;i<=m;i++)cin>>dtk[i];
    for(long long int i=1;i<=n;i++)
    {
        cin>>x[i];
        for(long long int l=1;l<=x[i];l++)
        {
            cin>>dtz[i][l]>>j[i][l];
        }
    }
    for(long long int i=1;i<=n;i++)
    {
        for(long long int k=1;k<=x[i];k++)
        {
            for(long long int l=k+1;l<=x[i];l++)
            {
                zt g;
                g.bh=dtz[i][k];
                g.jl=j[i][k];
                a[dtz[i][k]].push_back(g);
                g.bh=dtz[i][l];
                g.jl=j[i][l];
                a[dtz[i][k]].push_back(g);
            }
        }
    }
    for(long long int i=0;i<q;i++)
    {
        long long int z,y;
        cin>>z>>y;
        bool t=1;
        for(int j=0;j<a[z].size();j++)
        {
            if(a[z][j].bh==y)
            {
                t=0;
                cout<<dtk[z]+dtk[y]+a[z][j-1].jl+a[z][j].jl<<endl;
            }
        }
        if(t)cout<<dtk[z]+dtk[y]+25<<endl;

    }
    return 0;
}
