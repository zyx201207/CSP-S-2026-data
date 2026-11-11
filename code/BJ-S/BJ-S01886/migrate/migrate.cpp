#include<bits/stdc++.h>
using namespace std;
const int N = 2e6 + 5;
int c, t;
long long n, d, ans, a[N];
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t--)
    {
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        if(c == 11 || c == 12)
        {
            int g = a[2] - a[1], cnt = 0;
            if(d > g * cnt) cnt++;
            cnt--;
            if(cnt < 2)
            {
                cout << 0 << "\n";
                continue;
            }
            ans += n - 1 - 2 * (cnt - 1);
            cout << ans << "\n";
        }
    }
    return 0;
}
