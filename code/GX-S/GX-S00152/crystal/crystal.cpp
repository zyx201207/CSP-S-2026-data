#include <bits/stdc++.h>
using namespace std;
int n;
long long m, a[500005], sum[500006], ans=-0x6f6f;
bool A = 1;
bool ok(long long i)
{
    long long k = i * a[i] - sum[i-1];
    if(k <= m) return 1;
        ans = max(ans, (long long)i);
    return 0;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out","w", stdout);
    cin >> n >> m;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i];
        if (a[i] != i) A = 0;
        sum[i] = sum[i-1] + a[i];
    }
    if (A)
    {
        for (int i=1;i<=n;i++)
        {
            if (sum[i] > m && sum[i-1] <= m)
                cout << a[i];
        }
        return 0;
    }
    if (n > 1e4)
    {
        long long l=1, r=n, mid;
        while (l <= r)
        {
            mid = (l+r) / 2;
            if (ok(mid))
            {
                ans = max(ans, mid);
                l = mid+1;
            }
            else r = mid - 1;
        }
        cout << ans;
		return 0;
    }
    sort(a+1, a+n+1);
    for (int i=2;i<=n;i++)
    {
        long long k=0;
        long long left;
        for (int j=i-1;j>0;j--)
        {
            left = j;
            if (k < m)
            {
                if (k+a[i] - a[j] > m)
                {
                    left = j+1;
                    break;
                }
                k += a[i] - a[j];
            }
            else break;
        }
        long long q = i - left + 1;
        if(k <= m) ans = max(ans, q);
    }

    cout << ans;
    return 0;
}
