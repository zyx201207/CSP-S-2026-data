#include <bits/stdc++.h>
using namespace std;

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin >> c1 >> s1 >> c2 >> s2;

    int x1, x2;
    int y1, y2;

    x1 = (s1[0] - '0') * 10 + s1[1] - '0';
    x2 = (s2[0] - '0') * 10 + s2[1] - '0';
    y1 = s1[2] - 'A';
    y2 = s2[2] - 'A';
    if(s1[2] == 'F') y1 = 4;
    if(s2[2] == 'F') y2 = 4;

    if(c1 == c2) {
        cout << 1;
        if(x1 == x2) {
            cout << 1;
            if((y1 <= 2 && y2 <= 2) || (y1 >= 3 && y2 >= 3)) {
                cout << 1;
                if(abs(y1 - y2) == 1) cout << 1;
                else cout << 0;
            }
            else cout << "00";
        }
        else cout << "000";
    }
    else cout << "0000";
    fclose(stdin);
    fclose(stdout);
    return 0;
}
