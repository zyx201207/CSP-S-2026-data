#include <bits/stdc++.h>
using namespace std;
int c, t, n, k, ui[2000005], vi[2000005];
int main()
{
    freopen ("hub.in", "r", stdin);
    freopen ("hub.out", "w", stdout);
    cin >> c >> t;
    for (int i=1; i <= t; i++)
    {
        cin >> k;
        for (int j=1; j <= k; j++)
        {
            cin >> ui[j] >> vi[j];
        }
    }
    for (int i=1; i <= t; i++)
        cout << i;
    fclose (stdin);
    fclose (stdout);
    return 0;
}

