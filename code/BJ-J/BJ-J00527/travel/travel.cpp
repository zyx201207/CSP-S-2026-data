#include <bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> c1 >> s1 >> c2 >> s2;
    bool f1 = (c1 == c2);
    string x1 = s1.substr(0, 2);
    string x2 = s2.substr(0, 2);
    bool f2 = (f1 && (x1 == x2));
    char z1 = s1[2], z2 = s2[2];
    bool f3 = 0;
    if (f1 && f2){
        if (z1 <= 'C' && z2 >= 'D') f3 = 0;
        else if (z1 >= 'D' && z2 <= 'C') f3 = 0;
        else f3 = 1;
    }
    bool f4 = 0;
    if (f1 && f2 && f3){
        if (z1 > z2){
            if (z1 == 'B' && z2 == 'A') f4 = 1;
            else if (z1 == 'C' && z2 == 'B') f4 = 1;
            else if (z1 == 'F' && z2 == 'D') f4 = 1;
            else f4 = 0;
        }else{
            if (z2 == 'B' && z1 == 'A') f4 = 1;
            else if (z2 == 'C' && z1 == 'B') f4 = 1;
            else if (z2 == 'F' && z1 == 'D') f4 = 1;
            else f4 = 0;
        }
    }
    cout << f1 << f2 << f3 << f4 << '\n';
    return 0;
}