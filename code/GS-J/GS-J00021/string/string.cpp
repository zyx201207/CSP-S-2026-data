#include <bits/stdc++.h>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);

    int n, cnt = 0;cin >> n;
    string s = "";
    for(int i = 1; i <= n; ++i) {
        int num;char x;
        cin >> num >> x;
        for(int j = 1; j <= num; ++j) {
            s+=x;
        }
    }
    //cout << s << endl;
    int l = 0, r = s.size()-1;
    while(l < r) {
        if((char)s[l] != (char)s[r]) ++cnt;
        ++l;--r;
    }
    cout << cnt;
    return 0;
}