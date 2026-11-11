#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen(std.in, 'r', travel.in);
    freopen(std.out, 'w', travel.out);
    string s1, s2, c1, c2;
    cin >> s1 >> s2 >> c1 >> c2;
    if(!(s1 == c1 && s1 != 01 && s1 != 16 && c1 != 01 && c1 != 16)){
        cout << '0';
    }
    else cout << '1';
    if(s2 != c2 && s2 - 4 == c2 || c2 - 4 == s2 || s2 - 3 == c2 || c2 - 3 == s2 || s2 - 2 == c2 || c2 - 2 == s2 || s2 - 1 == c2 || c2 - 1 == s2){
        cout << '1';
    }
    else cout << 0;
    if(s2 != c2 && s2 - 2 == c2 || c2 - 2 == s2 || s2 - 1 == c2 || c2 - 1 == s2 && c2 - 1 != C || s2 - 2 != C){
        cout << '1';
    }
    else cout << 0;
    if(s2 != c2 && s2 - 1 == c2 || c2 - 1 == s2){
        cout << '1';
    }
    else cout << 0;
    return 0;
}

