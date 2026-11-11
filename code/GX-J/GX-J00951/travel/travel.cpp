#include <bits/stdc++.h>
using namespace std;
string s;
string c1, s1, c2, s2;
int main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2){
        s += '1';
    }
    else{
        s += "0000";
        cout << s;
        return 0;
    }
    for(int i = 0; i < 2; i++){
        if(s1[i] != s2[i]){
            s += "000";
            return 0;
        }
    }
    s += '1';
    if((s1[2] == 'A' || s1[2] == 'B' || s1[2] == 'C') && (s2[2] == 'A' || s2[2] == 'B' || s2[2] == 'C')){
        s += '1';
    }
    else if((s1[2] == 'D' || s1[2] == 'F') && (s2[2] == 'D' || s2[2] == 'F')){
        s += '1';
    }
    else{
        s += "00";
        cout << s;
        return 0;
    }
    if((s1[2] == 'A' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'A')){
        s += '1';
    }
    else if((s1[2] == 'C' && s2[2] == 'B') || (s1[2] == 'B' && s2[2] == 'C')){
        s += '1';
    }
    else if((s1[2] == 'D' && s2[2] == 'F') || (s1[2] == 'F' && s2[2] == 'D')){
        s += '1';
    }
    else {
        s += '0';
    }
    cout << s;
    return 0;
}
