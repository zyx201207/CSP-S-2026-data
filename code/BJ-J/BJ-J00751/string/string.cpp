#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int n;
ll sum, ans;
const int N = 200005;

int a[N];
char c[N];
ll ps[N];
vector<ll> blk;

void solve()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i] >> c[i];
        ps[i] = ps[i - 1] + a[i];
        sum += a[i];
    }
    for (int i = 1; i <= n; i++)
    {
        blk.push_back(ps[i]);
        blk.push_back(sum - ps[i]);
    }
    blk.push_back(0);
    blk.push_back(sum);
    sort(blk.begin(), blk.end());
    for (int i = 1, j = blk.size() - 1; i < j; i++, j--)
    {
        int pi = lower_bound(ps + 1, ps + n + 1, blk[i]) - ps;
        int pj = lower_bound(ps + 1, ps + n + 1, blk[j]) - ps;
        ans += (c[pi] != c[pj]) * (blk[i] - blk[i - 1]);
    }
    cout << ans;
}

int main()
{
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}
//O(n*log(n)), O(n*log(n)), 100pts
