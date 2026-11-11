#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    string s1, c1, s2, c2;
    cin >> s1 >> c1 >> s2 >> c2;
    if(s1 != s2){
        cout << "0000" << endl;
        return 0;
    }
    if(c1[0] != c2[0] || c1[1] != c2[1]){
        cout << "1000" << endl;
        return 0;
    }
    if(c1[2] >= 'A' && c1[2] <= 'C' && c2[2] >= 'D' && c2[2] <= 'E' || c2[2] >= 'A' && c2[2] <= 'C' && c1[2] >= 'D' && c1[2] <= 'E'){
        cout << "1100" << endl;
        return 0;
    }
    if(c1[2] + 1 != c2[2] && c2[2] + 1 != c1[2]){
        cout << "1110" << endl;
        return 0;
    }
    cout << "1111" << endl;
}

