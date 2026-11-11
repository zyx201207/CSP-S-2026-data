#include<bits/stdc++.h>
using namespace std;
int x, y, a, b, m, n;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> x;
    char c1, c2, c3;
    cin >> c1 >> c2 >> c3;
    a = (c1 - '0') * 10 + c2 - '0';
    m = c3 - 'A' + 1;
    cin >> y;
    cin >> c1 >> c2 >> c3;
    b = (c1 - '0') * 10 + c2 - '0';
    n = c3 - 'A' + 1;
    if(x != y) { cout << "0000"; return 0; }
    cout << 1;
    if(a != b) { cout << "000"; return 0; }
    cout << 1;
    if((m <= 3) ^ (n <= 3)) { cout << "00"; return 0; }
    cout << 1;
    if(n - m == 1 || m - n == 1) cout << 1;
    else cout << 0;
}
