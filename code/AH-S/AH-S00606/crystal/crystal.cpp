#include <bits/stdc++.h>
using namespace std;

long long n, m;
long long a[500010];

bool check(long long mid)
{
    long long cnt = 0;
    for (int i = 1; i < mid; i++)
    {
        cnt += a[mid] - a[i];
    }
    return cnt <= m;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
     {
         cin >> a[i];
     }
     sort (a + 1, a + n + 1);
     long long l = 1, r = n, mid, ans;
     while (l <= r)
     {
         mid = (l + r) / 2;
         if (check(mid))
         {
             l = mid + 1;
             ans = mid;
         }
         else
         {
             r = mid - 1;
         }
     }
     cout << ans;
    return 0;
}
