#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN = 5e5 + 5;
int a[MAXN];
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    int j = 1, sum = 0, ans = 1;
    for (int i = 1; i <= n; i++){
        if (i > 1) sum += (a[i] - a[i - 1]) * (i - j);
        while (sum > m){
            sum -= a[i] - a[j];
            j++;
        }
        ans = max(ans, i - j + 1);
    }
    cout << ans << '\n';
    return 0;
}