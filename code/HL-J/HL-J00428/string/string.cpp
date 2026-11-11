#include<bits/stdc++.h>
#define int long long
using namespace std;
int n;
string s;
int len;
int ans;
void solve1() {
    int mid = len / 2;
    string l, r;
    for (int i = mid - 1; i >= 0; i--) {
        l += s[i];
    }
    for (int i = mid + 1; i < len; i++) {
        r += s[i];
    }
    for (int i = 0; i < len / 2; i++) {
        if (r[i] != l[i]) {
            ans++;
        }
    }
}
void solve2() {
    int mid = len / 2;
    string l, r;
    for (int i = mid - 1; i >= 0; i--) {
        l += s[i];
    }
    for (int i = mid; i < len; i++) {
        r += s[i];
    }
    for (int i = 0; i < len / 2; i++) {
        if (r[i] != l[i]) {
            ans++;
        }
    }
}
signed main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);

    ios::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++) {
        int x;
        cin >> x;
        string c;
        cin >> c;
        for (int j = 1; j <= x; j++) {
            s += c;
        }
    }
    len = s.size();
    if (len % 2 == 1) {
        solve1();
        cout << ans;
        return 0;
    }else {
        solve2();
        cout << ans;
    }
    return 0;
}

