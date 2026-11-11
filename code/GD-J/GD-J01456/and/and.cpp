#include <bits/stdc++.h>
using namespace std;
struct bbb
{
    double p, q;
    int l;
}b[200005];
bool cmp(bbb x, bbb y)
{
    return x.q > y.q;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    long long n, m, max1 = 0;
    long long a[200010];
    cin >> n >> m;
    for (int i = 1;i <= n;i++)
    {
        cin >> a[i];
        b[i].p = log2(a[i]);
        b[i].q = b[i].p - int(b[i].p);
        b[i].l = i;
        max1 = max(max1, a[i]);
    }
    long long k = 0;
    if (n == m)
    {
        k = a[1];
        for (int i = 2;i <= n;i++)
        {
            k = (k & a[i]);
        }
        cout << k;
    }
    else if (m == 1)
        cout << max1;
    else
    {
        sort(b + 1, b + 1 + n, cmp);
        long long tot = 1;
        while(m && tot <= n)
        {
            if (k == 0)
                k = a[b[tot].l];
            else
                k = (k & a[b[tot].l]);
            m--;
            tot++;
        }
        cout << k;
    }
    return 0;
}
