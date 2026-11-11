#include <iostream>
using namespace std;

const int maxn = 200000;
int a[maxn], s[maxn];
char c[maxn];
long long len;
long long cnt;
int n;
typedef long long ll;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a[i] >> c[i];
        len += a[i];
        s[i] = a[i];
        if (i > 0)
            s[i] += s[i - 1];
    }

    ll l = 1, r = len;
    int sl = 0, sr = n - 1;
    while (true) {
        if (sl == sr) {
            break;
        }
        ll mv = min(s[sl] - l + 1, r - s[sr - 1]);
        ll nl = l + mv, nr = r - mv;
        if (c[sl] != c[sr])
            cnt += mv;
        if (mv == s[sl] - l + 1)
            sl++;
        if (mv == r - s[sr - 1])
            sr--;
        l = nl, r = nr;
    }
    cout << cnt << endl;
}