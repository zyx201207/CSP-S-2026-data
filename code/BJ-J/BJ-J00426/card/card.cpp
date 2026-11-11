#include<iostream>
#include<array>
using namespace std;
int m, n, last[300010], a[500010], ans[300010];
int main()
{
    freopen("card.in", "r", stdin);
    freopen("card.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    if(n <= 500)
    {
        for(int i = 1; i <= n; ++i)
        {
            int now = 0;
            for(int j = 1; j <= m; ++j)
            {
                last[j] = 0;
            }
            for(int j = i; j <= n; ++j)
            {
                ++now;
                if(last[a[j]])
                {
                    now = last[a[j]];
                    for(int k = 1; k <= m; ++k)
                    {
                        if(last[k] > now)
                        {
                            last[k] = 0;
                        }
                    }
                }
                else
                {
                    last[a[j]] = now;
                }
            }
            for(int j = 1; j <= m; ++j)
            {
                if(last[j])
                {
                    ans[j]++;
                }
            }
        }
        for(int i = 1; i <= m; ++i)
        {

            cout << ans[i] << ' ';
        }
    }
    else
    {
        for(int i = n; i >= 1; --i)
        {
            if(a[i] == a[i - 1])
            {
                ans[a[i]]++;
                a[i] = -1;
                a[i - 1] = -1;
            }
            else if(a[i] > 0 && a[i] != a[i + 1])
            {
                ans[a[i]] += i;
            }
        }
        for(int i = 1; i <= m; ++i)
        {
            cout << ans[i]  << ' ';
        }
    }
    return 0;
}
