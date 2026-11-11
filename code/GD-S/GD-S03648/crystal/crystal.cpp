// O(nlogn)
#include <bits/stdc++.h>
#define rep(i, a, b) for (int i = (a); i <= (b); i++)
#define reb(i, a, b) for (int i = (a); i >= (b); i--)
#define ref(i, a, b) for (int i = (a); i < (b); i++)
using namespace std;
typedef long long ll;
#define int ll

const int N = 5e5 + 5;
const int MOD = 1e9 + 7;
const int INF = 0x3f3f3f3f;

int n, k;
int a[N];
int ans;

signed main()
{
    freopen("crystal.in", "r", stdin), freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    cin >> n >> k;
    rep(i, 1, n) cin >> a[i];
    sort(a + 1, a + n + 1);
    int l = 1, cnt = 0;
    rep(r, 2, n)
    {
        cnt += (a[r] - a[r - 1]) * (r - l);
        while (l < r && cnt > k) cnt -= (a[r] - a[l]), l++;
        ans = max(ans, r - l + 1);
    }
    cout << ans << '\n';
    return 0;
}
