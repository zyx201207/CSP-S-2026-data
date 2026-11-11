#include<bits/stdc++.h>
using namespace std;
string s;
int c1, c2, r1, r2;
int ss1, ss2;

int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    getline(cin, s);
    if(s[0] == '0') c1 = s[1] - '0';
    else c1 = 10 + (s[1] - '0');
    if(s[7] == '0') c2 = s[8] - '0';
    else c2 = 10 + (s[8] - '0');
    if(s[3] == '0') r1 = s[4] - '0';
    else r1 = 10 + (s[4] - '0');
    if(s[10] == '0') r2 = s[11] - '0';
    else r2 = 10 + (s[11] - '0');
    ss1 = s[5] - 'A' + 1;
    ss2 = s[12] - 'A' + 1;
    if(c1 != c2){
        cout << "0000\n";
        return 0;
    }
    if(r1 != r2){
        cout << "1000\n";
        return 0;
    }
    if((ss1 >= 4 && ss2 <= 3) || (ss1 <= 3 && ss2 >= 4)){
        cout << "1100\n";
        return 0;
    }
    if(ss1 > 3 && ss2 > 3){
        cout << "1111\n";
        return 0;
    }
    if(abs(ss1 - ss2) != 1)
        cout << "1110\n";
    else
        cout << "1111\n";
    return 0;
}
