#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 5;
typedef long long ll;
ll a[N], s[N];
int n;
ll m;
bool check(int x) {
    for(int i = 1; i + x - 1 <= n; i++) {
        if(m >= a[i + x - 1] * x - (s[i + x - 1] - s[i - 1])) return 1;
    }
    return 0;
}
int main() {
    freopen("crystal.in", "r", stdin);
    freopen("crystal.out", "w", stdout);
    cin >> n >> m;
    for(int i = 1; i <= n; i++) cin >> a[i];
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    int l = 1, r = n;
    int mid;
    while(r - l >= 5) {
        mid = (l + r) / 2;
        if(check(mid)) l = mid;
        else r = mid - 1;
    }
    for(int i = r; i >= l; i--) 
        if(check(i)) {
            cout << i << endl;
            return 0;
        }
    return 0;
}
// 孩子们我真破绷了
// 上来 s[i] = s[i - 1] + 1
// 然后 mid = (l + r) / 1
// 最后 for(int i = r; i >= l; i++)
// 可是我觉得很神圣啊