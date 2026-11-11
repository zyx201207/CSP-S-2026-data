#include <bits/stdc++.h>
#define int long long
using namespace std;

int f[200005][32];
int n;
int m;
int a[200005];
int g[200005]; // flag, =1 means passed
int ans[32];
int tot;

signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    for(int i = 1; i <= n; i++)
        cin >> a[i];
    for(int i = 1; i <= n; i++)
        for(int j = 0; j < 31; j++)
            f[i][j] = a[i] & (1 << j);
    for(int j = 30; j >= 0; j--)
    {
        int cnt = 0;
        for(int i = 1; i <= n; i++)
            if(f[i][j] && !g[i]) cnt++;
        if(cnt >= m)
        {
            ans[j] = 1;
            for(int i = 1; i <= n; i++)
                if(f[i][j] == 0) g[i] = 1;
        }
        else ans[j] = 0;
    }
    for(int j = 30; j >= 0; j--)
        tot += ans[j] * (1 << j);
    cout << tot;

    return 0;
}