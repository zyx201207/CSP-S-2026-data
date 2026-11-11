#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Fro(i, j, k) for (int i = j; i >= k; i --)
#define File(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
using namespace std;
const int N = 5e5 + 5, M = 3e5 + 5;
int n, m, a[N];
int ans[M];
void suba()
{
    For (i, 1, n) ans[a[i]] = i;
    For (i, 1, m) cout << ans[i] << " ";
}
int ttmp[N], cur;
int lst[N], tmp[N], vis[N];
signed main()
{
    File("card");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    bool A = 1;
    int cnt = 0;
    For (i, 1, n) 
    {
        cin >> a[i];
        if (a[i] < a[i - 1]) A = 0;
        if (a[i] != a[i - 1] && i != 1) cnt ++;
    }
    if (A) 
    {
        suba();
        return 0;
    }
    For (i, 1, n) lst[i] = tmp[a[i]], tmp[a[i]] = i;
    For (i, 1, n)
    {
        For (j, 1, m) vis[j] = 0;
        For (j, i, n)
        {
            if (vis[a[j]]) For (k, lst[j], j) vis[a[k]] = 0;
            vis[a[j]] = 1;
        }
        For (j, 1, m) if (vis[j]) ans[j] ++;
    }
    For (i, 1, m) cout << ans[i] << " ";
    return 0;
}