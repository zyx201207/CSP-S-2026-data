#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n, m;
    long long ans = 1;
    cin >> n >> m;
    long long tmp = m;
    for(int i = 0; i < n; i++) cin >> a[i];
    sort(a, a + n);
    if(n <= 5000)
    {
        for(int i = 1; i < n; i++)
        {
            tmp = m;
            int cnt = 0;
            for(int j = i; j >= 0; j--)
            {
                if(a[i] - a[j] <= tmp)
                {
                    tmp -= (a[i] - a[j]);
                    cnt++;
                }
            }
            if(cnt > ans) ans = cnt;
        }
        cout << ans;
        return 0;
    }
    else
    {
        bool flag = 1;
        for(int i = 2; i < n; i++)
        {
            if(a[i] - a[i - 1] != a[i - 1] - a[i - 2]) flag = 0;
        }
        if(flag)
        {
            for(int i = n - 2; i >= 0; i--)
            {
                if(a[n - 1] - a[i] <= m)
                {
                    ans++;
                    m -= (a[n - 1] - a[i]);
                }
            }
        }
        cout << ans;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
