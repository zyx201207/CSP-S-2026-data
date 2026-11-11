#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int N = 5e5+5;

int n;
ll m, ans;
bool sp = true;
int a[N];

void s(int l) {
    ll sum = 0;
    for (int i = l+1; i <= n; i++) {
        sum = sum + (a[i]-a[i-1]) * (i-1LL);
        if (sum >= m) {
            ans = max(ans, i-l+1LL);
            return ;
        }
    }
    ans = max(ans, n-l+1LL);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        if (i >= 2 && a[i] - a[i-1] != a[2] - a[1]) sp = false;
    }
    if (sp) {
        ll sum = 0;
        for (int i = 1; i <= n; i++) {
            sum = sum + (a[i]-a[i-1]) * (i-1LL);
            if (sum > m) {
                cout << ans;
                return 0;
            }
            ans++;
        }
        cout << n;
        return 0;
    }
    if (m == 0 || n == 1) {cout << 1; return 0;}
    sort(a+1, a+n+1);
    for (int i = 2; i <= n; i++) s(i);
    cout << ans;
    return 0;
}
