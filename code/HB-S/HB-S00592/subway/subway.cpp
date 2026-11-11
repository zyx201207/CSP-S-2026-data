#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int M=5e5+5;
ll c,n,m,d,q,w[M],k,a[4005][4005],t[4005][4005],x,y;
void solve()
{
    cin >> x >> y;
    ll ans=w[x]+w[y];
    cout << ans << "\n";
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin >> c >> n >> m >> d >> q;
    for(int i=1;i<=m;i++)
        cin >> w[i];
    for(int i=1;i<=n;i++)
    {
        cin >> k;
        for(int j=1;j<=k;j++)
        {
            cin >> a[i][j] >> t[i][j];
        }
    }
    while(q--)
        solve();
    return 0;
}
