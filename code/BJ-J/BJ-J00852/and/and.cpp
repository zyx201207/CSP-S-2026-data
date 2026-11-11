#include <bits/stdc++.h>
using namespace std;

int a[200005];

bool cmp(int x, int y)
{
    return x > y;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n = 0, m = 0;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1, cmp);
    int x = a[m];
    if(x % 2 == 0)
    {
        cout << x;
        return 0;
    }
    bool flag = false;
    for(int i = 1; i <= m; i++)
    {
        if(a[i] % 2 == 0)
        {
            cout << x - 1;
            return 0;
        }
    }
    cout << x;
    return 0;
}
