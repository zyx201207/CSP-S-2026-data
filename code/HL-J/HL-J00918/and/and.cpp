#include <bits/stdc++.h>
using namespace std;
int n, m, sum, ans, a[200005];
bool fir, flag[200005];
void dfs(int num)
{
    if (num > m)
    {
        fir = true;
        for (int i = 1; i <= n; i++)
        {
            if (flag[i])
            {
                if (fir)
                {
                    sum = a[i];
                    fir = false;
                }
                else
                {
                    sum &= a[i];
                }
            }
        }
        ans = max(ans, sum);
        return;
    }
    dfs(num + 1);
    flag[num] = true;
    dfs(num + 1);
    flag[num] = false;
}
int main()
{
    freopen ("and.in", r, stdin);
    freopen ("and.out", w, stdout);
    scanf ("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf ("%d", &a[i]);
    }
     dfs(1);
     cout << ans;
    return 0;
}
