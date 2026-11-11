#include <iostream>
#include <vector>
using namespace std;
#define LL long long
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    LL n, m;
    cin >> n >> m;
    vector<LL> a(n);
    vector<LL> x(m);
    for (LL i = 0; i < n; ++i)
    {
        cin >> a[i];
    }
    LL max_n = 0;
    for (LL i = 0; i < n - 1; ++i)
    {
        for (LL j = i + 1; j < n; ++j)
        {
            if (max_n < (a[i] & a[j]))
            {
                max_n = a[i] & a[j];
            }
        }
    }
    cout << max_n;
    return 0;
}
