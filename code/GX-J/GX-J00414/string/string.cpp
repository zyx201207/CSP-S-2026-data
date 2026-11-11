/*
#include <bits/stdc++.h>
#define int long long //long long is the key in success
using namespace std;
const int N = 1e5 + 5;
int n;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    pair<int, char> a[2 * N];
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i].first >> a[i].second;
        sum += a[i].first;
    }
    //first is number, second is letter(or latter)
    if (n == 2) {
        if (a[1].second == a[2].second) {
            cout << 0;
            return 0;
        }
    }
    //start
    int ans = 0;
    for (int i = 1; i <= n / 2; i++) {
        int t = n + 1 - i;
        int f = abs(a[i].first - a[t].first);
        if (a[i].first == a[t].first) {
            if (a[i].second != a[t].second) {
                ans += a[i].first;
            }
        } else {
            if (a[i].second == a[t].second) {
                if (a[i].first > a[t].first) {
                    int cnt = a[t].first;
                    for (int j = t; j >= 1; j--) {
                        cnt += a[j].first;
                        if (cnt >= a[i].first) {
                            a[j].first = cnt - a[t].first;
                            ans += a[j].first;
                            break;
                        }
                    }
                }
            } else {
                ans = ans + min(a[i].first, a[t].first);
                if (a[i].first > a[t].first) {
                    a[t - 1].first -= f;
                } else {
                    a[i + 1].first -= f;
                }
            }
        }
    }
    if (sum % 2 == 0) {
        cout << ans;
    } else {
        cout << ans + a[n / 2 + 1].first;
    }
    //the end
    return 0;
}
*/
#include <bits/stdc++.h>
using namespace std;
int n;
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        int a;
        char c;
        cin >> a >> c;
        for (int j = 0; j < a; j++) {
            s += c;
        }
    }
    long long ans = 0;
    int len = s.size();
    if (len % 2) {
        string s1 = "", s2 = "";
        for (int i = 0; i < len / 2; i++) {
            s1 += s[i];
        }
        for (int i = len / 2 + 2; i < len; i++) {
            s2 += s[i];
        }
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) ans++;
        }
        cout << ans;
    } else {
        string s1 = "", s2 = "";
        for (int i = 0; i < len / 2; i++) {
            s1 += s[i];
        }
        for (int i = len / 2; i < len; i++) {
            s2 += s[i];
        }
        for (int i = 0; i < s1.size(); i++) {
            if (s1[i] != s2[i]) ans++;
        }
        cout << ans;
    }
    return 0;
}
