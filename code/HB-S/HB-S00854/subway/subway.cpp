#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q,k,x,y;
    cin>>c>>n>>m>>d>>q;
    int a[505][500005];
    int t[505][500005];
    int h=0;
    int w[500005];
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k;
        for(int j=1;j<=k;j++)
            cin>>a[i][j]>>t[i][j];
    }
    for(int i=1;i<=q;i++)
    {
        cin>>x>>y;
        h=h+w[x]+t[1][1]+t[1][2]+t[2][2]+t[2][y]+w[y];
    }
    cout<<h;
    return 0;
}
