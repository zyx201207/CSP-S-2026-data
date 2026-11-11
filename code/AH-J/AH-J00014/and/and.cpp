#include <bits/stdc++.h>
#define ll long long
#define faster ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
int n, m, a[200005], res;
bool check(int k) {
    int s = 0;
    for (int i = 1; i <= n; ++ i) {
        if ((k&a[i]) == k) ++ s;
    }
    return (s >= m);
}
int main() {
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    faster;
    cin >> n >> m;
    for (int i = 1; i <= n; ++ i) cin >> a[i];
    for (int i = 29; i >= 0; -- i) {
        int tmp = (1 << i);
        if (check(res|tmp)) res |= tmp;
    }
    cout << res;
    return 0;
}//made_by_zap2727
