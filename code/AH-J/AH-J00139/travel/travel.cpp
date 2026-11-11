#include<bits/stdc++.h>
using namespace std;

string c1, c2, s1, s2;
int a[4];

int main() {
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    memset(a, 0, sizeof(a));
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) {
        a[0] = 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]) {
            a[1] = 1;
            if((s1[2] - 'A' < 3 && s2[2] - 'A' < 3) || (s1[2] - 'A' > 2 && s2[2] - 'A' > 2)) {
                a[2] = 1;    
            }
            if(s1[2] == 'D' || s2[2] == 'D') {
                if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D'))
                    a[3] = 1;
            }else {
                if(abs(s1[2] - s2[2]) == 1)
                    a[3] = 1;
            }
        }
    }
    for(int i = 0; i < 4; i++) {
        printf("%d", a[i]);
    }
    return 0;
}