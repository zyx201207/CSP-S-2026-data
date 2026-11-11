#include <bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505];
long long f[1005][1005];
long long a[505][1005],t[505][1005];
struct node{
    int l,r;
}g[100005];
int main()
{
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    // cout<<1;
    for(int i=1;i<=m;i++) cin>>w[i];
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++) f[i][j]=1e18;
        f[i][i]=0;
    }
    // cout<<2;
    for(int i=1;i<=n;i++)
    {
        cin>>k[i];
        // cout<<k[i]<<" ";
        for(int j=1;j<=k[i];j++)
        {
            cin>>a[i][j]>>t[i][j];
            // cout<<j<<" ";
        }
        f[a[i][1]][a[i][2]]=f[a[i][2]][a[i][1]]=min(t[i][1]+t[i][2],f[a[i][1]][a[i][2]]);
    }
    // cout<<3;
    for(int u=1;u<=m;u++)
    {
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=m;j++)
            {
                f[i][j]=min(f[i][u]+f[u][j],f[i][j]);
                f[j][i]=f[i][j];
            }
        }
    }
    // cout<<4;
    for(int i=1;i<=q;i++) {
        int l,r;
        cin>>l>>r;
        cout<<f[l][r]+w[l]+w[r]<<"\n";
    }


    return 0;
}
