#include<bits/stdc++.h>
using namespace std;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    int c, n, m, d, q, a[10000005];
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=n;i++)
    {
        int k, b[10000005];
        cin>>k;
        for(int j=1;j<=k;j++) cin>>b[j];
    }
    for(int i=1;i<=q;i++)
    {
        int x, y;
        cin>>x>>y;
        cout<<a[x]+a[y]<<endl;
    }
    return 0;
}