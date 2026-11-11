#include <bits/stdc++.h>
#define int long long
#define ll long long
#define ull unsigned long long
#define i128 __int128
#define ld long double
#define pii pair<int, int>
#define vi vector<int>
#define vpii vector<pair<int, int>>
#define pb push_back
#define m_p make_pair
#define fi first
#define se second
#define pcnt __builtin_popcountll
using namespace std;
const int inf = (sizeof(int) == 4 ? 0x3f3f3f3f : 0x3f3f3f3f3f3f3f3f);
int a[500010], s[500010];
signed main()
{
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++) s[i] = s[i - 1] + a[i];
    int p = 0, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (a[i] * (i - p) - (s[i - 1] - s[p - 1]) > m) p++;
        ans = max(ans, i - p + 1);
    }
    cout << ans << endl;
    return 0;
}