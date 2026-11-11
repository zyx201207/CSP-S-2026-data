#include<bits/stdc++.h>
using namespace std;
const int maxn = 5e5 + 5;
typedef long long ll;
ll n,m,a[maxn],cnt;
bool check(int k)
{
    ll res = 0;
    for (int i = 1;i < k;i++) res += a[k] - a[i];
    if (res <= m) return true;
    return false;
}
int main()
{
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    cin >> n >> m;
    for (int i = 1;i <= n;i++) cin >> a[i];
    sort(a + 1,a + 1 + n);
    int l = 1,r = n;
    int ans = 0;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) ans = mid,l = mid + 1;
        else r = mid - 1;
    }
    cout << ans << '\n';
    return 0;
}
