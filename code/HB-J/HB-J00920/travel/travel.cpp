#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2;
    string s1,s2;
    cin >> c1 >> s1 >> c2 >> s2;
    if (c1 == c2) cout << 1;
    else{
        cout << "0000";
        return 0;
    }
    string s3 = s1.substr(0,2),s4 = s2.substr(0,2);
    if (s3 == s4) cout << 1;
    else{
        cout << "000";
        return 0;
    }
    int p = s1[2],h = s2[2];
    if ((p <= 'C' && h <= 'C') || (p >= 'D' && h >= 'D')) cout << 1;
    else{
        cout << "00";
        return 0;
    }
    if (abs(p-h) == 1) cout << 1;
    else cout << 0;
    return 0;
}
