#include <iostream>
using namespace std;

long long c, t, n, d, x[2000005], cnt = 0, pos = 0, tmp, ans = 0;
bool flag = true;
int main()
{
    freopen("migrate.in", "r", stdin);
    freopen("migrate.out", "w", stdout);
    ios::sync_with_stdio(false), cin.tie(0);
    cin >> c >> t;
    while (t--)
    {
        cin >> n >> d;
        for (int i = 1; i <= n; i++) cin >> x[i];
        for (int i = 1; i < n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                cnt = 0;
                pos = i;
                flag = true;
                if (x[j] - x[j - 1] > d) break;
                while (pos < j)
                {
                    tmp = pos;
                    while (x[tmp] - x[pos] <= d && tmp < j) tmp++;
                    if (x[tmp] - x[pos] > d) tmp--;
                    for (int k = pos - 1; k >= i; k--, cnt++) if (x[tmp] - x[k] > d) break;
                    if (cnt > 1)
                    {
                        flag = false;
                        break;
                    }
                    pos = tmp;
                }
                if (cnt != 1) ans--;
                if (!flag) break;
                ans++;
            }
        }
        cout << ans << '\n';
    }
    return 0;
}
