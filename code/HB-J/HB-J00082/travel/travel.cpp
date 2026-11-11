# include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string a, b, c, d;
    cin >> a >> b >> c >> d;
    if (a != c) {
        puts("0000");
        return 0;
    }
    if (b[0] == d[0] && b[1] == d[1]) {
    } else {
        puts("1000");
        return 0;
    }
    if ((b[2] <= 'C' && d[2] <= 'C') || (b[2] >= 'D' && d[2] >= 'D')) {
    } else {
        puts("1100");
        return 0;
    }
    if ((b[2] == d[2] + 1) || (b[2] == d[2] - 1) || (b[2] == 'D' && d[2] == 'F') || (b[2] == 'F' && d[2] == 'D')) {
        puts("1111");
    } else {
        puts("1110");
    }
    return 0;
}
