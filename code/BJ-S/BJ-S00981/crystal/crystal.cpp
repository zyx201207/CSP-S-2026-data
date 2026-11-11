#include <bits/stdc++.h>
using namespace std;

const int N = 5e5 + 5;
long long n, m, ans;
long long a[N], s[N];

int main(){
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    scanf("%lld%lld", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);
    for (int i = n; i >= 1; i--)
        s[i] = s[i + 1] + a[i];
    for (int i = 1; i <= n; i++){
        long long l = 1, r = i, res = i;
        while (l <= r){
            long long mid = l + r >> 1;
            if ((a[i] * (i - mid)) - (s[mid] - s[i]) <= m){ res = mid; r = mid - 1; }
            else { l = mid + 1; }
        }
        ans = max(ans, i - res + 1);
    }
    printf("%lld\n", ans);
    return 0;
}