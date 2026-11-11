#include <bits/stdc++.h>
using namespace std;
#define int long long
int n, ans, l;
string s = " ";
signed main(){
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> n;
    for (int i = 1; i <= n; i++){
        int x;
        char c;
        cin >> x >> c;
        l += x;
        for (int j = 1; j <= x; j++) s += c;
    }
    s += " ";
    for (int i = 1; i <= (l + 1) / 2; i++){
        if (s[i] != s[l + 1 - i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
