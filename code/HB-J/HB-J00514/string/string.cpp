#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

string s;
ll a, n;
char c;
ll ans = 0;

int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a >> c;
        for (int j = 1; j <= a; j++) {
            s += c;
        }
    }
    for (int i = 0; i < s.size() / 2; i++) {
        if (s[i] != s[s.size() - i - 1]) {
            ans++;
        }
    }
    cout << ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}