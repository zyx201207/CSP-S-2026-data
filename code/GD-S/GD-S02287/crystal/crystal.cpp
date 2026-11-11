#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
#include <ctime>
using namespace std;

using ll = long long;

mt19937_64 rnd(time(0));

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    int n;
    ll m;
    scanf("%d %lld", &n, &m);

    vector<ll> a(n);
    for (int i = 0; i < n; ++i)
    {
        scanf("%lld", &a[i]);
    }

    if (n > 5000)
    {
        bool ok = 1;
        for (int i = 0; i < n; ++i)
        {
            if (a[i] > 100)
            {
                ok = 0;
            }
        }
        if (ok)
        {
            vector<int> cnt(105);
            for (int i = 0; i < n; ++i)
            {
                ++cnt[a[i]];
            }
            ll ans = 0;
            for (int i = 0; i < 105; ++i)
            {
                ll cur = cnt[i],
                   cs = 0;
                for (int j = i - 1; j > 0; --j)
                {
                    if (cnt[j])
                    {
                        if (cs + cnt[j] * (i - j) <= m)
                        {
                            cs += cnt[j] * (i - j);
                            cur += cnt[j];
                        }
                        else
                        {
                            cur += (m - cs) / (i - j);
                            break;
                        }
                    }
                }

                ans = max(ans, cur);
            }
            cout << ans;
            return 0;
        }
        ll ans = 0;
        vector<ll> ned(n);
        for (int j = 0; j < n; ++j)
        {
            ned[j] = a[n - 1] - a[j];
        }

        ll sum = 0;
        for (int j = n - 1; j > 0; --j)
        {
            if (ned[j] >= 0 && sum + ned[j] <= m)
            {
                sum += ned[j];
                ++ans;
            }
            else if (sum + ned[j] > m)
            {
                break;
            }
        }

        printf("%lld", ans);
        return 0;
    }

    sort(a.begin(), a.end());

    // 45pts
    int ans = 0;
    vector<int> ned(n);
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            ned[j] = a[i] - a[j];
            // printf("%d ", ned[j]);
        }

        sort(ned.begin(), ned.end());
        ll sum = 0;
        int cnt = 0;
        for (int j = 0; j < n; ++j)
        {
            if (ned[j] >= 0 && sum + ned[j] <= m)
            {
                sum += ned[j];
                ++cnt;
            }
            else if (sum + ned[j] > m)
            {
                break;
            }
        }

        ans = max(ans, cnt);
        // printf("[%d] %d\n", i, cnt);
    }

    printf("%d", ans);
    return 0;
}
