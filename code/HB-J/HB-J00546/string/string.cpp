#include <bits/stdc++.h>
using namespace std;
int a[200005];
char b[200005];
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        sum += a[i];
    }
    sum /= 2;
    long long ans = 0, cnt = 0;
    int k = 1;
    for (int i = n; i >= 1; i--)
    {
        if (cnt + a[i] < sum)
        {
            cnt += a[i];
            for (int j = k; j <= n; j++)
            {
                if (a[j] < a[i])
                {
                    if (b[j] != b[i])
                    {
                        ans += a[j];
                    }
                    a[i] -= a[j];
                    k ++;
                }
                else
                {
                    if (b[j] != b[i])
                    {
                        ans += a[i];
                    }
                    a[j] -= a[i];
                    break ;
                }
            }
        }
        else
        {
            int c = sum - cnt, d = b[i];
            for (int j = k; j <= n; j++)
            {
                if (a[j] < c)
                {
                    if (b[j] != d)
                    {
                        ans += a[j];
                    }
                    c -= a[j];
                    k ++;
                }
                else
                {
                    if (b[j] != d)
                    {
                        ans += c;
                    }
                    a[j] -= c;
                    break ;
                }
            }
            break ;
        }
    }
    cout << ans;
    return 0;
}
