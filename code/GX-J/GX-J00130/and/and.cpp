#include <bits/stdc++.h>
using namespace std;

long long n, m, sum;
long long a[1000000005];
long long maxn = 0;

int main()
{
    freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        if (a[i] > maxn)
        {
            maxn = a[i];
        }
    }
    sum = a[0];
    if (m == 1)
    {
        cout << maxn;
        return 0;
    }
    else if (m == n)
    {
        for (int i = 1; i < n; i++)
        {
            sum &= a[i];
        }
        cout << sum;
        return 0;
    }
    sort (a, a + n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; i < n; j++)
        {
            sum = a[i] & a[j];
        }
    }
    cout << sum;
    return 0;
}
