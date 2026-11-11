#include <bits/stdc++.h>
using namespace std;
int n, m;
int a[500005], pre[500005];
bool check(int x)
{
    for(int i = 1; i <= n - x + 1; i++)
    {
        if(a[i + x - 1] * x <= pre[i + x - 1] - pre[i - 1] + m)
            return true;
    }
    return false;
}
int main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
    {
        pre[i] = pre[i - 1] + a[i];
    }
    int l = 1, r = n;
    while(l < r)
    {
        int mid = (l + r + 1) / 2;
        if(check(mid))
        {
            l = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << l;
    return 0;
}