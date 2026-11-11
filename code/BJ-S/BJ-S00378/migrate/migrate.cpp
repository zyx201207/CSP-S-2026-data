#include <bits/stdc++.h>
using namespace std;
long long a[500005];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int b, n;
    cin >> b >> n;
    for(int i = 0; i < n; i++)
    {
        int island, maxfly, mi;
        cin >> island >> maxfly;
        for(int j = 0; j < island; j++)
        {
            cin >> a[j];
        }
        mi = a[1] - a[0];
        cout << "mi = " << mi << "\n";
        if(maxfly >= 2 * mi && maxfly < 3 * mi)
        {
            cout << max(0, island - 3) << "\n";
        }
        else cout << "0\n";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
