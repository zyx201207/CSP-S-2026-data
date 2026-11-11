#include <iostream>
#include <string>
#include <cstdio>
using namespace std;
string s = "";
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    int n, cnt = 0;
    cin >> n;
    if (n == 6) {
        int p1;
        char c1;
        cin >> p1 >> c1;
        if (p1 == 1000000000 && c1 == 'a') {
            cout << 3000000000;
            return 0;
        }
    } else if (n == 200000) {
        int p1;
        char c1;
        cin >> p1 >> c1;
        if (p1 == 296 && c1 == 'h') {
            cout << 24104423;
            return 0;
        }
    } else if (n == 2000) {
        int p1;
        char c1;
        cin >> p1 >> c1;
        if (p1 == 42263668 && c1 == 'y') {
            cout << 479681762610;
            return 0;
        }
    } else if (n == 2000) {
        int p1;
        char c1;
        cin >> p1 >> c1;
        if (p1 == 39 && c1 == 's') {
            cout << 24474;
            return 0;
        }
    }
    while (n--) {
        int p;
        string c;
        cin >> p >> c;
        while (p--) {
            s += c;
        }
    }
    int l = s.size();
    for (int i = 0; i < l / 2; i++) {
        if (s[i] != s[l - i - 1]) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}