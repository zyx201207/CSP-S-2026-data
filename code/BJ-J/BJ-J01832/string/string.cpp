#include <iostream>
using namespace std;
typedef long long ll;
int t, cnt;
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> t;
    while (t--) {
        int n;
        char c;
        cin >> n >> c;
        for (int i = 0; i < n; i++) {
            s += c;
        }
    }
    int l = 0;
    ll r = s.size() - 1;
    while (l < r) {
        if (s[l] == s[r]) {
            l++;
            r--;
        } else if (s[l] != s[r]) {
            l++;
            r--;
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
