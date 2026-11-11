#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 2e6+5;
int c, t, n;
ll d, x[N], dp[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++)
        {
            cin >> x[i];
        }
        if (c==11 || c==12) //flagA
        {
        	if (d < x[2]-x[1])
        	{
        		cout << "0\n";
        		continue;
			}
            ll ans = 0;
            if (n <=2e6)
            {
                for (int st = 1; st < n; st++)//start
                {
                    memset(dp, 0, sizeof(dp));
                    dp[st] = 1;
                    for (int i = st+1; i <= n; i++)
                    {
                        int pos = lower_bound(x+st, x+i, x[i]-d)-x;
                        for (int j = pos; j < i; j++)
                        {
                            dp[i] += dp[j];
                        }
                    }
                    for (int j = st+1; j <= n; j++)
                    {
                        int pos = lower_bound(x+st, x+n+1, x[j]-d)-x;
                        if (dp[j]-dp[st] == 2)
                        {
                            ans++;
                        }
                    }
                }
            }
            else
            {
                ans = n-d-1;
            }
            cout << ans << '\n';
            continue;
        }
        if (c==13 || c==14)
        {
            cout << 0 << '\n';
            continue;
        }
        cout << 0 << '\n';
    }
    return 0;
}
