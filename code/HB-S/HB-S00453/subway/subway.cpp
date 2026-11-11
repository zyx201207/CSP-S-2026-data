#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
int x,y;
int w[500005],k[505],a[505][500005],t[505][500005];
int mp[500005][500005],np[500005][500005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        for(int j=1;j<=k[i];j++)
        {
            mp[i][j]=1;
            np[i][j]=i;
            cin>>a[i][j]>>t[i][j];
        }
    }
    while(q--)
    {
        cin>>x>>y;
        if(mp[x][y])
        {
            int p=np[x][y];
            int ans=t[p][x]+t[p][y]+w[x]+w[y];
            cout<<ans<<'\n';
        }
    }
    return 0;
}

