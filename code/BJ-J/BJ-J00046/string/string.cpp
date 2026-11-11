#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5 + 5;
signed main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    int sum = 0;
    string s = "";
    for (int i = 1; i <= n; i++) {
        int a; char c;
        cin >> a >> c;
        for (int j = 1; j <= a; j++) s += c;
    }
    int l = 0, r = s.size() - 1, ans = 0;
    //cout << s;
    while (l < r) {
        if (s[l] != s[r]) {
                ans++;
        //cout << s[l] << s[r];
        }
        l++,r--;
    }
    cout << ans;
    return 0;
}
//g++ -o o.exe travel.cpp
