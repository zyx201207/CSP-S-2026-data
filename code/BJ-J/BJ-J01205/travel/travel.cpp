#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,c2,c3,c4;
    cin >> c1 >> c2 >> c3 >>c4;
    cout << (c1==c3);
    if (c1 != c3){cout << "000";return 0;}
    cout << ((c2[0] == c4[0]) && (c2[1] == c4[1]));
    if (((c2[0] == c4[0]) && (c2[1] == c4[1]))){
        if (c2[2] >= 'A' && c2[2] <= 'C' && c4[2] >= 'A' && c4[2] <= 'C' ){
            cout << 1;
            if (abs((int)c2[2]-c4[2]) == 1) cout << 1;
            else cout << 0;
        }
        else if (c2[2] >= 'D' && c2[2] <= 'E' && c4[2] >= 'D' && c4[2] <= 'E' ){
            cout << 1;
            if (abs((int)c2[2]-c4[2]) == 1) cout << 1;
            else cout << 0;
        }
        else cout << "00";
    }
    else cout << "00";
    return 0;
}
