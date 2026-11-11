#include <iostream>
#include <queue>
using ll = long long;
using namespace std;
const int N = 2e5 + 10;
ll a[N], sum = 0, ans = 0;
pair<ll, char> q1, r1;
int n;
char ch[N];
bool flag = false;
queue<pair<ll, char>> q, r;
int main () {
    freopen ("string.in", "r", stdin);
    freopen ("string.out", "w", stdout);
    ios :: sync_with_stdio (false);
    cin.tie (nullptr); cout.tie (nullptr);
    cin >> n;
    for (int i = 1; i <= n; i ++) cin >> a[i] >> ch[i], sum += a[i];
    if (sum % 2 == 1) flag = true;
    sum /= 2;
    for (int i = 1; i <= n; i ++) {
        if (sum == 0) {
            if (flag == true) a[i] --;
            break;
        }
        if (sum - a[i] < 0) {
            q.push ({sum, ch[i]}), a[i] -= sum, sum = 0;
            if (flag == true) a[i] --;
            break;
        }
        else q.push ({a[i], ch[i]}), sum -= a[i], a[i] = 0;
    }
    for (int i = n; i >= 1; i --) if (a[i] != 0) r.push ({a[i], ch[i]});
    while ((q.empty () == false && r.empty () == false) || (q1.first != 0 || r1.first != 0)) {
        if (q1.first == 0) q1 = q.front (); q.pop ();
        if (r1.first == 0) r1 = r.front (); r.pop ();
        if (q1.first > r1.first) {
            if (q1.second != r1.second) ans += r1.first;
            q1.first -= r1.first; r1.first = 0;
        }
        else if (q1.first < r1.first) {
            if (q1.second != r1.second) ans += q1.first;
            r1.first -= q1.first; q1.first = 0;
        }
        else {
            if (q1.second != r1.second) ans += r1.first;
            q1.first = 0; r1.first = 0;
        }
    }
    cout << ans;
    return 0;
}
/*
6
100000000 a
100000000 a
99999999 a
100000000 b
100000000 b
100000000 b
*/
