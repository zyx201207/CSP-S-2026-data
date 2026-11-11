#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string s1,s2,s3,s4;
int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> s1 >> s2 >> s3 >> s4;
    string s5 = s2.substr(0,2);
    string s6 = s4.substr(0,2);
    int a,b;
    switch(s2[2]) {
        case 'A': a = 0; break;
        case 'B': a = 1; break;
        case 'C': a = 2; break;
        case 'D': a = 3; break;
        case 'F': a = 4; break;
    }
    switch(s4[2]) {
        case 'A': b = 0; break;
        case 'B': b = 1; break;
        case 'C': b = 2; break;
        case 'D': b = 3; break;
        case 'F': b = 4; break;
    }
    bool aa = a < 3;
    bool bb = b < 3;
    if(s1 == s3) {
        cout << 1;
        if(s5 == s6) {
            cout << 1;
            if(aa == bb) {
                cout << 1;
                if(!aa) {
                    cout << 1;
                } else if(abs((int)s2[2]-(int)s4[2]) <= 1) {
                    cout << 1;
                } else cout << 0;
            } else cout << "00";
        } else {
            cout << "000";
        }
    } else cout << "0000";
    //cin.ignore().get();
    return 0;
}
