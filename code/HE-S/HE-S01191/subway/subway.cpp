#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;
int main()
{
    freopen("subway.in", "r", stdin);
    freopen("subway.out", "w", stdout);
    long long c, n, m, d, q;
    cin >> c >> n >> m >> d >> q;
    vector<long long> time(m);
    for(int i = 0; i < m; i++)
    {
        cin >> time[i];
    }

    vector<long long> arr(n);
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    for(int i = 0; i < q; i++)
    {
        ll x, y;
        cin >> x >> y;
    }
    return 0;
}
