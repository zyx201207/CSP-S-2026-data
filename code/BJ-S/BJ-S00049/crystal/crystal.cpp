#include <iostream>
#include <algorithm>
#define ll long long
using namespace std;

const int N = 5e5+5;
int n, m, ans;
ll a[N], d[N];

int main()
{
    ios::sync_with_stdio(false);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a+1, a+n+1);
    for (int i = 1; i <= n; i++)
    {
        d[i] = a[i] - a[i-1];
    }
    int l = 1, s = 0;
    for (int r = 1; r <= n; r++)
    {
        s += d[r] * (r-l);
        while (s > m && l <= r)
        {
            l++;
            s -= a[r] - a[l];
        }
        ans = max(ans, r-l+1);
    }
    cout << ans << endl;
    return 0;
}
