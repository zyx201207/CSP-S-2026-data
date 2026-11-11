#include <bits/stdc++.h>
using namespace std;

const int N=500005;
typedef long long ll;

ll n, m, a[N];
ll ans=1, last, sum;

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);

    scanf("%lld%lld", &n, &m);
    for (int i=1; i<=n; ++i) {
        scanf("%lld", &a[i]);
    }
    sort(a+1, a+1+n);
    for (int i=1; i<=n; ++i) {
        if (i>1) {
            sum+=(a[i]-a[i-1])*(i-last-1);
        }
        while (sum>m) {
            sum-=(a[i]-a[++last]);
        }
        ans=max(ans, i-last);
    }
    printf("%lld\n", ans);

    return 0;
}
