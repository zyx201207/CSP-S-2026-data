#include <bits/stdc++.h>
using namespace std;
char c[100000005], b[200005];
int a[200005], d = 1, e, f;
long long cnt;
int cnt2;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> b[i];
        cnt += a[i];
    }
    if (cnt > 100000000) cout << cnt / 2;
    else
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = d; j <= d + a[i] - 1; j++)
            {

                c[j] = b[i];
            }
            d += a[i];
        }
        for (int i = 1; i <= cnt / 2; i++)
        {
            if (c[i] != c[cnt - i + 1])
            {
                cnt2++;
            }
        }
        cout << cnt2;
    }
    return 0;
}
