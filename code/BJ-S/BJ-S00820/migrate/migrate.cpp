#include <bits/stdc++.h>
using namespace std;
#define int long long
int c,t;
signed main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >> t;
    while (t--)
    {
        int n,d,x[2000005],diff = 1e18;
        cin >> n >> d;
        for (int i = 1;i <= n;i++)
        {
            cin >> x[i];
            if (i >= 2) diff = min(diff,x[i]-x[i-1]);
        }
        if (diff > d)
        {
            cout << 0 << endl;
        }
        else
        {
            cout << 1 << endl;
        }
    }
    return 0;
}
