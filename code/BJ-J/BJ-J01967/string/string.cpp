#include <bits/stdc++.h>
using namespace std;
int a, c, s;
string b;
int main() {
    freopen("string.in", "r", stdin);
    freopen("string.out", "w", stdout);
    cin >> a;
    for (int i = 0; i < a; i++) {
        long long x;
        string y;
        cin >> x >> y;
        c += x;
        for (int j = 0; j < x; j++) {
            b += y;
        }
    }
    for (int i = 0; i < c / 2; i++) {
        if (b[i] != b[c - i - 1]) {
            s++;
        }
    }
    cout << s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}