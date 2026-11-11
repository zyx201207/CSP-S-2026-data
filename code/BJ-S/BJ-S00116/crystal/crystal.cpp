#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
long long n, m, a[N], sum[N], ans;
int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i ++)
        sum[i] = sum[i - 1] + a[i];
    for (int i = 1; i <= n; i ++){
        long long l = 1, r = i;
        while (l < r){
            long long mid = l + r + 1 >> 1;
            if (a[i] * mid <= m + sum[i] - sum[i - mid])
                l = mid;
            else r = mid - 1;
        }
        ans = max(ans, l);
    }
    cout << ans;
    return 0;
}
