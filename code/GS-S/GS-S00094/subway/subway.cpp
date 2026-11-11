#include <bits/stdc++.h>

using namespace std;

int c,n,m,q,q1,w[1005],d[1005][1005];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    memset(d,0x3f,sizeof d);
    cin >> c >> n >> m >> q1 >> q;
    for(int i=0; i<=m; i++) d[i][i]=0;
    for(int i=1; i<=m; i++) cin >> w[i];
    for(int i=1; i<=n; i++)
    {
        int k,a1,a2,t1,t2;
        cin >> k;
        for(int j=1; j<=k; j++)
        {
            cin >> a1 >> t1 >> a2 >> t2;
            d[a1][a2]=t1+t2;
        }
    }
    for(int k=1; k<=m; k++)
    {
        for(int i=1; i<=m; i++)
        {
            for(int j=1; j<=m; j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
        }
    }
    int x,y;
    for(int i=1; i<=q; i++)
    {
        cin >> x >> y;
        int ans=d[x][y]+w[x]+w[y];
        cout << ans << '\n';
    }
    return 0;
}
