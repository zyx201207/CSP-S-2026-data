#include <bits/stdc++.h>
using namespace std;
int n, m, a;
int cnt[33][2][2];
int c[200005];
int ans = 0;
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    if (m == 1)
    {
        int aa = (1 << 30) + 5;
        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            aa = max(aa, a);
        }
        cout << aa << endl;
    }
    else if (m == n)
    {
        int aa;
        cin >> aa;
        for (int i = 2; i <= n; i++)
        {
            cin >> a;
            aa = aa & a;
        }
        cout << aa << endl;
    }
    else if (m == 2 && n <= 2000)
    {
        int aa = 0;
        for (int i = 1; i <= n; i++)
        {
            cin >> c[i];
            for (int j = 1; j < i; j++)
                aa = max(aa, c[i] & c[j]);
        }
        cout << aa << endl;
    }
    else
    {

        for (int i = 1; i <= n; i++)
        {
            cin >> a;
            int la = 0;
            for (int j = 30; j >= 0; j--)
            {
                int ll = ((a & (1 << j)) > 0);
                cnt[j][la][ll]++;
                la = ll;
            }
        }
        int xx = 0, yy = 0;
        for (int i = 30; i >= 0; i--)
        {
            int s = cnt[i][0][1] + cnt[i][1][1];
            if (s >= m)
            {
                ans += (1 << i);
                if (i >= 1)
                {
                    cnt[i - 1][0][0] = 0;
                    cnt[i - 1][0][1] = 0;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}