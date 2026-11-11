#include <bits/stdc++.h>
#define ft first
#define nd second
using namespace std;
using ll = long long;
using P = pair<int, int>;

string c1, s1, c2, s2;

int cont(char ch) {
    if (ch >= 'A' && ch <= 'C') return 1;
    return 0;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
        if (s1.substr(0, 2) == s2.substr(0, 2)) {
            cout << 1;
            char ch1 = s1.back(), ch2 = s2.back();
            if (cont(ch1) == cont(ch2)) {
                    cout << 1;
                    if (abs((int)ch1 - (int)ch2) == 1) cout << 1;
                    else cout << 0;
                } else cout << "00";
        } else cout << "000";
    } else cout << "0000";
    return 0;
}
