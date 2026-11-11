#include <bits/stdc++.h>
using namespace std;
long long a[500005], c[500005];
int dp[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        a[i] += 1000;
        c[a[i]]++;
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        dp[i] = c[a[i]];
    }
    for(int i = 2; i <= n; i++)
    {
        if(a[i] == a[i - 1])
        {
            continue;
        }
        long long k = m;
        int o = i - 1;
        while(1)
        {
            int p = a[i] - a[o];
            if(k >= p && o >= 1)
            {
                k -= p;
                dp[i]++;
                o--;
            }else
            {
                break;
            }

        }
    }
    int ans = 0;
    for(int i = 1; i <= n; i++)
    {
        ans = max(ans, dp[i]);
    }
    cout << ans;
    return 0;
}
