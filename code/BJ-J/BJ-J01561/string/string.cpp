#include <bits/stdc++.h>
using namespace std;

long n, m, sum;
int a[100005] = {}, an[100005] = {};
char c[100005] = {};

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i] >> c[i];

    for (int i = 0; i < n; i++)
    {
        m += a[i];
        an[i+1] = an[i] + a[i];
    }

    m = m/2 + 1;
    for (int i = m; i > 0; i--)
    {
        int p = 0;
        for (int j = m-i; j < an[p+1];)
            p++;

        int q = n;
        for (int j = m+i-1; j >= an[q+1];)
            q--;

        if (c[p] != c[q])
            sum += 1;
    }

    cout << sum;

    return 0;
}
