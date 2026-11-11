#include<bits/stdc++.h>
#define int long long
using namespace std;

int n, m;
int a[500005];
int num[500005];

signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        num[a[i]]++;
    }
    sort (a + 1, a + n + 1);
    int ans = 1;
    for (int i = 2; i <= n; i++)
    {
        if (i >= 3 && a[i] == a[i - 1])
        {
            continue;
        }
        int tar = a[i];
        int re = m;
        int cnt = num[a[i]];
        for (int j = i - 1; j >= 1; j--)
        {
            if (a[j] == a[i])
                continue;
            int ch = a[i] - a[j];
            if (re - ch >= 0)
            {
                re -= ch;
                cnt++;
            }
            else
            {
                break;
            }
        }
        ans = max(ans, cnt);
    }
    cout << ans;
    return 0;
}
