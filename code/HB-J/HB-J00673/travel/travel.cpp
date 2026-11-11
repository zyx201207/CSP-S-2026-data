#include <bits/stdc++.h>
using namespace std;

int main(){

    // freopen("travel.in", "r",stdin);
    // freopen("travel.out", "w",stdout);

    string s[2][2];
    cin >> s[0][0] >> s[0][1] >> s[1][0] >> s[1][1];
    if(s[0][0] != s[1][0]){
        cout << "0000" << endl;
        return 0;
    }

    if(s[0][1][0] != s[1][1][0] || s[0][1][1] != s[1][1][1]){
        cout << "1000" << endl;
        return 0;
    }
    if(s[0][1][2] == 'A' || s[0][1][2] == 'B' || s[0][1][2] == 'C'){
        if(s[1][1][2] != 'A' && s[1][1][2] != 'B' && s[1][1][2] != 'C'){
            cout << "1100" << endl;
            return 0;
        }
            
    }else{
        if(s[1][1][2] != 'D' && s[1][1][2] != 'E'){
            cout << "1100" << endl;
            return 0;
        }
    }
    if(s[0][1][2] - s[1][1][2] == 1 || s[0][1][2] - s[1][1][2] == -1){
        cout << "1111" << endl;
        return 0;
    }

    cout << "1110" << endl;
    return 0;
}