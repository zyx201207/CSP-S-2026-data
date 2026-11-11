#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;
bool flag1, flag2, flag3,flag4;


int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    flag1 = (c1 == c2);
    flag2 = (s1[0] == s2[0] && s1[1] == s2[1]);
    flag3 = (((int)(s1[2] - 'A' + 1) > 3 && (int)(s2[2] - 'A' + 1) > 3) || ((int)(s1[2] - 'A' + 1) <= 3 && (int)(s2[2] - 'A' +1) <= 3));
    flag4 = (abs((int)(s1[2] - 'A'+1) - (int)(s2[2] - 'A'+1)) == 1.0);
    if (flag1){
        printf("1");
    }
    else {
        printf("0");
    }

    if (flag1 && flag2){
        printf("1");
    }
    else {
        printf("0");
    }

    if (flag1 && flag2 && flag3){
        printf("1");
    }
    else {
        printf("0");
    }
    if (flag1 && flag2 && flag3 && flag4){
        printf("1");
    }
    else {
        printf("0");
    }
    return 0;
}
