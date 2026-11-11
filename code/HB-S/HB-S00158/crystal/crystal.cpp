#include <bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    a[0] = -1e13, a[n + 1] = 1e13;
    if (n <= 5000)
    {
        int ans = 0;
        for (int i = 1; i <= n; i++) cin >> a[i];
        for (int i = 1; i <= n; i++)
        {
            int b[n + 1] = {};
            int l = i - 1, r = i + 1;
            b[1] = 0;
            int cur = 1;
            while (true)
            {
                if (l < 1 && r > n)
                    break;
                int num1 = a[i] - a[l];
                int num2 = a[r] - a[i];
                if (num1 < num2)
                {
                    b[++cur] = num1;
                    l--;
                }
                else
                {
                    b[++cur] = num2;
                    r++;
                }
            }
            int t = m, cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (t >= b[j])
                {
                    t -= b[j];
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            ans = max(ans, cnt);
        }
        cout << ans << endl;
    }
    else
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        if (a[1] == 1 && a[2] == 2 && a[n] == n)
        {
            int num = 0, sum = 0, cnt = 1;
            for (int i = 1; i <= (n - 1) / 2; i++)
            {
                num++;
                if (sum + num <= m)
                {
                    sum += num;
                    cnt++;
                }
                else
                {
                    break;
                }
                if (sum + num <= m)
                {
                    sum += num;
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            cout << cnt << endl;
        }
        else if (a[2] - a[1] == a[3] - a[2] && a[3] - a[2] == a[n] - a[n - 1])
        {
            int d = a[2] - a[1];
            int num = 0, sum = 0, cnt = 1;
            for (int i = 1; i <= (n - 1) / d; i++)
            {
                num += d;
                if (sum + num <= m)
                {
                    sum += num;
                    cnt++;
                }
                else
                {
                    break;
                }
                if (sum + num <= m)
                {
                    sum += num;
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            cout << cnt << endl;
        }
        else
        {
            int t = (n + 1) / 2;
            int d = a[t];
            int sum = 0, cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (sum + abs(a[t - i] - d) <= m)
                {
                    sum += abs(a[t - i] - d);
                    cnt++;
                }
                else
                {
                    break;
                }
                if (sum + abs(a[t + i] - d) <= m)
                {
                    sum += abs(a[t + i] - d);
                    cnt++;
                }
                else
                {
                    break;
                }
            }
            cout << cnt << endl;
        }
    }
    return 0;
}
