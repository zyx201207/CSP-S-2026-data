#include <bits/stdc++.h>
typedef long long ll ;
using namespace std;
string c1, c2, s1, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        cout << 1;
        if(s1[0] == s2[0] && s1[1] == s2[1]){
            cout << 1;
            if( (s1[2] - 'A' < 3 && s2[2] - 'A' < 3) || (s1[2] - 'A' >= 3 && s2[2] - 'A' >= 3) ){
                cout << 1;
                if( abs(s1[2] - s2[2]) == 1 || (max(s1[2], s2[2]) == 'F' && min(s1[2], s2[2]) == 'D') )
                    cout << 1 << '\n';
                else cout << 0 << '\n';
            }
            else cout << "00" << '\n';
        }
        else cout << "000" << '\n';
    }
    else cout << "0000" << '\n';
    return 0;
}
