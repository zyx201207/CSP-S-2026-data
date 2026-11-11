#include <iostream>
#include <cmath>
using namespace std;

bool f[10];

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);

    string c1, s1, c2, s2;
    cin>>c1>>s1>>c2>>s2;
    if (c1[0] == c2[0] && c1[1] == c2[1]) {
        f[0] = true;
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            f[1] = true;
            if (!(s1[2] <= 'C' && s2[2] >= 'D') && !(s1[2] >= 'D'&& s2[2] <= 'C')) {
                f[2] = true;
                if (abs(int(s1[2] - s2[2])) == 1) f[3] = true;
            }
        }
    }
    for (int i=0; i<4; i++) cout<<f[i];
    cout<<endl;
    return 0;
}
//  BJ-J00178/travel/travel.cpp
