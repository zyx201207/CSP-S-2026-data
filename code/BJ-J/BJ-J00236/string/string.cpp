#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll sum;
int n;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    string s;
    for (int i = 1; i <= n; i++) {
        int a;
        char ch;
        cin >> a >> ch;
        for (int j = 1; j <= a; j++) {
            s += ch;
        }
        sum += a;
    }
    string t = s;
    int ans = 0;
    reverse(t.begin(), t.end());
    for (int i = 0; i < s.size(); i++) {
        if (s[i] != t[i])ans++;
    }
    cout << ans / 2 << "\n";
    return 0;
}
