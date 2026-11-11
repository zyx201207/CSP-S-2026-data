#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int a[200005] = {};
    int n, m;
    cin >> n >> m;
    for (int i = 1 ; i <= n ; i++)
    {
        cin >> a[i];
    }
    int maxn = 0;
    if(m == n)
    {
        maxn = a[1];
        for (int i = 2 ; i <= n ; i++)
        {
            maxn &= a[i];
        }
    }
    if(m == 1)
    {
        sort(a + 1 , a + n + 1, [](int x, int y){return x > y;});
        maxn = a[1];
    }
    if(m == 2)
    {
        for (int i = 1 ; i <= n ; i++)
        {
            for (int j = i + 1; j <= n ; j++)
            {
                maxn = max(maxn, a[i] & a[j]);
            }
        }
    }
    cout << maxn;
    fcloseall();
    return 0;
}
