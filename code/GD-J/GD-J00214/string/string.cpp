#include <bits/stdc++.h>
#define For(i, j, k) for (int i = j; i <= k; i ++)
#define Fro(i, j, k) for (int i = j; i >= k; i --)
#define File(s) freopen(s".in", "r", stdin); freopen(s".out", "w", stdout)
using namespace std;
const int N = 2e5 + 5;
int n;
struct node
{
    int a;
    char c;
}a[N];
long long pre[N], suf[N];
signed main()
{
    File("string");
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    For (i, 1, n)
    {
        cin >> a[i].a >> a[i].c;
        pre[i] = pre[i - 1] + a[i].a;
    }
    Fro (i, n, 1) suf[i] = suf[i + 1] + a[i].a;
    long long id = 0, ans = 0;
    int l = 1, r = n;
    while (id * 2 < pre[n])
    {
        int x = pre[l] - id, y = suf[r] - id;
        if (x == y) ans += x * (a[l].c != a[r].c), id = pre[l], l ++, r --;
        else if (x < y) ans += x * (a[l].c != a[r].c), id = pre[l], l ++;
        else ans += y * (a[l].c != a[r].c), id = suf[r], r --;
    }
    cout << ans;
    return 0;
}