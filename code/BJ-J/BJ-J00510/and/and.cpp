#include <bits/stdc++.h>
#define ll long long
#define endl "\n"
using namespace std;
int n, m, a[200005], ans;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    int r = n;
    for (int i = 30; i >= 0; i--)
    {
        int b = (1 << i), t = r;
        sort(a + 1, a + r + 1, [b](int x, int y){return (x & b) > (y & b);});
        for (int j = 1; j <= r; j++)
        {
            if (!(a[j] & b))
            {
                t = j - 1;
                break;
            }
        }
        if (t >= m) r = t, ans |= b;
    }
    cout << ans;
    return 0;
}
