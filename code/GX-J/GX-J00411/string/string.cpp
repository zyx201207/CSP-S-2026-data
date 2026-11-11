#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;
int n, a[N], ans;
char c;
string s;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> a[i] >> c;
        while(a[i]--) {
            s += c;
        }
    }
    for(int i = 0; i <= (s.size() % 2 ? s.size() / 2 : s.size() / 2 - 1); i++) {
        if(s[i] != s[s.size() - 1 - i]) ans++;
    }
    cout << ans;
    return 0;
}
