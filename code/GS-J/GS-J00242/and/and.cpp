#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

const int N = 2e5 + 5;

int n, m, a[N], ans;

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + 1 + n, greater<int>());
    ans = a[1];
    //int i = 1, c;
    /*while (c != m)
    {
        i++;
        if (a[i] == ans - 1 || a[i] == ans + 1)
        {
            continue;
        }
        ans &= a[i];
        c++;
    }*/
    cout << a[m];
    return 0;
}
