#include <bits/stdc++.h>
#define int long long
using namespace std;

int n;
struct node {int x; char c;};
node a[200005];
node l[200005], r[200005];
int lcur = 0, rcur = 0;
int lcnt = 0, rcnt = 0, len = 0;

signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    //cout << n <<"\n";
    for (int i = 1; i <= n; i++) {
        cin >> a[i].x >> a[i].c;
        //cout << i <<" " << a[i].x <<" " << a[i].c << "\n";
        len += a[i].x;
    }
    if (len <= 200000000) {
        string s;
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= a[i].x; j++) s += a[i].c;
        }
        string ll, rr;
        ll = s.substr(0, len / 2);
        rr = s.substr(len / 2 + 1, len / 2);
        for (int li = 0, ri = len / 2 - 1; li < len / 2 && ri >= 0; li++, ri--) {
            ans += (ll[li] != rr[ri]);
        }
        cout << ans << "\n";
        return 0;
    }
    //cout << len << "\n";
    bool f = 0;
    for (int i = 1; i <= n; i++) {
        if (lcnt + a[i].x <= len / 2) {
            lcnt += a[i].x;
            l[++lcur] = a[i];
        }
        else if (lcnt < len / 2) {
            l[++lcur] = {len / 2 - lcnt, a[i].c};
            if (len % 2 == 1 && lcnt + a[i].x - len / 2 - 1 == 0) {
                lcnt = len / 2;
                f = 1;
                continue;
            }
            if (len % 2 == 0 && lcnt + a[i].x - len / 2 == 0) {
                lcnt = len / 2;
                continue;
            }
            if (len % 2 == 1) r[++rcur] = {lcnt + a[i].x - len / 2 - 1, a[i].c}, rcnt += lcnt + a[i].x - len / 2 - 1;
            else r[++rcur] = {lcnt + a[i].x - len / 2, a[i].c}, rcnt += lcnt + a[i].x - len / 2;
            lcnt = len / 2;
        }
        else if (lcnt == len / 2 && rcur == 0) {
            if (len % 2 == 1 && a[i].x == 1 && !f) continue;
            if (len % 2 == 1 && !f) r[++rcur] = {a[i].x - 1, a[i].c}, rcnt += a[i].x - 1;
            else r[++rcur] = a[i], rcnt += a[i].x;
        }
        else {
            r[++rcur] = a[i];
            rcnt += a[i].x;
        }
    }
    //for (int i = 1; i <= lcur; i++) cout << l[i].x << " " << l[i].c << " ";
    //cout << "\n";
    //for (int i = 1; i <= rcur; i++) cout << r[i].x << " " << r[i].c << " ";
    //cout << "\n";
    int ans = 0, lenl = 0, lenr = 0;
    int li = 1, ri = rcur;
    for (; li <= lcur && ri >= 1; ) {
        if (lenl + l[li].x == lenr + r[ri].x && l[li].c == r[ri].c) {
            lenl += l[li].x; lenr += r[ri].x;
            li++, ri--;
        }
        else if (l[li].c != r[ri].c) {
            if (lenl + l[li].x < lenr + r[ri].x) {
                ans += lenl + l[li].x - lenr;
                lenl += l[li].x;
                li++;
            }
            else if (lenl + l[li].x == lenr + r[ri].x) {
                ans += min(l[li].x, r[ri].x);
                lenl += l[li].x;
                lenr += r[ri].x;
                li++; ri--;
            }
            else {
                ans += lenr + r[ri].x - lenl;
                lenr += r[ri].x;
                ri--;
            }
        }
        else {
            if (lenl + l[li].x < lenr + r[ri].x) {
                lenl += l[li].x;
                li++;
            }
            else if (lenl + l[li].x == lenr + r[ri].x) {
                lenl += l[li].x;
                lenr += r[ri].x;
                li++; ri--;
            }
            else {
                lenr += r[ri].x;
                ri--;
            }
        }
        //cout << lenl << " " << lenr << " " << ans << "\n";
    }
    cout << ans << "\n";
    return 0;
}
