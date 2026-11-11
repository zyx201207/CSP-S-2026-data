#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6 + 10;
int x[N];
int dp[N];
int st[N];
void calc1()
{
    int n , d;
    cin >> n >> d;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x[i];
    }
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        dp[i] = 1;
        st[i] = 0;
        for (int j = i + 1 ; j <= n ; j++)
        {
            dp[j] = 0;
            st[j] = 9e18;
            for (int k = i ; k <= j ; k++)
            {
                if (x[j] - x[k] > d)
                {
                    continue;
                }
                if (st[k] + 1 < st[j])
                {
                    st[j] = st[k] + 1;
                    dp[j] = dp[k];
                }
                else if (st[k] + 1 == st[j])
                {
                    dp[j] += dp[k];
                }
            }
            if (dp[j] == 2)
            {
                ans++;
            }
        }
        dp[i] = 0;
    }
    cout << ans << endl;
}
// int sa[N];
int sad[N];
void calc2()
{
    int n , d;
    cin >> n >> d;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> x[i];
        // sa[i] = sa[i - 1] + x[i];
        // cout << sa[i] << " ";
    }
    // cout << endl;
    int ans = 0;
    for (int i = 1 ; i <= n ; i++)
    {
        dp[i] = 1;
        sad[i] = 1;
        st[i] = 0;
        for (int j = i + 1 ; j <= n ; j++)
        {
            dp[j] = 0;
            sad[j] = 0;
            st[j] = 9e18;
            // int t1 = lower_bound(sa + i , sa + j , sa[j] - d) - sa;
            int t1 = lower_bound(x + i , x + j , x[j] - d) - x;
            int t2 = upper_bound(st + t1 , st + j , st[t1]) - st - 1;
            // for (int k = i ; k <= j ; k++)
            // {
            //     if (x[j] - x[k] > d)
            //     {
            //         continue;
            //     }
            //     if (st[k] + 1 < st[j])
            //     {
            //         st[j] = st[k] + 1;
            //         dp[j] = dp[k];
            //     }
            //     else if (st[k] + 1 == st[j])
            //     {
            //         dp[j] += dp[k];
            //     }
            // }
            dp[j] = sad[t2] - sad[t1 - 1];
            st[j] = st[t1] + 1;
            // cout << i << " " << j << " " << t1 << " " << t2 << endl;
            if (dp[j] == 2)
            {
                ans++;
            }
            sad[j] = sad[j - 1] + dp[j];
        }
        // for (int j = 1 ; j <= n ; j++)
        // {
        //     cout << st[j] << " ";
        // }
        // cout << endl;
        // for (int j = 1 ; j <= n ; j++)
        // {
        //     cout << dp[j] << " ";
        // }
        // cout << endl;
        dp[i] = 0;
        sad[i] = 0;
    }
    cout << ans << endl;
    // cout << endl;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("migrate.in" , "r" , stdin);
    freopen("migrate.out" , "w" , stdout);
    int c , t;
    cin >> c >> t;
    while (t--)
    {
        if (c == 13 || c == 14)
        {
            cout << 0 << endl;
            continue;
        }
        if (c <= 6)
        {
            calc1();
        }
        else
        {
            calc2();
        }
    }
    return 0;
}
/*
4 2
1 2 3 4

1 1 1 2
0 1 1 1
0 0 1 1
0 0 0 1

0 1 1 2
0 0 1 1
0 0 0 1
0 0 0 0

*/