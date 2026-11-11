//Eason Cyj001001 AH-J00766
#include "bits/stdc++.h"
#define int long long

using namespace std;
int c1,c2;
string s1,s2;
signed main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 != c2) {
        cout << "0000";
        return 0;
    }
    cout << 1;
    if(!(s1[0] == s2[0]&&s1[1] == s2[1])) {
        cout << "000";
    }else{
        cout << 1;
        if(('A'<=s1[2] && s1[2]<='C') && ('A'<=s2[2] && s2[2]<='C') || ('D'<=s1[2] && s1[2]<='E') && ('D'<=s2[2] && s2[2]<='E')) {
            cout << 1;
            if(s1[2]-s2[2] == 1 || s1[2]-s2[2]==-1) {
                cout << 1;
            }else cout << "0";
        }else{
            cout << "00";
        }
    }

    return 0;
}
