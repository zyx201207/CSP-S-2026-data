#include<bits/stdc++.h>
using namespace std;

string c1, s1, c2, s2;

bool check(char c){
    if(c == 'A' || c == 'B' || c == 'C') return 1;
    else return 0;
}

int val(char c){
    if(c == 'A') return 1;
    if(c == 'B') return 2;
    if(c == 'C') return 3;
    if(c == 'D') return 5;
    if(c == 'F') return 6;
}

signed main(){
    freopen("travel.in", "r", stdin);
    freopen("travel.out", "w", stdout);
    cin >> c1 >> s1 >> c2 >> s2;
    if(c1 == c2) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1]) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && (check(s1[2]) == check(s2[2]))) cout << 1;
    else cout << 0;
    if(c1 == c2 && s1[0] == s2[0] && s1[1] == s2[1] && (check(s1[2]) == check(s2[2])) && (abs(val(s1[2]) - val(s2[2])) == 1)) cout << 1;
    else cout << 0;
    return 0;
}
