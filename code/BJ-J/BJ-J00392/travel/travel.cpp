#include <bits/stdc++.h>
using namespace std;

int main() {

    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    int c1, c2;
    string s1, s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        cout << "1";
    }
    else {
        cout << "0000";
        return 0;
    }

    int r1 = 0, r2 = 0;
    for(int i = 0; i < s1.size() - 1; i++) {
        r1 = r1 * 10 + s1[i] - '0';
        r2 = r2 * 10 + s2[i] - '0';
    }
    if(r1 == r2) {
        cout << "1";
    }
    else {
        cout << "000";
        return 0;
    }
    char h1 = s1[s1.size() - 1], h2 = s2[s2.size() - 1];
    //printf("Debug: h1:%c h2:%c\n", h1, h2);
    if(h1 >= 'A' && h1 <= 'C' && h2 >= 'A' && h2 <= 'C') {
        cout << "1";
        //cout << "A";
    }
    else if(h1 >= 'D' && h1 <= 'F' && h2 >= 'D' && h2 <= 'F') {
        cout << "1";
        //cout << "B";
    }
    else {
        cout << "00";
        return 0;
    }

    if(max(h1, h2) - min(h1, h2) == 1) {
        cout << "1";
    }
    else {
        cout << 0;
    }


    return 0;
}
