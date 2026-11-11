#include <bits/stdc++.h>
using namespace std;
int n,m,w[500005],a[505][500005],c,lllll,q,d[500005],t[505][500005],k[505],y,z;
vector<pair<int,int>> e[500005];
void distance(int x)
{
    for(int i=1;i<=m;i++)
    {
        d[i]=0x3f3f3f3f;
    }
    d[y]=0;
    for(auto[u,l]:e[x])
    {

        if(d[u]>d[x]+l)
        {
            d[u]=d[x]+l;
            distance(u);
        }
    }
}
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>lllll>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>w[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
        }
        for(int j=1;j<=k[i];j++)
        {
            for(int f=j;f<=k[i];f++)
            {
                e[a[i][j]].push_back({a[i][f],t[i][j]+t[i][f]});
            }
        }
    }
    while(q--)
    {
        cin>>y>>z;
        distance(y);
        cout<<d[z]+w[y]+w[z]<<endl;
    }
    return 0;
}