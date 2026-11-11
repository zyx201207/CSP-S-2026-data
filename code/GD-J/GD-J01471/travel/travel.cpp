#include <bits/stdc++.h>
using namespace std;

string a1 = "",a2 = "",b1 = "",b2 = "";
bool c1 = 0,c2 = 0,c3 = 0,c4 = 0;

int main () {
    freopen("travel.in", "r" ,stdin);
    freopen("travel.out", "w" ,stdout);
    cin >> a1 >> b1 >> a2 >> b2;
    if (a1 == a2) {
        c1 = 1;
        char s3 = b1[2],s4 = b2[2];
        if (b1[0] == b2[0] && b1[1] == b2[1]){
            c2 = 1;
            if ((s3 == 'A' && s4 == 'B') || (s3 == 'A' && s4 == 'C') || (s3 == 'B' && s4 == 'C') || (s3 == 'D' && s4 == 'F')){
                c3 = 1;
            }
            if ((s3 == 'A' && s4 == 'B') || (s3 == 'B' && s4 == 'c') || (s3 == 'C' && s4 == 'D') || (s3 == 'D' && s4 == 'F') || (s3 >= 'F' && s3 <= 'D') && (s4 >= 'F' && s4 <= 'D')){
                c4 = 1;
            }
        }
        cout << c1 << c2 << c3 << c4;
    }
    else {
        cout << c1 << c2 << c3 << c4;
    }
    return 0;
}
