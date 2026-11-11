#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const int N = 5e5 + 10;
int n, l, r, mid, res;
ll m, a[N], pre[N];
bool chk(int x) {
    bool f = 0;
    for(int rr = x; rr <= n; rr++) {
        int ll = rr - x + 1;
        if(x * a[rr] - (pre[rr] - pre[ll - 1]) <= m) {
            f = 1;
            break;
        }
    }
    return f;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
	ios :: sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i]; 
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++) pre[i] = pre[i - 1] + a[i];
    l = 1, r = n;
    while(l <= r) {
        mid = (l + r) / 2;
        if(chk(mid)) {
            l = mid + 1;
            res = mid;
        }
        else r = mid - 1;
    }
    cout << res;
	return 0;
}