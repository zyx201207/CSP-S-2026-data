#include <bits/stdc++.h>
using namespace std;
long long n, m, ans = 1;
long long a[500005];
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n);
    long long  l = 1;
    long long sum = a[1];
    for (int i = 2; i <= n; i++)
    {
        sum += a[i];
        long long ss = a[i] * (i - l + 1);
        while (ss - sum > m)
        {
            sum -= a[l];
            l++;
            ss -= a[i];
        }
        ans = max(ans, (long long)i - l + 1);
    }
    cout << ans;
    return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/