#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    string c1,s1,c2,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    int a[4] = {0};

    if (c1 == c2) {
        a[0] = 1;
        if (s1[0] == s2[0] && s1[1] == s2[1]) {
            a[1] = 1;
            if ((s1[2] >= 'A' && s1[2] <= 'C' && s2[2] >= 'A' && s2[2] <= 'C') || ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))) {
                a[2] = 1;
                if ((abs(s2[2] - s1[2]) == 1) || (s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')) {
                    a[3] = 1;
                }else{
                    a[3] = 0;
                }
            }else{
                a[2] = 0;
                a[3] = 0;
            }
        }else{
            a[1] = 0;
            a[2] = 0;
            a[3] = 0;
        }
    }else{
        for (int i = 0; i < 4; i++) {
            a[i] = 0;
        }
    } 
    for (int i = 0; i < 4; i++) {
        cout << a[i];
    }
    return 0;
}