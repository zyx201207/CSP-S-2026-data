#include<bits/stdc++.h>
using namespace std;
const long long N = 200010;
long long n, m, mx = LONG_MIN;
long long a[N];
void dfs(long long lv, long long sum, long long num)
{
    if(lv == n)
    {
        mx = max(mx, num);
        return;
    }
    if(sum < m)
    {
        dfs(lv + 1, sum + 1, num & a[lv]);
    }
    if((n - lv) > (m - sum))
    {
        dfs(lv + 1, sum, num);
    }
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    //cout << mx << "\n";
    cin >> n >> m;
    for(long long i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    dfs(0, 0, pow(2, 31) - 1);
    cout << mx;
    return 0;
}
