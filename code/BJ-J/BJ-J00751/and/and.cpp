#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n, m, ans;
const int N = 200005;

int a[N];
bool flg[N];

void solve()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    for (int b = 30; b >= 0; b--)
    {
        int cnt = 0;
        for (int i = 1; i <= n; i++)
            cnt += (!flg[i] && (a[i] >> b) & 1);
        if (cnt >= m)
        {
            ans += 1 << b;
            for (int i = 1; i <= n; i++)
                if (((a[i] >> b) & 1) == 0) flg[i] = true;
        }
    }
    cout << ans;
}

int main()
{
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//O(n*log(a)), O(n), 100pts
