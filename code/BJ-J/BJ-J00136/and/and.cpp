#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5, M = 32;
long long n, m, a[N], ans, bt;
bool cmp(long long x, long long y){
    return (x & ((1 << bt) - 1)) > (y & ((1 << bt) - 1));
}
int main(){
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; i ++)
        cin >> a[i];
    for (bt = 0; bt <= 30; bt ++){
        sort(a + 1, a + n + 1, cmp);
        long long sum = a[1];
        for (int i = 2; i <= m; i ++)
            sum &= a[i];
        ans = max(ans, sum);
    }
    cout << ans;
    return 0;
}
