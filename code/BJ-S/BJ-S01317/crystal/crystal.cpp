#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010], s[500010];
signed main()
{
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for(int i = 1; i <= n; i++)cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int cur = 1;
    int maxn = 0;
    for(int i = 1; i <= n; i++)
    {
        while(a[i] * i - (s[i] - s[cur - 1]) > m)cur++;
        maxn = max(maxn, i - cur + 1);
    }
    cout << maxn << "\n";
    return 0;
}
