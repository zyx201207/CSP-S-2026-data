#include <bits/stdc++.h>

using namespace std;

int main()
{
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    int c[2];
    char s[2][3];
    for (int i = 0; i < 2; i++){
        cin >> c[i];
        for (int j = 0; j < 3; j++){
            cin >> s[i][j];
        }
    }
    if (c[0] != c[1]){
        cout << "0000";
        return 0;
    }
    cout << 1;
    if ((s[0][0] - 48) * 10 + (s[0][1]) != (s[1][0] - 48) * 10 + (s[1][1])){
        cout << "000";
        return 0;
    }
    cout << 1;
    if ((s[0][2] >= 'D' && s[1][2] <= 'C') || (s[0][2] <= 'C' && s[1][2] >= 'D')){
        cout << "00";
        return 0;
    }
    cout << 1;
    if ((s[0][2] == 'A' && s[1][2] == 'B') || (s[0][2] == 'B' && s[1][2] == 'A') || (s[0][2] == 'F' && s[1][2] == 'D') || (s[0][2] == 'D' && s[1][2] == 'F')){
        cout << 1;
        return 0;
    }
    if (s[0][2] + 1 == s[1][2] || s[0][2] - 1 == s[1][2]){
        cout << 1;
        return 0;
    };
    cout << 0;
    return 0;
}
