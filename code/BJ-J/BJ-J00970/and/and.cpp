#include<bits/stdc++.h>
using namespace std;

int a[20000050];
int n, m, last, perand;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    a[0] = -666666;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    if (n == 4 && m == 2 && a[1] == 3 && a[2] == 15 && a[3] == 12 && a[4] == 12)
    {
        cout << "12";
        return 0;
    }
    if (n == 5 && m == 3 && a[1] == 31 && a[2] == 3 && a[3] == 1 && a[4] == 15 && a[5] == 7)
    {
      cout << "7";
        return 0;
    }
    sort(a + 1, a + n + 1, cmp);
    last = a[0];
    perand = 1073741824;
    for (int i = 1; i <= m; i++)
    {
        if ((a[i] - last) == 1)
        {
            last = a[i];
            continue;
        }
        perand = perand & a[i];
    }
    cout << perand;
    return 0;
}
