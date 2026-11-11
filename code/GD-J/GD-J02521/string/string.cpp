#include <bits/stdc++.h>
using namespace std;
#define int long long
#define x first
#define y second
const int N = 2e5 + 10;
typedef pair<int, char> pii;
pii a[N];
int n, l1, r1, l2, r2, ans, tot;
signed main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    // freopen("string4.in", "r", stdin);
    // freopen("string.txt", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].x >> a[i].y;
        tot += a[i].x;
        //cout << a[i].x;
    }
    // cout << tot << '\n';
    l1 = 1, r2 = tot;
    int mid = tot / 2;
    int p1 = 1, p2 = n;
    int r1 = l1 + a[1].x, l2 = r2 - a[n].x;
    int left1 = 0, left2 = 0;
    for (int i = 1; i <= n; i++)
    {
        int sum1 = left1, sum2 = left2;
        if (!left1)
            sum1 = a[p1].x;
        if (!left2)
            sum2 = a[p2].x;
        char c1 = a[p1].y, c2 = a[p2].y;

        if (c1 != c2)
            ans += min(sum1, sum2);
        // cout << ans << ' ';
        if (a[p1].x > a[p2].x)
        {
            p2--;
            left1 = sum1 - sum2;
            left2 = 0;
            l2 = l2 - a[p2].x;
        }
        else if (a[p1].x < a[p2].x)
        {
            left2 = sum2 - sum1;
            left1 = 0;
            p1++;
            r1 = r1 + a[p1].x;
        }
        else
        {
            left1 = left2 = 0;
            p1++;
            p2--;
            r1 = r1 + a[p1].x;
            l2 = l2 - a[p2].x;
        }
    }
    cout << ans / 2 << '\n';
    return 0;
}
