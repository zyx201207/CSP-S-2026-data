#include <iostream>
#include <algorithm>
using namespace std;

typedef long long ll;

const int NR = 5e5 + 5;

int n;
ll m;
ll a[NR], sum[NR];

bool check(int i, int mid) {
    int len = i - mid + 1;
    return (a[i] * (ll)len - (sum[i] - sum[mid - 1]) <= m);
}

int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);

    int ans = 0;

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    sort(a + 1, a + 1 + n);

    for (int i = 1; i <= n; i++)
        sum[i] = sum[i - 1] + a[i];
        
    for (int i = 1; i <= n; i++) {
        int l = 1, r = i, pos = i;
        while (l <= r) {
            int mid = (l + r) >> 1;
            if (check(i, mid)) r = mid - 1, pos = mid;
            else l = mid + 1;
        }
        ans = max(ans, i - pos + 1);
    }

    printf("%d\n", ans);
    return 0;
}