#include <bits/stdc++.h>
using namespace std;
long long n, m, a, res = 0, Max = -1e18, mpow[34];
string s[200006];
vector<int> vec;
string trans(long long num) {
    string ans = "";
    while (num) {
        ans += (num % 2 + '0');
        num /= 2;
    }
    return ans;
}
int main() {
    freopen("and.in", "r", stdin);
    freopen("and.out", "w", stdout);
    mpow[0] = 1;
    for (int i = 1; i <= 31; i++) {
        mpow[i] = mpow[i - 1] * 2;
    }
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> a;
        s[i] = trans(a);
        Max = max(Max, a);
    }
    long long weishu = log2(Max) + 1;
    for (int i = 1; i <= n; i++) {
        if (s[i].size() != weishu) {
            for (int j = s[i].size() + 1; j <= weishu; j++) {
                s[i] += '0';
            }
        }
        reverse(s[i].begin(), s[i].end());
    }
    for (int i = 1; i <= n; i++) {
        vec.push_back(i);
    }
    for (int i = 0; i <= weishu; i++) {
        long long cnt = 0;
        vector<int> jilu;
        for (int j : vec) {
            if (s[j][i] == '1') {
                cnt++;
                jilu.push_back(j);
            }
        }
        if (cnt > m) {
            res += mpow[weishu - i - 1];
            vec = jilu;
        } else if (cnt == m) {
            res += mpow[weishu - i - 1];
            vec = jilu;
            continue;
        } else if (cnt < m) {
            continue;
        }
    }
    cout << res;
    return 0;
}
