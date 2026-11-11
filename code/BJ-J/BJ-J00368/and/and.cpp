#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e5 + 10;
int dp[N], a[N], vis[N];
int mx = 0;
int n, m;
void dfs(int now, int cnt, int zhi)
{

    if(cnt == m)
    {
        mx = max(mx, zhi);
        return;
    }
    if(now > n || cnt > m) return;
    if(cnt == 0)
        dfs(now + 1, cnt + 1, a[now]);
    else
        dfs(now + 1, cnt + 1, zhi & a[now]);
    dfs(now + 1, cnt, zhi);
}
signed main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);

    cin >> n >> m;
    int z;
    for(int i = 1;i <= n;i++)
    {
        cin >> a[i];
        if(i == 1) z = a[i];
        else z &= a[i];
        mx = max(mx, a[i]);
    }
    if(m == n)
    {
        cout << z;
        return 0;
    }
    if(m == 1)
    {
        cout << mx;
        return 0;
    }
    if(m == 2)
    {
        mx = 0;
        for(int i = 1;i <= n;i++)
            for(int j = 1;j <= n;j++)
            {
                if(i == j) continue;
                mx = max(mx, (a[i] & a[j]));
            }
        cout << mx;
        return 0;
    }
    if(n < 20)
    {
        mx = 0;
        dfs(1, 0, 0);
        cout << mx;
    }

    return 0;
}
