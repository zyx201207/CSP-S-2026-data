#include <bits/stdc++.h>
#define N 200011
using namespace std;
typedef long long ll;

int n, m;
ll a[N];
bool has[N];

int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) {
        cin >> a[i];
        has[i] = true;
    }
    int sum1; ll ans = 0;
    for(int b = 30; b >= 0; b--) {
        sum1 = 0;
        for(int i = 1; i <= n; i++)
            if(has[i] && ((a[i] >> b) & 1) == 1) sum1++;
        if(sum1 < m) {
            ans <<= 1;
            continue;
        }
        for(int i = 1; i <= n; i++)
            if(has[i] && ((a[i] >> b) & 1) == 0) has[i] = false;
        ans = (ans << 1) + 1;
    }
    cout << ans;
    return 0;
}