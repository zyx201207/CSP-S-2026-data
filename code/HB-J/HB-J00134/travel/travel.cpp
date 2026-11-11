// travel
#include <iostream>
using namespace std;

string c1, s1, c2, s2;

bool id(char c) { return c == 'D' || c == 'F'; }

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
        string r1, r2;
        r1 = s1[0] + s1[1];
        r2 = s2[0] + s2[1];
        if (r1 == r2) {
            cout << 1;
            if (id(s1[2]) == id(s2[2])) {
                cout << 1 << (bool)(id(s1[2]) || s1[2] == 'B' || s2[2] == 'B') << '\n';
            } else {
                puts("00");
            }
        } else {
            puts("000");
        }
    } else {
        puts("0000");
    }
    return 0;
}
