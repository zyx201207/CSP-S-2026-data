#include <bits/stdc++.h>
#define endl '\n'
#define int long long
using namespace std;
int n, m, s, st, ans;
struct STRUCT
{
    char c;
    int cnt;
} k[200005];
signed main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> k[i].cnt >> k[i].c;
    for (int i = 1, j = n, a, b; i <= n && j >= 1;)
    {
        int change = min(k[i].cnt, k[j].cnt);
        if (k[i].c != k[j].c)
            ans += change;
        if (change == k[i].cnt)
            a = 1;
        else
            a = 0;
        if (change == k[j].cnt)
            b = 1;
        else
            b = 0;
        k[i].cnt -= change;
        k[j].cnt -= change;
        i += a;
        j -= b;
    }
    cout << ans << endl;
    return 0;
}