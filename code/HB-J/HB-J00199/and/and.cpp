#include <bits/stdc++.h>
using namespace std;
#define int long long
const int N = 2e5;
int a[32];
string num2bin(int num) {
    string res;
    for (; num; num >>= 1)
        res += char((num & 1) + '0');
    while (res.size() < 32) res += '0';
    reverse(res.begin(), res.end());
    return res;
}
int bin2num(string s) {
    int ret = 0;
    for (char c : s)
        ret = ret * 2 + c - '0';
    return ret;
}
signed main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i ++) {
        int x;
        cin >> x;
        string tmp = num2bin(x);
        for (int i = 0; i < tmp.size(); i ++)
            if (tmp[i] == 1)
                a[i] ++;
    }
    string ans = "00000000000000000000000000000000";
    for (int i = 0; i < 32; i ++)
        if (a[i] >= m)
            ans[i] = '1';
    cout << bin2num(ans);
    return 0;
}
