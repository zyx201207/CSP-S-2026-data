#include <bits/stdc++.h>
using namespace std;
string c1, s1, c2, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2){
        cout << 1;
        int num1 = (s1[0] - '0') * 10 + s1[1] - '0';
        int num2 = (s2[0] - '0') * 10 + s2[1] - '0';
        if (num1 == num2){
            cout << 1;
            if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'A' && s2[2] == 'C') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'A') || (s1[2] == 'C' && s2[2] == 'B')){
                cout << 1;
                if ((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D') || (s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A') || (s1[2] == 'B' && s2[2] == 'C') || (s1[2] == 'C' && s2[2] == 'B')) cout << 1 << endl;
                else cout << 0 << endl;
            }
            else cout << "00" << endl;
        }
        else cout << "000" << endl;
    }
    else cout << "0000" << endl;
    return 0;
}
