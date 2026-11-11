#include<bits/stdc++.h>
using namespace std;
#define int long long

const int N = 1e6 + 5;
int a[N], ans[N], sum[N];

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    bool flaga = true;
    bool flagb = true;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(flaga && a[i] != i)
            flaga = 0;
        if(flagb && i >= 3 && a[i] - a[i - 1] != a[i - 1] - a[i - 2])
            flagb = 0;
        if(ans[i] == 0)
        {
            ans[i] = ans[i - 1] + 1;
        }
        sum[i] = sum[i - 1] + i;
        for(int j = sum[i - 1];j <= sum[i] && j <= n;j++)
            if(ans[j] == 0)
                ans[j] = ans[i - 1] + 1;
    }
    if(flaga || flagb)
    {
        int d = a[2] - a[1];
        cout << ans[m / d];
        return 0;
    }
    int i = 1, cnt = 0;
    sort(a + 1, a + n + 1);
    while(m)
    {
        if(i > n)
        {
            cout << n;
            return 0;
        }
        m -= ((a[i + 1] - a[i]) * i);
        if(m >= 0)
            cnt++;
        i++;
    }
    while(a[i] == a[i + 1] && m >= 0)
    {
        cnt++;
        i++;
    }
    cout << cnt + 1;
    return 0;
}
