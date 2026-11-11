#include <bits/stdc++.h>
using namespace std;

int n;
long long m, a[500010];

bool check(long long x)
{
    long long sum = 0;
    for(int i = 1;i <= x; i++)
        sum += a[x] - a[i];
    long long ans = sum;
    for(int i = 2;i <= n - x + 1; i++)
    {
        sum -= a[i + x - 2] - a[i - 1];
        sum += x * (a[i + x - 1] - a[i + x - 2]);
        ans = min(ans, sum);
    }
    return ans <= m;
}

int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n; i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    long long l = 0, r = n;
    while(l < r)
    {
        long long mid = l + r + 1 >> 1;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    cout << l << endl;
    return 0;
}
