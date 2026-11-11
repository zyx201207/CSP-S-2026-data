#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
long long a[N], sum[N], dp[N];
long long n, m;

long long check(long long z)
{
    long long x = sum[z - 1] + m;
    if(x >= a[z] * (z - 1)) return z;
    else return 0;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        sum[i] = sum[i - 1] + a[i];
    }
    dp[1] = 1;
    for(int i = 1;i <= n;i++)
    {
        long long now = i;
        dp[i] = max(dp[i - 1], check(now));
    }
    cout << dp[n];
    return 0;
}
