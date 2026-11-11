#include <bits/stdc++.h>
using namespace std;
int num[5];
string a, b, c, d;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> a >> b >> c >> d;
    if (a == c) {
        num[1] = 1;
    }
    if (num[1] == 1 && b[0] == d[0] && b[1] == d[1]) {
        num[2] = 1;
    }
    if (num[2] == 1 && (b[2] <= 'C' && d[2] <= 'C') || (b[2] > 'C' && d[2] > 'C')) {
        num[3] = 1;
    }
    if (num[3] == 1 && (b[2] == d[2] - 1 || b[2] == d[2] - 1 || (b[2] == 'D' && d[2] == 'F') )|| (b[2] == 'F' && d[2] == 'D')) {
        num[4] = 1;
    }
    for (int i = 1; i <= 4; i++) {
        printf("%d", num[i]);
    }
    return 0;
}
