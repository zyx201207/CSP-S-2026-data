# include <bits/stdc++.h>
using namespace std;

const long long MAXN = 5e5 + 7;
long long a[MAXN];

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    long long n;
    long long m;
    bool flagA = true;
    cin >> n >> m;
    for (long long i = 1; i <= n; i++)
        cin >> a[i];
    sort(a+1, a+n+1);
    for (long long i = 1; i <= n; i++)
    {
        if (i >= 2 && a[i] != a[i-1])
            flagA = false;
    }
    if (flagA)
    {
        cout << n << endl;
        return 0;
    }

    long long l1 = 0;
    long long r1 = n;
    long long mid = n/2;
    long long maxn = -1;
    while (l1 < r1)
    {
        long long l = mid;
        long long cur = 0;
        for (long long i = 1; i <= l; i++)
            cur += (a[l] - a[i]);
        bool flag = false;
        if (cur <= m)
        {
            maxn = max(maxn, l);
            l1 = mid + 1;
            mid = (l1 + r1)/2;
            flag = true;
            continue;
        }
        for (long long i = l+1; i <= n; i++)
        {
            cur += (l-1)*(a[i] - a[i-1]);
            cur -= (a[i-1] - a[i-l]);
            if (cur <= m)
            {
                maxn = max(maxn, l);
                l1 = mid + 1;
                mid = (l1 + r1)/2;
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            r1 = mid;
            mid = (l1 + r1)/2;
        }
    }
    cout << maxn;
    return 0;
}
