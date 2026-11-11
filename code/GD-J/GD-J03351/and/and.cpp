#include <bits/stdc++.h>
using namespace std;
int n, m, a[200005], cnt, ans;
bool v[32];
int main()
{
    freopen("and.in", "r", stdin);
    freopne("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    for (int i = 1; i <= 30; i++)
    {
        cnt = 0;
        for (int j = 1; j <= n; j++)
        {
            cnt += a[j] & 1;
            a[j] /= 2;
        }
        if (cnt >= m)
        {
            v[i] = 1;
        }
    }
    cnt = 1;
    for (int i = 1; i <= 30; i++)
    {
        ans += cnt * v[i];
        cnt *= 2;
    }
    cout << ans << endl;
    return 0;
}
