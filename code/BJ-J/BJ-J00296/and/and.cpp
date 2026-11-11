#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N = 2e5 + 5;
struct node
{
    int a, c;
} w[N];
int n, m, s[N][31], maxn, ans, cnt[31][2]; //cnt:cnt of k1/k0
bool cmp(node x, node y)
{
    return x.c > y.c;
}
int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i].a;
        int t = w[i].a, idx = 0;
        while (t != 0)
        {
            s[i][idx++] = t % 2;
            cnt[idx][t%2]++;
            t /= 2;
        }
        maxn = max(maxn, idx);
    }
    for (int i = 1; i <= n; i++)
    {
        int ct = 0;
        for (int j = 0; j <= maxn; j++)
        {
            if (s[i][j] == 0) continue;
            else ct += (cnt[j][1]-1);
        }
        w[i].c = ct;
    }
    sort(w+1, w+n+1, cmp);
    //for (int i = 1; i <= n; i++)
    //    cout << w[i].a << " ";
    //cout << "\n";
    ans = w[1].a;
    for (int i = 2; i <= m; i++)
        ans &= w[i].a;
    cout << ans << "\n";
    return 0;
}
