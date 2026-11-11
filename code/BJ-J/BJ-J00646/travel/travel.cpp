#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int a;
    string x;
    cin >> a >> x;
    int b;
    string y;
    cin >> b >> y;
    int a_pai = 0, b_pai = 0;
    int n = x.size() - 1;
    int m = y.size() - 1;
    for (int i = 0; i <= n; i++) {
        if (x[i] >= '0' && x[i] <= '9') a_pai = a_pai *10 + (int)(x[i] - 48);
        if (y[i] >= '0' && y[i] <= '9') b_pai = b_pai *10 + (int)(y[i] - 48);
    }
    if (a == b) cout << 1;
    else cout << 0;
    if (a_pai == b_pai && a == b) cout << 1 ;
    else cout << 0;
    if (a_pai == b_pai && a == b && x[n] >= 'A' && x[n] <= 'C' && y[n] >= 'A' && y[n] <= 'C') cout << 1;
    else cout << 0;
    if (a_pai == b_pai && a == b && (x[n] + 1 == y[n] || y[n] + 1 == x[n]) && ((x[n] >= 'A' && x[n] <= 'C' && y[n] >= 'A' && y[n] <= 'C') || (x[n] >= 'D' && x[n] <= 'F' && y[n] >= 'D' && y[n] <= 'F'))) cout << 1;
    else cout << 0;
    return 0;
}

