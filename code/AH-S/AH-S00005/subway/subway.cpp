#include<bits/stdc++.h>
#define int long long
using namespace std;
int c, n, m, d, q, w[50000], ans;
struct subway{
    int z, t;
};
subway xl[5000][5000];
signed main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> c >> n >> m >> d >> q;
    for(int i = 1; i<=n; i++)cin >> w[i];
    for(int i=0; i<n; i++)
    {
        int k; cin>>k;
        for(int j=0; j<k; j++)
        {
            cin >> xl[i][j].z >> xl[i][j].t;
        }
    }
    for(int i=1; i<=q; i++)
    {
        ans = 0;
        int Be, Ed; cin >> Be >> Ed;
        ans += w[Be];
        for(int i=0; i<n; i++)
        {
            ans += xl[i][0].t;
        }
        cout << ans << endl;
    }
    return 0;
}
