#include <bits/stdc++.h>
using namespace std;

long long a[200005], a1[200005];
char c[200005], c1[200005];

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n;
    cin >> n;
    long long sum = 0;
    for (int i = 1; i <= n; ++i) cin >> a[i] >> c[i];
    int x = 1, num = 1;
    c1[1] = c[1];
    for (int i = 1; i <= n; ++i)
    {
        sum += a[i];
        if (c[i] == c[x])
        {
            a1[num] += a[i];
        }
        else
        {
            x = i;
            c1[++num] = c[x];
            a1[num] = a[x];
        }
    }
    int numnow = 1, lst = num, now1 = 0, now2 = 0;
    long long ans = 0;
    for (int i = 1; i <= (sum % 2 == 0 ? sum / 2 : (sum + 1) / 2); ++i)
    {
        now1++;
        now2++;
        if (now1 > a1[numnow])
        {
            now1 -= a1[numnow];
            numnow++;
        }
        if (now2 > a1[lst])
        {
            now2 -= a1[lst];
            lst--;
        }
        int zm1 = c1[numnow], zm2 = c1[lst];
        if (zm1 != zm2) ans++;
    }
    cout << ans;
    return 0;
}
