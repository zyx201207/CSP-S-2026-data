#include <bits/stdc++.h>
using namespace std;
int c, t;
int n[1000005], d[1000005], x[1000005];
int main()
{
    freopen ("migrate.in", "r", stdin);
    freopen ("migrate.out", "w", stdout);
    cin >> c >> t;
    for (int i=1; i <= t; i++)
    {
        cin >> n[i] >> d[i];
        for (int j=1; j <= n[i]; j++)
            cin >> x[j];
    }
    for (int i=1; i <= t; i++)
    {
        cout << n[i] - 3 << endl;
    }
    fclose (stdin);
    fclose (stdout);
    return 0;
}

