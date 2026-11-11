

#include <iostream>
#include <cmath>
 
using namespace std;

string c1, s1, c2, s2;

int main () {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) {
        cout << 1;
    }else{
        cout << "0000";
        return 0;
    }

    string s3 = ""+ s1[0] + s1[1], s4 = "" + s2[0] + s2[1];
    if (s3 == s4) {
        cout << 1;
    }else{
        cout << "000";
        return 0;
    }

    char s5 = s1[2], s6 = s2[2];
    if (s5 == 'D') {
        s5 = 'E';
    }
    if (s6 == 'D') {
        s6 = 'E';
    }

    bool ok = true;
    if ((s5 == 'E' && s6 != 'F') || (s6 == 'E' && s5 != 'F') || (s5 == 'F' && s6 != 'E') || (s6 == 'F' && s5 != 'E')) {
        cout << "00";
        return 0;
    }else{
        cout << 1;
    }
    if (abs(int(s5) - int(s6)) == 1) {
        cout << 1;
    }else{
        cout << 0;
    }
    return 0;
}