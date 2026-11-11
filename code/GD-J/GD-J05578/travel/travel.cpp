#include <bits/stdc++.h>

using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a, b;
    string tmp1, tmp2;
    cin >> a >> tmp1 >> b >> tmp2;
    if (a != b) {
        cout << "0000" << endl;
        return 0;
    }
    int c = tmp1[0] * 10 + tmp1[1], d = tmp2[0] * 10 + tmp2[1];
    if (c != d) {
        cout << "1000" << endl;
        return 0;
    }
    char e = tmp1[2], f = tmp2[2];
    string s;
    s += min(e, f), s += max(e, f);
    if (s == "AD" || s == "AF" || s == "BD" || s == "BF" || s == "CD" || s == "CF") {
        cout << "1100" << endl;
        return 0;
    }
    if (s == "AC") {
        cout << "1110" << endl;
        return 0;
    }
    cout << "1111" << endl;
    return 0;
}
