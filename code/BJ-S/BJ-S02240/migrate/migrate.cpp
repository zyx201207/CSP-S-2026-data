#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 2e6 + 5;
int a[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    int c, t;
    cin >> c >> t;
    while(t--)
    {

        int n, d, d1, ans = 0;;
        cin >> n >> d;
        if(c == 13 || c == 14)
        {
            cout << (n >= 3 ? (n - 3) * (n - 2) / 2 : 0) << "\n";
            continue;
        }
        for(int i = 1;i <= n;i++)
        {
            cin >> a[i];
            if(a[i] - a[1] > d && a[i - 1] - a[1] <= d)
                d1 = i + 1;

        }
        if(c == 11 || c == 12)
        {
            cout << (n - d1) * (n - d1 + 1) / 2;
            continue;
        }
        for(int i = 1;i = n;i++)
        {
            for(int j = i + 1;j <= i + 3;j++)
            {
                if(a[j] - a[i] <= d)
                continue;
                if(a[j + 1] - a[j] > d)
                    break;
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
