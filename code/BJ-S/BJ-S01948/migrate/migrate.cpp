#include <bits/stdc++.h>
#define int long long
using namespace std;

int w[100005],v[100005];
vector <int> v1[100005];
int maxn = 0;



signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    int c,t;
    cin >> c >> t;
    while (t--)
    {
        int n,d,ans = 0;
        cin >> n >> d;
        memset(v,0,sizeof(v));
        memset(w,0,sizeof(w));
        for (int i = 1; i <= n; i++) cin >> w[i];
        for (int i = 1; i <= n; i++)
        {
            int o = i,ans = 0;
            while (o--)
            {
                if (w[i] - w[o] <= d)
                {
                    v[i] = v[o] + 1;
                }
                else
                {
                    break;
                }
            }
            if (v[i] == 2) ans++;
        }
        cout << ans << endl;
    }
    return 0;
}
