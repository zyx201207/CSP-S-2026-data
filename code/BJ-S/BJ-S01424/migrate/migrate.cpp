#include <bits/stdc++.h>
#define int long long
using namespace std;

const int NR = 5e3 + 10;
int c, T;
int n, d;
int a[NR];
struct Range{
    int l, r;
}mig[NR];
int cnt, ans;
void dfs(int step, int now, int tar)
{
    if(step > ans) return ;
    if(now > tar) return ;
    if(now == tar)
    {
        if(step < ans)
        {
            cnt = 1;
            ans = step;
        }
        else if(step == ans)
        {
            cnt++;
        }
        return;
    }
    for(int i = now + 1; i <= mig[now].r; i++)
    {
        dfs(step + 1, i, tar);
    }
}
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin >> c >>T;
    while(T--)
    {
//        cout << 18 - T << ":\n";
        cin >> n >> d;
        for(int i = 1; i <= n; i++)
        {
            cin >> a[i];
        }
        for(int i = 1; i <= n; i++)
        {
            mig[i].l = lower_bound(a + 1, a + n + 1, a[i] - d) - a;
            mig[i].r = upper_bound(a + 1, a + n + 1, a[i] + d) - a - 1;
        }
        int tot = 0;
        for(int i = 1; i <= n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                cnt = 0;
                ans = n;
                dfs(0, i, j);
//                cout << cnt << " " << ans << "\n";
                if(cnt == 2)
                {
                    tot++;
                }
            }
        }
        cout << tot << "\n";
    }
    return 0;
}
