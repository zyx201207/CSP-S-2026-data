#include<iostream>
#include<algorithm>
using namespace std;
long long n, m, a[500010], t[500010];
bool check(int x)
{
    long long sum = 0, minn = 1e18;
    for(int i = x; i <= n; ++i)
    {
        sum = x * a[i] - t[i] + t[i - x];
        minn = min(minn, sum);
    }
    return minn <= m;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; ++i)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; ++i)
    {
        t[i] = t[i - 1] + a[i];
    }
    int l = 1, r = n, res = 1;
    while(l <= r)
    {
        int mid = (l + r) / 2;
        if(check(mid))
        {
            l = mid + 1;
            res = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << res;
    return 0;
}
