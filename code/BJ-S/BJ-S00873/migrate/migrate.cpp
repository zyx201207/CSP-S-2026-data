#include<iostream>
using namespace std;
#define int long long
const int N = 2e6 + 5;
const int inf = 1e18;

int c,ttt;
int n,d,a[N],dp[505],cnt[505];

signed main()
{
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c >> ttt;
    while(ttt--)
    {
        cin >> n >> d;
        for(int i=1;i<=n;i++) cin >> a[i];
        if(c <= 6)
        {
            int ans = 0;
            for(int x=1;x<=n;x++)
            {
                for(int i=x;i<=n;i++) dp[i] = inf, cnt[i] = 0;
                dp[x] = 0; cnt[x] = 1;
                for(int i=x;i<=n;i++)
                {
                    for(int j=i+1;j<=n;j++)
                    {
                        if(a[j] - a[i] <= d) dp[j] = min(dp[j],dp[i]+1);
                        else break;
                    }
                    for(int j=i+1;j<=n;j++)
                    {
                        if(a[j] - a[i] <= d)
                        {
                            if(dp[i] + 1 == dp[j]) cnt[j] += cnt[i];
                        }
                        else break;
                    }
                }
                // for(int i=x;i<=n;i++) cout << cnt[i] << " "; cout << '\n';
                for(int i=x;i<=n;i++) if(cnt[i] == 2) ans++;
            }
            cout << ans << '\n';
            continue;
        }
        if(c == 11 || c == 12)
        {
            int x = a[2] - a[1];
            if(d < 2 * x) cout << 0 << '\n';
            if(2 * x <= d)
            {
                int p = d / x;
                cout << max(0ll, n - 2 * p + 1) << '\n';
            } continue;
        }
        if(c == 13 || c == 14)
        {
            int ans = 0;
            for(int i=1,j=1;i<=n;i++)
            {
                while(a[i] - a[j] > d) j++;
                if(i - j >= 3) ans++;
            }
            cout << ans << '\n'; continue;
        }
        cout << 0 << '\n';
    }
    return 0;
}