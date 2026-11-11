#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int a[200000], i, m, n, ans = 0;
    cin >> m >> n;
    for(i = 0; i < m; i++)
    {
        cin >> a[i];
        if(a[i] > ans) ans = a[i];
    }
    cout << ans;
    return 0;
}