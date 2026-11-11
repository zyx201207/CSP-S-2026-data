#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 5e5 + 5;
int n, ans;
ll m, a[N], sum[N];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; sum[i] = sum[i - 1] + a[i], i++);
    for(int i = 1, l, r; i <= n; i++)
    {
        l = 1, r = i;
        while(l <= r)
        {
            int mid = l + r >> 1;
            if(a[i] * (i - mid) - (sum[i - 1] - sum[mid - 1]) <= m) r = mid - 1;
            else l = mid + 1;
        }
        ans = max(ans, i - l + 1);
    }
    cout << ans;
    return 0;
}