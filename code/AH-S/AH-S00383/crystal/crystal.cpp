#include <bits/stdc++.h>
using namespace std;
int n;
long long a[500005],m,sum[500005];
bool check(long long num)
{
    for(long long i = 1; i + num - 1 <= n; i++)
    {
        long long now = (num - 1) * a[i + num - 1] - (sum[i + num - 2] - sum[i - 1]);
        if(now <= m) return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    sort(a + 1,a + n + 1);
    for(int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
    long long mid,L = 1,R = n,ans;
    while(L <= R)
    {
        mid = (L + R) / 2;
        if(check(mid))
        {
            ans = mid;
            L = mid + 1;
        }
        else
            R = mid - 1;
    }
    cout << ans;
    return 0;
}
