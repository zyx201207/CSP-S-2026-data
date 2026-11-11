#include <bits/stdc++.h>
#define int long long
using namespace std;

int c,t,n,d;
int x[2000010];

signed main ()
{
    freopen ("migrate.in","r",stdin);
    freopen ("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        int y = d / (x[2] - x[1]);
        cout << n / y << endl;
    }
    return 0;
}