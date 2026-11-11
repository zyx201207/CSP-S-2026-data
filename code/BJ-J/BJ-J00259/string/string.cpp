#include <bits/stdc++.h>
using namespace std;

string s;
long long n, ans;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        int a;
        char c;

        cin >> a >> c;

        s += string(a, c);
    }

    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            ans++;
        }
    }

    cout << ans << endl;

    return 0;
}