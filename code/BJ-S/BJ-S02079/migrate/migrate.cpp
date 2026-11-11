#include<bits/stdc++.h>
using namespace std;

const int N = 2e6 + 5;
long long x[N], n, ans, d, c, t;

void work()
{
    cin >> n >> d;
    for(int i = 1; i <= n; i ++)
        cin >> x[i];
    for(int i = 2; i < n; i ++)
    {
        if(x[i + 2] - d > x[i - 1] && x[i] - x[i - 1] <= d && x[i + 1] - x[i - 1] <= d && i + 2 <= n)
        {
            int r = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
            ans += max(0, r - i - 2);
        }
        //cout << ans << endl;
        if(x[i + 2] - x[i] <= d && x[i + 2] - x[i - 1] > d)
        {
            int l = lower_bound(x + 1, x + n + 1, x[i + 1] - d) - x;
            int r = i - 2;
            ans += max(0, r - l + 1);
        }
        //cout << ans << endl;
        if(x[i + 2] - x[i + 1] <= d && x[i + 2] - x[i] <= d && x[i + 1] - x[i - 1] <= d && x[i] - x[i - 1] <= d && i + 2 <= n)
            ans ++;
        //cout << x[i + 1] - x[i - 1] << endl;
        int r = upper_bound(x + 1, x + n + 1, x[i] + d) - x - 1;
        int l1 = lower_bound(x + 1, x + n + 1, x[i + 1] - d) - x;
            int r1 = i - 2;
        ans += max(0, r - i - 2) * max(0, r1 - l1 + 1);
        //cout << ans << endl;
    }
    cout << ans << endl;
    return;
}

int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    cin >> c >> t;
    while(t --)
    {
        work();
        ans = 0;
    }
}
