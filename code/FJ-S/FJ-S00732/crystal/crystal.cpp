#include <bits/stdc++.h>
using namespace std;
#define FILE(x) freopen(x".in", "r", stdin); freopen(x".out", "w", stdout);
#define ll long long
const int N = 5e5 + 5;
int n, ans; ll s, m, a[N];
int main()
{
    FILE("crystal");
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i]; sort(a + 1, a + n + 1);
    for (int i = 1, j = 1; i <= n; i++)
    {
        s += (a[i] - a[i-1]) * (i - j);
        while (s > m) s -= a[i] - a[j++];
        ans = max(ans, i - j + 1);
    }
    cout << ans << "\n";
    return 0;
}