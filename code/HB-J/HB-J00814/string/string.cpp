#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int a[200000], i, j, n, x = 0, y = 0;
    long long ans = 0, sum = 0;
    char b[200000], l[500][500], r[500][500], s1[200000], s2[200000];
    cin >> n;
    for(i = 0; i < n; i++)
    {
        cin >> a[i] >> b[i];
        for(j = 0; j < a[i]; j++)
        {
            if(i < n / 2) l[i][j] = b[i];
            if(i >= n / 2 && n % 2 == 0 || i > n / 2 && n % 2 == 1) r[i][j] = b[i];
            sum++;
        }
    }
    for(i = 0; i < sum / 2; i++)
    {
        s1[i] = l[x][y], y++;
        if(y == a[x]) x++, y = 0;
    }
    x = n - 1, y = a[x] - 1;
    for(i = 0; i < sum / 2; i++)
    {
        s2[i] = r[x][y], y--;
        if(y == -1) x--, y = a[x] - 1;
    }
    for(i = 0; i < sum / 2; i++) if(s1[i] != s2[i]) ans++;
    cout << ans;
    return 0;
}