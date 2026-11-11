#include<bits/stdc++.h>
using namespace std;
const long long N = 5e5 + 10;
long long n, m, a[N];
bool check(long long num)
{
    long long sum = 0;
    for (long long i = 1; i <= num; i++)
    {
        sum += a[num] - a[i];
        if (sum > m) return false;
    }
    return true;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >>n >>m;
    for (long long i = 1; i <= n; i++) cin >>a[i];
    sort (a + 1, a + n + 1);
    long long l = 1, r = n;
    while (l < r)
    {
        long long mid = (l + r + 1) / 2;
        if (check(mid)) l = mid;
        else r = mid - 1;
    }
    cout <<l;
    return 0;
}
