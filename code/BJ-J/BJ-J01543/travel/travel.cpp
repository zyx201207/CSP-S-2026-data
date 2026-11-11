#include<bits/stdc++.h>

using namespace std;

void q_0(string &s) {
    if (s[0] == '0') s = s.substr(1, 10);
    else s = s;
}

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    q_0(a);q_0(b);q_0(c);q_0(d);
//    cout << a << " " << b << " " << c << " " << d;
    swap(b, c);
    if (a == b) cout << 1;
    else {
        cout << "0000";
        return 0;
    }
    int n = (int)c.size(), m = (int)d.size();
    c[n - 1] = c[n - 1] - 'A';
    d[m - 1] = d[m - 1] - 'A';
    string s1 = c.substr(0, n - 1), s2 = d.substr(0, n - 1);
    if (s1 == s2) cout << 1;
    else {
        cout << "000";
        return 0;
    }
    if ((c[n - 1] < 3 && d[m - 1] < 3) || (c[n - 1] >= 3 && d[m - 1] >= 3)) cout << 1;
    else {
        cout << "00";
        return 0;
    }
    if (abs(c[n - 1] - d[m - 1]) == 1) cout << 1;
    else cout << 0;
    return 0;
}